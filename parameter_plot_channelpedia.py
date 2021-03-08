"""
Code takes a voltage from a NEURON simulation and uses the equations from our channelpedia models
to plot m, h, and tau values for fast sodium and potassium delayed rectifier channels. (See equations 
here https://drive.google.com/drive/folders/1bl3mHICmLVNlHHxuwjxCR4MYuVcCbJ-4)

Remember to assign the voltage and time outputs from the NEURON simulation in lines 16 and 17
"""
import numpy as np
import matplotlib.pyplot as plt

####### FAKE DATA FOR TESTING PURPOSES ################
#v = np.linspace(0,100,100)
#t = np.linspace(0,100,100)

###### from running simulation in netpyne format ##########
t = sim.allSimData['t']
v = sim.allSimData['V_soma']['cell_0']

######## ASSIGN YOUR VOLTAGE VARIABLE HERE ########
V = np.array(v) # voltage output of simulation
t = np.array(t)# time output of simulation

# Fast Sodium Parameters
m_Alpha = (0.182 * (V + 35)) / (1 - (np.exp(-(V + 35) / 9)))
m_Beta = (0.124 * (-V - 35)) / (1 - (np.exp(- (-V - 35) / 9)))
m_inf = m_Alpha / (m_Alpha + m_Beta)
m_Tau = 1 / (m_Alpha + m_Beta)
h_inf = 1 / (1 + np.exp((V + 65) / 6.2))
h_Tau = 1 / (((0.024 * (V + 50)) / (1 - (np.exp(-(V + 50) / 5)))) + ((0.0091 * (-V - 75.000123)) / (1 - np.exp(-(-V - 75.000123) / 5))))



##Plot --- to automate/create routine
#Na
#m_inf_Na
plt.plot(V, m_inf)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('m_inf_Na')
plt.show()

#m_Tau
plt.plot(V, m_Tau)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('m_Tau')
plt.show()

#h_inf
plt.plot(V, h_inf)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('h_inf')
plt.show()

#h_tau
plt.plot(V, h_Tau)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('h_Tau')
plt.show()


plt.plot(V, m_Alpha)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('m_Alpha')
plt.show()

plt.plot(V, m_Beta)
plt.rcParams['font.size'] = '8'
plt.xlabel('mv')
plt.ylabel('m_Beta')
plt.show()
############################################################

fig, axs = plt.subplots(6) #, sharex=True, sharey=True)
plt.rcParams['font.size'] = '8'
axs[0].plot(t, m_Alpha)    # Insert time vector used here
fig.suptitle('m_Alpha')
axs[0].set(ylabel='m_Alpha (mV)')

axs[1].plot(t, m_Beta)
fig.suptitle('m_Beta')
axs[1].set(ylabel='m_Beta (mV)')

axs[2].plot(t, m_inf)
fig.suptitle('m_inf')
axs[2].set(ylabel='m_inf (unitless)')

axs[3].plot(t, m_Tau)
fig.suptitle('m_Tau')
axs[3].set(ylabel='m_Tau (1/mV)')

axs[4].plot(t, h_inf)
fig.suptitle('h_inf')
axs[4].set(ylabel='h_inf (unitless)')

axs[5].plot(t, h_Tau)
fig.suptitle('h_Tau')
axs[5].set(ylabel='h_Tau (1/mV)')

plt.xlabel('t (ms)')
plt.show()
