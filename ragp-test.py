from neuron import h
from neuron.units import ms, mV

import numpy as np

h.load_file('stdrun.hoc')
#h.v_init = -65*mV			#need to revisit - is it -44.5 mV?
h.v_init = -44.5*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = h.v_init


soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 0.00001
soma(0.5).ch_Scn1a_cp35.gNabar = 0.000000001
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
iclamp.dur = 0.1 #ms
iclamp.amp = 0.9 #nA


def set_recording_vectors(cell):
    """Set soma and time recording vectors on the cell.
    :param cell: Cell to record from.
    :return: the soma and time vectors as a tuple.
    """
    soma_v_vec = h.Vector()   # Membrane potential vector at soma
    t_vec = h.Vector()        # Time stamp vector
    soma_v_vec.record(soma(0.5)._ref_v)
    t_vec.record(h._ref_t)
    return soma_v_vec,  t_vec

    #v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
    #t = h.Vector().record(h._ref_t)                     # timestamp vector


def simulate(tstop=40):
    """Initialize and run a simulation.

    :param tstop: Duration of the simulation.
    """
    h.finitialize(h.v_init)
    h.tstop = tstop
    h.run()


## RUN SIMULATION
#h.finitialize(h.v_init)
# continue sim thru 40 ms
#h.continuerun(100 * ms)

h('strdef s')
h('{x = 3  s = "hello"}')
print (h.x)          # prints 3.0
print (h.s)          # prints hello


def show_output(soma_v_vec, t_vec, new_fig=True):
    """Draw the output.

    :param soma_v_vec: Membrane potential vector at the soma.
    :param t_vec: Timestamp vector.
    :param new_fig: Flag to create a new figure (and not draw on top
            of previous results)
    """
    import matplotlib.pyplot as plt
    plt.rcParams.update({'font.size': 12})
    if new_fig:
        pyplot.figure(figsize=(8,4)) # Default figsize is (8,6)
    soma_plot = pyplot.plot(t_vec, soma_v_vec, color='black')
    pyplot.legend(soma_plot , ['soma'])
    pyplot.xlabel('time (ms)')
    pyplot.ylabel('mV')



# PLOT RESULTS
#import matplotlib.pyplot as plt
#plt.rcParams.update({'font.size': 12})

#plt.figure()
#plt.plot(t, v, '.', color='blue')
#plt.xlabel("Time (s)")
#plt.ylabel("Output (V)")
#plt.grid(True)
#plt.show()


