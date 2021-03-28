#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb  19 16:28:28 2021


"""
from __future__ import print_function
import matplotlib.pyplot as plt
plt.ion() #interactive plotting
import math 
# For integration.
import scipy.integrate 
# For arrays (Python does not have native arrays).
import numpy as np
import csv
import os

# Allows for an interactive widget bar.
from ipywidgets import interactive 


#Parameters
############


#TAKEN FROM PN MODEL -PPLESE CHECK!!!
#####################
Cm       = 0.025    # membrane capacitance  (nano-farad)

gDR_bar  = 0.9      # maximal conductance of Kdr (delayed rectifier) (micro-siemen)
gL       = 0.05     # maximal conductance of leak channel (micro-siemen)

ENa      = 55       # reversal potential of Na+ (milli-volt)
EK       = -94      # reversal potential of K+ (milli-volt)
ESynE    = -10      # reversal potential of (excitatory Synapse) (milli-volt)
EL       = -43      # reversal potential of leak channel (milli-volt - (-41.31 for 1Hz  -52.57 for 2Hz  -52.56 for 3Hz))   */ 

tauE     = 30       # Time constatnt for excitatory synapse (milli-second)
tauI     = 30       # Time constatnt for inhibitory synapse (milli-second)

####################

# Scn1a_cp35 constants
gNa_bar = 0.00001 #(S/cm2) 

# Kcna1ab1_md80769 constants
q10 = 3

ca = 0.12889 #(1/ms)
cva = 45 #(mV)
cka = -33.90877 #(mV)

cb = 0.12889 #(1/ms)
cvb = 45 #(mV)
ckb = 12.42101 #(mV) 

celsius =27.0

def alphanfkt(v):
    return ca * math.exp(-(v+cva)/cka)

def betanfkt(v):
    return cb * math.exp(-(v+cvb)/ckb)

qt = q10^(int(celsius-22 /10) ) # In C: qt = q10^((celsius-22 (degC))/10 (degC))
    

      
# Steady State with IR and EL=-43 and gL=0.05. */
###############################################

y0=np.zeros(5)
y0[0]  = -6.165671106176441e+01 # Membrane volatge Vm
y0[1]  = 1.277236125734123e-02  # activation variable of Na+
y0[2]  = 3.429830012296679e-01  # inactivation variable of Na+
y0[3]  = 2.642252518522899e-02  # activation variable of Kdr
y0[4] = 0.0                     # pre synaptic excitation


#Inputs
#######

InE  = 0.012      # Excitatory Synapse conductnace

#################################
#Delete the mh-parameter file
os.remove("mh-parameters.txt")
#################################

def RAGP_model(y,t):
    
    #variables
    ##########

    V     = y[0] # Membrane volatge from interg over Vm
    mNa   = y[1] # activation variable of Na+
    hNa   = y[2] # inactivation variable of Na+
    mDR   = y[3] # activation variable of Kdr

    gSynE = y[4] # pre synaptic excitation


    #Current from channels
    ######################

    INa   = -gNa_bar*mNa**3*hNa*(ENa-V) #Fast sodium
    IDR   = -gDR_bar*mDR**4*(EK-V)      #Potassium delayed rectifier

    ISynE = gSynE*(ESynE-V) # Excitatory Synapse
    IL    = gL*(EL-V)       # Leak channel current


    #Steady state values
    ####################

    # Fast Sodium, Scn1a_cp35 */
    v =V
    mAlpha = (0.182 * (v- -35))/(1-(np.exp(-(v- -35)/9)))
    mBeta = (0.124 * (-v -35))/(1-(np.exp(-(-v -35)/9)))
    mInf = mAlpha/(mAlpha + mBeta)
    mTau = 1/(mAlpha + mBeta) 
    hInf = 1.0/(1+np.exp((v- -65)/6.2))
    hTau = 1/((0.024 * (v- -50))/(1-(np.exp(-(v- -50)/5))) +(0.0091 * (-v - 75.000123))/(1-(np.exp(-(-v - 75.000123)/5))))

    gNa = gNa_bar*mNa**3*hNa
    #ina = gNa*(v-ENa)

    mNa_dot = (mInf-mNa)/mTau
    hNa_dot = (hInf-hNa)/hTau 
    

    # Potassium-delayed rectifier, Kcna1ab1 */

    alphan = alphanfkt(v)
    betan = betanfkt(v)
    ninf = alphan/(alphan+betan) 
    taun = 1/(qt*(alphan + betan))       

    gDR  = gDR_bar*mDR**4 
    
    mDR_dot = (ninf-mDR)/taun 
    

    # Synaptic conductances */
    gSynE_dot = (InE-gSynE)/tauE 

    # Membrane potential */

    V_dot = gNa*(ENa-V) + (gDR)*(EK-V) + gL*(EL-V) + gSynE*(ESynE-V) 
    V_dot = V_dot/Cm 

    #################################    
    #Save the activation, inactivation parameters
    f=open("mh-parameters.txt", "a+")
    f.write("%f %f %f %f %f %f %f\n" % (t, mInf, mTau, hInf, hTau, ninf, taun ))
    f.close () 
    #################################
        
    #Differential equations
    #######################
    
    dy = np.zeros(5)


    dy[0] = (1e3*V_dot)
    dy[1] = (1e3*mNa_dot)
    dy[2] = (1e3*hNa_dot)
    dy[3] = (1e3*mDR_dot)

    dy[4] = (1e3*gSynE_dot)

    return dy


#ODE CALCULAITON AND PLOTTING
###############################
# initial time
ti = 0
# time step (0.0005 s)
dt = 0.5*10**(-3)
# final time 
tf = 1 # 800 for step response
    
tspan = np.arange(ti,tf,dt)
 
y1 = abs(y0)
Vy = scipy.integrate.odeint(RAGP_model, y0, tspan)
    
V     = Vy[:,0] 
mNa   = Vy[:,1]
hNa   = Vy[:,2]
mDR   = Vy[:,3]
gSynE = Vy[:,4]
  
#Plotting
##########
fig = plt.figure
#plt.plot(V,ninf)
#plt.plot(V, hInf)
#plt.xlabel('mV')
#plt.show()
#plt.savefig('Membrane_Voltage.png',dpi=300) 
#plt.close()  

data = np.loadtxt('mh-parameters.txt')
a = 1  # number of rows
b = 6  # number of columns
count = 1  # initialize plot counter
fig = plt.figure(figsize=(40,4))
#print (len(data))

count=1
myyaxis = ['Na-mi', 'Na-tm', 'Na-hi', 'Na-th', 'DR-mi', 'DR-tm' ]
for i in range(1,6):
    plt.rcParams.update({'font.size': 16}) 
    plt.subplot(a,b,count)
    plt.plot(data[:,0], data[:,i])
    plt.xlabel('Time (ms)')
    plt.ylabel(myyaxis[i])
    count+=1
plt.show()
fig.savefig('mh-parameters.png')
#plt.close()
