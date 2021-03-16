from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -65*mV

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm = 30, 30, 1

<<<<<<< HEAD:s_ragp.py
#soma.insert('pas')
#soma.insert('hh')
#hh.gnabar, hh.gkbar, hh.gl, hh.el = 0.12 , 0.036 , 0.0003 , -54.3 #NOTE: hh. throws an error
# soma(0.5).hh.gnabar # = 0.12
# soma(0.5).hh.gkbar # = 0.036
# soma(0.5).hh.gl #= 0.0003
# soma(0.5).hh.el #= -54.3
=======
soma.insert('pas')
soma.insert('hh')
#hh.gnabar, hh.gkbar, hh.gl, hh.el = 0.12 , 0.036 , 0.0003 , -54.3 #NOTE: hh. throws an error
soma(0.5).hh.gnabar = 0.12  # changing from parameter value in mod file
soma(0.5).hh.gkbar  = 0.036 #  
soma(0.5).hh.gl = 0.0003
soma(0.5).hh.el = -54.3
>>>>>>> 744e5b9fca5505a5ec9e19dcbfba1d15e41b4b09:ragp.py

# SET NSEG - setting hh.gnabar for all nseg
# for seg in soma: print(seg)
#    seg.hh.gnabar
# soma.nseg = 3

<<<<<<< HEAD:s_ragp.py
# mech = soma(0.5).hh
#print(dir(mech))

## INSERT AN ICLAMP/STIMULUS
# iclamp = h.IClamp(soma(0.5))

# #looking at iclamp params:
# print([item for item in dir(iclamp) if not item.startswith('__')])
# #['amp', 'baseattr', 'delay', 'dur', 'get_loc', 'get_segment', 'has_loc', 'hname', 'hocobjptr', 'i', 'loc', 'same']
# iclamp.delay = 2 #ms
# iclamp.dur = 0.1 #ms
# iclamp.amp = 0.9 #nA
=======
## INSERT AN ICLAMP/STIMULUS
iclamp = h.IClamp(soma(0.5))
iclamp.delay = 2 #ms
iclamp.dur = 0.1 #ms
iclamp.amp = 0.9 #nA
>>>>>>> 744e5b9fca5505a5ec9e19dcbfba1d15e41b4b09:ragp.py

#looking at iclamp params:
#print([item for item in dir(iclamp) if not item.startswith('__')])
#['amp', 'baseattr', 'delay', 'dur', 'get_loc', 'get_segment', 'has_loc', 'hname', 'hocobjptr', 'i', 'loc', 'same']


# get representation of current model
soma.psection()

## SET UP RECORDING VARIABLES
v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

## RUN SIMULATION
# initalize sim w/ resting potential
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
# SAVE figure

