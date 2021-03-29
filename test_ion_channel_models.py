# NOTE: This script is set up to test Nav1.1 models for neuron model cell_Mid, with result compiled as a 5x6 array of models 
# x conductances in Appendix 2 of Model Documention, where full citations for below Refs. can also be found.

# DESCRIPTION: This script generates a 1x6 figure corresponding to one ion channel (kinetic) model for Nav1.1, with subplots of 
# increasing conductances (S/cm2) and varying current input (nA) within each subplot. It contributes to our analysis and selection
# of the kinetic model for each ion channel, here Nav1.1, with in totem output a 6x5 array of m models x n conductances. 
# This allows for comparison of conductances and current input within each model and across ion channel models, from which 
# a viable/best ion channel model for Nav1.1 can be selected, along with the optimal conductance and amp values under which
# APs are generated and w/o spontaneous firing. 

# USAGE: To test viability of different ion channel models for a given gene where they exist. For example,
# Scna1 (Nav1.1) has 5 kinetic models across CP, ModelDB and literature. As written here, script is meant to test a 
# single ion channel model at a time for a given neuron model and should be run 5 times given 5 different Nav1.1 models 
# (Berecki, Zheng, Traub, Rybak, CP) as coded below.
# 1) Run script as is. Output: figure w/ 6 subplots as described above.
# 2) Refer to "EDIT THIS PART TO SELECT IC MODEL" to modify code: comment out model 1 (Berecki) and 
# uncomment the next model (Zheng). Note that 3 line edits need to be made under #EDIT THIS SEC. BASED ON IC MODEL SELECTED ABOVE.
# Re-run script.
# 3) Repeat (2) for each successive model. 

from neuron import h
from neuron.units import ms, mV

import matplotlib.pyplot as plt
import numpy as np

h.load_file('stdrun.hoc')
h.v_init = -61*mV		

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = -65
soma(0.5).pas.g = 1.8e-6

#Channel conductances 
#EDIT THIS PART TO SELECT IC MODEL
###############################################
### Berecki et al 2019 ###
soma.insert('ch_Scn1a_md264834') #add channel suffix here
soma(0.5).ch_Scn1a_md264834.gNav11bar = 0.00001 #(S/cm2)
channelName = "Berecki"
### Zheng et al 2019 ###
#soma.insert('ch_Scn1a_md256632') #add channel suffix here
#soma(0.5).ch_Scn1a_md256632.gnabar = 0.008 #(S/cm2)
#channelName = "Zheng"
### Traub et al 2003 ###
#soma.insert('ch_Naf_md20756') #add channel suffix here
#soma(0.5).ch_Naf_md20756.gbar = 0	   #(mho/cm2)
#channelName = "Traub"
### Rybak et al 1997 ###
#soma.insert('ch_Naf_rybak') #add channel suffix here
#soma(0.5).ch_Naf_rybak.gNabar= 0.106103295 #(S/cm2) <0,1e9> 
#channelName = "Rybak"
### Channelpedia ###
#soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001
#channelName = "cp"
###############################################

soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.015
soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #0.011

soma.insert('ch_Cacna1b_cp6') #add channel suffix here
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.00001
soma.insert('ch_Cacna1c_cp3') #add channel suffix here
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.00001 
soma.insert('ch_Cacna1i_cp42') #add channel suffix here
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.0001

#soma.insert('ch_Hcn2_cp10') #add channel suffix here
#soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.01
#soma.insert('ch_Hcn4_cp12') #add channel suffix here
#soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.001


v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

iclamp = h.IClamp(soma(0.5))
iclamp.delay = 50 #ms
iclamp.dur = 200.0 #ms
tstop = 500
iclamp.amp = 0 #nA


#SAVE DATA FILE, PLOT FOR EACH IC CONDUCTANCE MODEL
###############################################
a = 1  # number of rows
b = 6 # number of columns
c = 1  # initialize plot counter
fig = plt.figure(figsize=(28,4))

#EDIT THIS SEC. BASED ON IC MODEL SELECTED ABOVE
###############################################
modelType = 'cell_Mid'                              # <-- DO NOT CHANGE - DEMO MODE
channel = "Scn1a_md264834" + "_" + channelName      # <-- UPDATE THIS LINE 
mylist1 = [0.00001, 0.0001, 0.001, 0.01, 0.1, 1.0]  #Conductance values 

for soma(0.5).ch_Scn1a_md264834.gNav11bar in mylist1:  # <-- UPDATE THIS LINE 
    cond = soma(0.5).ch_Scn1a_md264834.gNav11bar   # <-- UPDATE THIS LINE 
###############################################   

    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 10}) 
    plt.title('Conductance= {}'.format(cond))
    mylist2 = [0.1, 0.5, 1.0] #IClamp.amp values (nA)
    colors = ['r','b', 'k']
    for iclamp.amp in mylist2: 
      
        ## RUN SIMULATION
        h.finitialize(h.v_init)
        h.continuerun(500 * ms) #redundancy

        for amp, color in zip(mylist2, colors):
            iclamp.amp = amp
            h.finitialize(h.v_init * mV)
            h.continuerun(500* ms)
            plt.plot(t,v, color=color)
            plt.ylim((-80,70))
            plt.xlabel('t (ms)')
            plt.ylabel('v (mV)')
            plt.legend(mylist2)  
    c = c+1

#SAVE PLOT FOR EACH IC CONDUCTANCE MODEL
################################################
try:
    plt.savefig('PULSE/%s.png' % (channel))
except:
    print('CREATE A SAVE DIR AND EDIT CODE')
    plt.show()
    plt.close()
plt.show()
plt.close()