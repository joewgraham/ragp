from neuron import h
from neuron.units import ms, mV

#import neuron.gui
import matplotlib.pyplot as plt
import numpy as np
import matplotlib

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
### Zheng et al 2019 ###
#soma.insert('ch_Scn1a_md256632') #add channel suffix here
#soma(0.5).ch_Scn1a_md256632.gnabar = 0.008 #(S/cm2)
### Traub et al 2003 ###
#soma.insert('ch_Naf_md20756') #add channel suffix here
#soma(0.5).ch_Naf_md20756.gbar = 0	   #(mho/cm2)
### Rybak et al 1997 ###
#soma.insert('ch_Naf_rybak') #add channel suffix here
#soma(0.5).ch_Naf_rybak.gNabar=0.106103295 #(S/cm2) <0,1e9> 
### Channelpedia ###
#soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001
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


#SAVE DATA FILE AND PLOT FOR EACH CONDUCTANCE - 
###############################################

a = 1  # number of rows
b = 6 # number of columns
c = 1  # initialize plot counter
fig = plt.figure(figsize=(28,4))

#EDIT THIS PART BASED ON IC MODEL SELECTED ABOVE
###############################################
channel = "Scn1a_md264834_Berecki"
mylist1 = [0.00001, 0.0001, 0.001, 0.01, 0.1, 1.0]  #Conductance values 

for soma(0.5).ch_Scn1a_md264834.gNav11bar in mylist1:
    cond = soma(0.5).ch_Scn1a_md264834.gNav11bar
###############################################   

    #plt.figure() 
    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 10}) 
    plt.title('Conductance= {}'.format(cond))
    #mylist2 = [0.1,1,5]  #Current strength - corresponds to colors b, o, g (add key?)
    mylist2 = [0.01, 0.05, 0.1]
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
        #plt.plot(t, v)
        #plt.ylim((-70,70))
        #plt.xlabel("time(ms)")
        #plt.ylabel("membrane potential(mV)")  
        #plt.legend(mylist2)
    #plt.ylim((-70,70))
    #plt.xlabel("time(ms)")
    #plt.ylabel("membrane potential(mV)")    
    #plt.grid(True) 
    c = c+1
  
#plt.savefig('PULSE_test2/%s.png' % (channel))
#plt.savefig('PULSE_test/%s.png' % (channel))
plt.savefig('PULSE/%s.png' % (channel))
plt.show()
#plt.close()  
