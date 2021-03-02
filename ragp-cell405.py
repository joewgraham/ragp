from neuron import h
from neuron.units import ms, mV

#import neuron.gui
import matplotlib.pyplot as plt
import numpy as np
import matplotlib

import csv
#dlopen("/Users/lakshmikc/Dropbox (SBG)/SPARC-2020/EP-Modeling/RAGP-Models/RAGP-PyN/Cell-405/x86_64/.libs/libnrnmech.so")


h.load_file('stdrun.hoc')
#h.v_init = -65*mV			#need to revisit - is it -44.5 mV?i#
h.v_init = -44.5*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = h.v_init

#Channel conductances
#=====================
#Sodium channel
soma.insert('ch_Scn1a_cp35') #add channel suffix here
soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001

#Potassium channel
soma.insert('ch_Kcna1_md232813') #add channel suffix here
soma(0.5).ch_Kcna1_md232813.gkcnabar= 0.01592

soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.011

soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.015


#Calcium channels
soma.insert('ch_Cacna1i_cp42') #add channel suffix here
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.00001


soma.psection()

v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

iclamp = h.IClamp(soma(0.5))

iclamp.delay = 50 #ms

iclamp.dur = 200.0 #ms


#SAVE DATA FILE AND PLOT FOR EACH CONDUCTRANCE - 
###############################################

a = 1  # number of rows
b = 6  # number of columns
c = 1  # initialize plot counter
fig = plt.figure(figsize=(28,4))


#EDIT ONLY THIS PART
########################################
channel = "Hcn4"
mylist1 = [0.00001, 0.0001, 0.001, 0.01, 0.1, 1.0]  #Conductance values 

for soma(0.5).ch_Hcn4_cp12.gHCN4bar in mylist1:
    cond = soma(0.5).ch_Hcn4_cp12.gHCN4bar
#########################################   

    #plt.figure() 
    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 16}) 
    plt.title('Conductance= {}'.format(cond))
    mylist2 = [0.1,1,5]  #Current strength

    for iclamp.amp in mylist2: 
      
        ## RUN SIMULATION
        h.finitialize(h.v_init)
        # continue sim thru 40 ms
        h.continuerun(200 * ms)
            
        #f = "PULSE/%s-C-%s-I-%s.txt" % (channel,cond,iclamp.amp)
        #with open(f, "w") as f:
         #   csv.writer(f).writerows(zip(t, v))

        plt.plot(t, v)
       
    plt.ylim((-70,70))
       
    plt.xlabel("Time (ms)")
    plt.ylabel("Membrane Potential (mV)")    
    plt.grid(True) 
    c = c+1
 
plt.savefig('PLOTS/%s.png' % (channel))
plt.show()
plt.close()  

    
    



