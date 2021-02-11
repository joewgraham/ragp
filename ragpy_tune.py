from neuron import h
from neuron.units import ms, mV
from netpyne import specs, sim
import matplotlib.pyplot as plt
import numpy as np

h.load_file('stdrun.hoc')
h.v_init = -65

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm = 30, 30, 1

# RMP, pas
soma.insert('pas')
soma(0.5).pas.e = -70
soma(0.5).pas.g = 1.8e-6
v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector

def run():
    h.run()
    #plt.plot(v)
    t = np.linspace(0,h.tstop,len(v))
    plt.plot(t,v)
    plt.show()
    
run()

