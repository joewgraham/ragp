from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
#h.nrn_load_dll("nrnmech.dll)
h.v_init = -65*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')

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
iclamp.dur = 0.1 #ms
iclamp.amp = 0.9 #nA

v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

## RUN SIMULATION
h.finitialize(h.v_init)
# continue sim thru 40 ms
h.continuerun(40 * ms)

# PLOT RESULTS
import matplotlib.pyplot as plt

plt.figure()
plt.plot(t, v)
plt.xlabel('t (ms)')
plt.ylabel('v (mV)')
plt.show()
