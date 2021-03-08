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
t = sim.allSimData['t']
v = sim.allSimData['V_soma']['cell_0']

######## ASSIGN YOUR VOLTAGE VARIABLE HERE ########
V = v # voltage output of simulation
# t = time # time output of simulation
V = np.array(v) # voltage output of simulation
t = np.array(t)
# Fast Sodium Parameters
m_Alpha = (0.182 * (V + 35)) / (1 - (np.exp(-(V + 35) / 9)))
m_Beta = (0.124 * (-V - 35)) / (1 - (np.exp(- (-V - 35) / 9)))
m_inf = m_Alpha / (m_Alpha + m_Beta)
m_Tau = 1 / (m_Alpha + m_Beta)
h_inf = 1 / (1 + np.exp((V + 65) / 6.2))
h_Tau = 1 / (((0.024 * (V + 50)) / (1 - (np.exp(-(V + 50) / 5)))) + ((0.0091 * (-V - 75.000123)) / (1 - np.exp(-(-V - 75.000123) / 5))))


# Potassium channel parameters
# Constants from Kcna1ab1_md80769 
ca = 0.12889 #(1/ms)
cva = 45 #(mV)
cka = -33.90877 #(mV)

cb = 0.12889 #(1/ms)
cvb = 45 #(mV)
ckb = 12.42101 #(mV) 

celsius = 27
q10 = 3
qt = q10**((celsius-22) / 10)

def alphanfkt(V):
    return ca * np.exp(-(V+cva)/cka)


def betanfkt(V):
    return cb * np.exp(-(V+cvb)/ckb)


alphan = alphanfkt(V)
betan = betanfkt(V)
ninf = alphan/(alphan+betan) 
taun = 1/(qt*(alphan + betan))  





#### plot of V v above vars/params #### - will write routine for plotting, for now just use piecemeal
# m_inf_Na
plt.plot(V, m_inf)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('m_inf_Na')
plt.show()

# tau_mNA
plt.plot(V, m_Tau)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('m_Tau_Na')
plt.show()

#h_inf_Na
plt.plot(V, h_inf)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('h_inf_Na')
plt.show()

#tau_hNa
plt.plot(V, h_Tau)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('tau_hNa')
plt.show()


# K values
#n_inf
plt.plot(V, ninf)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('ninf')
plt.show()


# Kdr
plt.plot(V, taun)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('taun')
plt.show()

# alpha_m, beta_m where alpha = rate of Na activation and beta = rates of Na deactivation


#alpha_h, beta_h?


# alpha n, beta_n
plt.plot(V,alphan)
plt.plot(V, betan)
plt.rcParams['font.size'] = '6'
plt.xlabel('mv')
plt.ylabel('alpha_n, beta_n')
plt.show()


#m, n, h

####################################################
# Plot
#fig, axs = plt.subplots(6) #, sharex=True, sharey=True)
#plt.rcParams['font.size'] = '8'

#axs[0].plot(t, m_inf)
#fig.suptitle('m_inf')
#axs[0].set(ylabel='m_inf (unitless)')

#axs[1].plot(t, m_Tau)
#fig.suptitle('m_Tau')
#axs[1].set(ylabel='m_Tau (1/mV)')

#axs[2].plot(t, h_inf)
#fig.suptitle('h_inf')
#axs[2].set(ylabel='h_inf (unitless)')

#axs[3].plot(t, h_Tau)
#fig.suptitle('h_Tau')
#axs[3].set(ylabel='h_Tau (1/mV)')

#axs[4].plot(t, ninf)   
#fig.suptitle('Postassium, ninf')
#axs[4].set(ylabel='ninf (unitless)')

#axs[5].plot(t, taun)
#fig.suptitle('Potassium, taun')
#axs[5].set(ylabel='taun (ms)')

#plt.xlabel('t (ms)')
#plt.show()
