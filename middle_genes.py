from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -65*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = h.v_init

soma.insert('ch_Cacna1b_cp6') #add channel suffix here
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.00001
soma.insert('ch_Cacna1c_cp3') #add channel suffix here
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.00001
soma.insert('ch_Cacna1i_cp42') #add channel suffix here
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.00001 

soma.insert('ch_Scn1a_cp35') #add channel suffix here
soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001 #0.00001

soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 
soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.011
soma.insert('ch_Kcna1_') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.011  

#leak channel


iclamp = h.IClamp(soma(0.5))
iclamp.delay = 65 #ms
iclamp.dur = 0.1 #ms
iclamp.amp = 0.9 #nA


v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

## RUN SIMULATION
h.finitialize(h.v_init)
# continue sim thru 40 ms
h.continuerun(140 * ms)

# PLOT RESULTS
import matplotlib.pyplot as plt

plt.figure()
plt.plot(t, v)
plt.xlabel('t (ms)')
plt.ylabel('v (mV)')
plt.show()
