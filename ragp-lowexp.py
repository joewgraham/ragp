from neuron import h
from neuron.units import ms, mV

#import neuron.gui
import numpy as np

import csv

h.load_file('stdrun.hoc')
#h.nrn_load_dll("nrnmech.dll)
#h.v_init = -65*mV			#need to revisit - is it -44.5 mV?
h.v_init = -44.5*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = h.v_init

#Sodium and Potassium delayed rectifier channels
#================================================
#soma.insert('Naf') #add channel suffix here
#soma(0.5).Naf.gNabar = 0.106103295
#soma.insert('KDR') #add channel suffix here
#soma(0.5).KDR.gDrbar=0.031830989

soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001
soma(0.5).ch_Scn1a_cp35.gNabar = 0.1
#soma(0.5).ch_Scn1a_cp35.gNabar = 0.0400

soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 
soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.011

soma.insert('ch_Cacna1b_cp6') #add channel suffix here
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.00001
soma.insert('ch_Cacna1c_cp3') #add channel suffix here
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.00001

soma.insert('ch_Hcn2_cp10') #add channel suffix here
soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.00001
soma.insert('ch_Hcn4_cp12') #add channel suffix here
soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.00001
     
# def initalize_segments(): #add channel parameters that we need to tune from .py file
#     for x in soma:		#parameters must not change channel dynamics; 
#         x.				#only expression levels and ...?

iclamp = h.IClamp(soma(0.5))
iclamp.delay = 2 #ms
#iclamp.delay = 65 #ms
#iclamp.dur = 0.1 #ms
iclamp.dur = 0.1 #ms
#iclamp.amp = 0.9 #nA
iclamp.amp = 0.9 #nA

soma.psection()

v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

timeArray = np.array(t)
vSoma = np.array(v)

## RUN SIMULATION
h.finitialize(h.v_init)
# continue sim thru 40 ms
h.continuerun(100 * ms)



# PLOT RESULTS
import matplotlib.pyplot as plt
plt.rcParams.update({'font.size': 12})

plt.figure()
plt.plot(t, v, '.', color='black')
plt.xlabel("Time (s)")
plt.ylabel("Output (V)")
plt.grid(True)
plt.show()


with open('Scn1a/data_10.csv', 'w') as f:
    csv.writer(f).writerows(zip(t, v))

    
#with open('data.csv') as f:
#    reader = csv.reader(f)
#    tnew, vnew = zip(*[[float(val) for val in row] for row in reader if row])


#h('strdef s')
#h('{x = 3  s = "hello"}')
#print (h.x)          # prints 3.0
#print (h.s)          # prints hello
#print(h.Vector().record(soma(0.5)._ref_v))

#import pickle
#with open('t.p', 'wb') as t_file:
#    pickle.dump(t, t_file)
#with open('v.p', 'wb') as v_file:
#    pickle.dump(v, v_file)
#
#with open('t.p', 'rb') as t_file:
#    t = pickle.load(t_file)
#with open('v.p', 'rb') as file:
#    v = pickle.load(file)

#plt.figure(figsize=(8,4))
#step = 0.075
#num_steps = 4
#for i in np.linspace(step, step*num_steps, num_steps):
#    stim.amp = i
#    h.tstop = simdur
#    h.run()
#    plt.plot(t, v, color='black')
#
#plt.xlabel('time (ms)')
#plt.ylabel('mV')
#plt.show()



#plt.figure(figsize=(4,3))
#ax = fig.add_subplot(111)
#x = np.linspace(0,4.15,10)
#plt.plot(t,v, '-^')
#plt.title("Oscillator Output")
#plt.xlabel("Time (s)")
#plt.ylabel("Output (V)")
#plt.grid(True)
#plt.legend(loc=1)
#plt.show()
#fig.savefig('Basic.png', dpi=300)


