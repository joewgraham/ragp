"""
Code takes a voltage from a NEURON simulation and uses the equations in Table 1 of Rybak 1, 1997
to plot m, h, and tau values for fast sodium and potassium delayed rectifier channels

Remember to assign the voltage output from the NEURON simulation in line 12
"""
import numpy as np
import matplotlib.pyplot as plt
from neuron import h

######## ASSIGN YOUR VOLTAGE VARIABLE HERE ########
V = v # voltage output of simulation, or look up in Hodgkin and Huxley 1952 

# Fast Sodium Parameters
m_inf_Na = (0.091 * (V + 38) / (1-np.exp(-(V + 38)/5))) / (0.091 * (V + 38) / (1-np.exp(-(V + 38)/5)) + 0.062 * (V + 38) / (np.exp((V + 38)/5)-1))
tau_mNa = 1 / (0.091 * (V + 38) / (1 - np.exp(-(V + 38) / 5)) + 0.062 * (V + 38) / (np.exp((V + 38) / 5) - 1))
h_inf_Na = (0.016 * np.exp(-(V + 55) / 15)) / (0.016 * np.exp(-(V + 55) / 15) + 2.07 / (1 + np.exp(-(V - 17) / 21)))
tau_hNa = 1 / (0.016 * np.exp(-(V + 55) / 15) + 2.07 / (1 + np.exp(-(V - 17) / 21)))

# Potassium-delayed rectifier
m_inf_DR = (0.01 * (V + 45) / (1 - np.exp(-(V + 45) / 5))) / (0.01 * (V + 45) / (1 - np.exp(-(V + 45) / 5)) + 0.17 * np.exp(-(V + 50) / 40))

# Plot
fig, axs = plt.subplots(5) #, sharex=True, sharey=True)
axs[0].plot(t, m_inf_Na)    # Insert time vector used here
fig.suptitle('m_inf_Na')
axs[0].set(ylabel='m_inf_Na (unitless)')

axs[1].plot(t, tau_mNa)
fig.suptitle('tau_mNa')
axs[1].set(ylabel='tau_mNA (1/mV)')

axs[2].plot(t, h_inf_Na)
fig.suptitle('≈≈')
axs[2].set(ylabel='h_inf_Na (unitless)')

axs[3].plot(t, tau_hNa)
fig.suptitle('tau_hNa')
axs[3].set(ylabel='tau_hNa (unitless)')

axs[4].plot(t, m_inf_DR)
fig.suptitle('m_inf_DR')
axs[4].set(ylabel='m_inf_DR (unitless)')

plt.xlabel('t (ms)')
plt.show()

from scipy.io import savemat
import json

### ADD SAVE TO FILE for above m, h PARAMS ###
# mat file 
# json file