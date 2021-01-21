from neuron import h
from neuron.units import ms, mV
import matplotlib.pyplot as plt
h.load_file('stdrun.hoc')
h.v_init = -65

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm = 30, 30, 1

# RMP, pas
soma.insert('pas')
v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector

run()