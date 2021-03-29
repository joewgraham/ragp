#middle_heatmap_genes.py

from neuron import h
from neuron.units import ms, mV
import matplotlib.pyplot as plt
import csv

h.load_file('stdrun.hoc')
h.v_init = -61*mV	
h.celsius = 33 		#Meeting with Dr. Paton on 22 March 2021		

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg, soma.Ra = 30, 30, 1, 1, 35.4 #123

soma.insert('pas')
soma(0.5).pas.e = -65
soma(0.5).pas.g = 1.8e-6


soma.insert('ch_Cacna1b_cp6') # N-type Ca channel
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.0001
soma.insert('ch_Cacna1c_cp3') # L-type Ca channel
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.0001
soma.insert('ch_Cacna1i_cp42') # T-type Ca channel
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.0001

soma.insert('ch_Scn1a_md264834') # Nav 1.1 from Berecki 2019
soma(0.5).ch_Scn1a_md264834.gNav11bar = 2.0 # 0.00001 #(S/cm2)

soma.insert('ch_Hcn2_cp10') #add channel suffix here
soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.010
soma.insert('ch_Hcn4_cp12') #add channel suffix here
soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.001

soma.insert('ch_Kcnc1_md74298') # KDR Kv3.1
soma.insert('ch_Kcna1ab1_md80769') #KDR Kv 1.1
soma(0.5).ek = -74*mV 					# -81.77879864959175 NetPyNE's ek
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #0.011


h.ion_style("k_ion", 0, 1, 0, 0, 0,sec=soma) 
################################# STIMULUS ###########################################
     
# Stimulus - iClamp
iclamp = h.IClamp(soma(0.5))
iclamp.delay = 200	#1*ms 				# 200 ms
iclamp.dur = 200	#0 					#200 #ms #0.5
iclamp.amp = 0.1	#0 					#0.05 #0.1 #1 #nA
tstop = 500 		#0.025*ms 			#500; 5000 for ss exercise; 

# Stimulus - AlphaSynapse - not for networks
# asyn = h.AlphaSynapse(soma(0.5))
# asyn.onset = 100*ms
# asyn.tau = 10*ms
# asyn.gmax = 0.002 # (umho)
# tstop = 500*ms 

# Stimulus - Exp2Syn
# syn = h.Exp2Syn(soma(0.5))
# syn.tau1 = 10*ms
# syn.tau2 = 50*ms
# syn.e = 0*mV

# spikesrc = h.NetStim(soma(0.5))
# spikesrc.interval = 300 # mean time between spikes in ms
# spikesrc.number = 1 # avg. no. of spikes
# spikesrc.start = 200 # mean start time of 1st spike (in ms)
# spikesrc.noise = 0 # 0 deterministic; 1 random -> IEI is exponentially decaying

# thresh = 10 # threshold to fire APs - relevant when conn to postsynaptic cell
# delay = 0.1 # delay in connection
# weight = 0.001 # strength of connection
# conn = h.NetCon(spikesrc, syn, thresh, delay, weight) # threshold, delay, weight

# tstop = 1000*ms


v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

ic = h.Vector().record(h.IClamp[0]._ref_i)
# ia = h.Vector().record(h.AlphaSynapse[0]._ref_i)
# isy = h.Vector().record(h.Exp2Syn[0]._ref_i)


## RUN SIMULATION
h.finitialize(h.v_init)
# continue sim thru 40 ms
h.continuerun(tstop)

# Debug
gEdict = {'v':soma(0.5).v, 'ina':soma(0.5).ina, 'ik':soma(0.5).ik, 'ica':soma(0.5).ica, 'ipas':soma(0.5).pas.i, 'ena':soma(0.5).ena, 'ek':soma(0.5).ek, 'eca':soma(0.5).eca, 'epas':soma(0.5).pas.e, 'gpas':soma(0.5).pas.g, 'gNa':soma(0.5).ch_Scn1a_md264834.gNav11, 'gKcnc':soma(0.5).ch_Kcnc1_md74298.gkcnc, 'gKcna':soma(0.5).ch_Kcna1ab1_md80769.gk,'gHcn2':soma(0.5).ch_Hcn2_cp10.gHCN2, 'gHcn4':soma(0.5).ch_Hcn4_cp12.gHCN4, 'gCa1b':soma(0.5).ch_Cacna1b_cp6.gCav2_2, 'gCa1c':soma(0.5).ch_Cacna1c_cp3.gL, 'gCan1i':soma(0.5).ch_Cacna1i_cp42.gCav3_3,'S/w':'NEURON'}
print(gEdict)

file = open('gEdump.csv','w') #creates a new file and writes the values in it
cw = csv.DictWriter(file, gEdict.keys())
cw.writeheader()
cw.writerow(gEdict)
file.close()

# PLOT RESULTS
plt.figure(1)
plt.plot(t, v)
#plt.xlim(90,250)
plt.xlabel('t (ms)')
plt.ylabel('v (mV)')
plt.show()

plt.figure(2)
plt.plot(t, ic)
# plt.xlim(asyn.onset-2, asyn.onset+5)
plt.xlabel('t (ms)')
plt.ylabel('i (nA)')
plt.show()



#### add save params/model functionality - json, pkl, mat #### 
#import json
#savePickle = True        # Save params, network and sim output to pickle file
#saveJson = True
#saveMat = True
#filename = 'model_params'

