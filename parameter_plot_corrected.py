"""
Code takes a voltage from a NEURON simulation and uses the equations in Table 1 of Rybak 1, 1997
to plot m, h, and tau values for fast sodium and potassium delayed rectifier channels

Remember to assign the voltage output from the NEURON simulation in line 12
"""
import numpy as np
import matplotlib.pyplot as plt
from neuron import h


### IF NETPYNE
t = sim.allSimData['t']
v = sim.allSimData['V_soma']['cell_0']
#if NEURON
#v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
#t = h.Vector().record(h._ref_t)                     # timestamp vector
V = v
######## ASSIGN YOUR VOLTAGE VARIABLE HERE ########
V = np.array(v) # voltage output of simulation
t = np.array(t)
# Fast Sodium Parameters
m_inf_Na = (0.091 * (V + 38) / (1-np.exp(-(V + 38)/5))) / (0.091 * (V + 38) / (1-np.exp(-(V + 38)/5)) + 0.062 * (V + 38) / (np.exp((V + 38)/5)-1))   
tau_mNa = 1 / (0.091 * (V + 38) / (1 - np.exp(-(V + 38) / 5)) + 0.062 * (V + 38) / (np.exp((V + 38) / 5) - 1))
h_inf_Na = (0.016 * np.exp(-(V + 55) / 15)) / (0.016 * np.exp(-(V + 55) / 15) + 2.07 / (1 + np.exp(-(V - 17) / 21)))
tau_hNa = 1 / (0.016 * np.exp(-(V + 55) / 15) + 2.07 / (1 + np.exp(-(V - 17) / 21)))
  
# Potassium-delayed rectifier
m_inf_DR = (0.01 * (V + 45) / (1 - np.exp(-(V + 45) / 5))) / (0.01 * (V + 45) / (1 - np.exp(-(V + 45) / 5)) + 0.17 * np.exp(-(V + 50) / 40))
tau_m_DR = 1/(0.01 * (V + 45) / (1 - np.exp(-(V + 45) / 5)) + 0.17 * np.exp(-(V + 50) / 40))

#### Plotting one variable at a time 
# m_inf_Na
plt.plot(V, m_inf_Na)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('m_inf_Na')
plt.show()

# tau_mNA
plt.plot(V, tau_mNa)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('tau_mNa')
plt.show()

#h_inf_Na
plt.plot(V, h_inf_Na)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('h_inf_Na')
plt.show()

#tau_hNa
plt.plot(V, tau_hNa)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('tau_hNa')
plt.show()

#m_inf_DR
plt.plot(V, m_inf_DR)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('m_inf_DR')
plt.show()

#tau_m_DR - corresponds to beta
plt.plot(V, tau_m_DR)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('tau_m_DR')
plt.show()

### DO NOT USE FOR NOW --- INCORRECT WAY OF LOOKING AT these params####
# Plot
#fig, axs = plt.subplots(6) #, sharex=True, sharey=True)
#axs[0].plot(t, m_inf_Na)    # Insert time vector used here
#fig.suptitle('m_inf_Na')
#axs[0].set(ylabel='m_inf_Na (unitless)')

#axs[1].plot(t, tau_mNa)
#fig.suptitle('tau_mNa')
#axs[1].set(ylabel='tau_mNA (1/mV)')

#axs[2].plot(t, h_inf_Na)
#fig.suptitle('h_inf_Na')
#axs[2].set(ylabel='h_inf_Na (unitless)')

#axs[3].plot(t, tau_hNa)
#fig.suptitle('tau_hNa')
#axs[3].set(ylabel='tau_hNa (unitless)')

#axs[4].plot(t, m_inf_DR)
#fig.suptitle('m_inf_DR')
#axs[4].set(ylabel='m_inf_DR (unitless)')

#axs[5].plot(t, tau_m_DR)
#fig.suptitle('tau_m_DR')
#axs[5].set(ylabel='tau_m_DR (1/mV)')

#plt.xlabel('t (ms)')
#plt.show()
