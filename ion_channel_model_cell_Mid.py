## NOTE: this code contains optimized single values for conductances and Iamplitude which produces a plot of action potentials
## demonstrating the functionality of the model

from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -61*mV			

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = -65
soma(0.5).pas.g = 1.8e-6

## NA ##
soma.insert('ch_Scn1a_md264834') # (Berecki et al., 2019)
soma(0.5).ch_Scn1a_md264834.gNav11bar = 1.0 #2.0 #(S/cm2)

## K ##
soma.insert('ch_Kcnc1_md74298') 
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 #(S/cm2)
soma.insert('ch_Kcna1ab1_md80769') 
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #0.011 #(S/cm2)

## CA ##
soma.insert('ch_Cacna1c_cp3') #add channel suffix here
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.0001 #(S/cm2)
soma.insert('ch_Cacna1b_cp6') #add channel suffix here
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.0001 #(S/cm2)
soma.insert('ch_Cacna1i_cp42') #add channel suffix here
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.0001 #(S/cm2) 


## HCN ##
# N/A

# STIMULUS: ICLAMP
iclamp = h.IClamp(soma(0.5))
iclamp.delay = 50 #ms
iclamp.dur = 200 #ms
tstop = 500 #ms
iclamp.amp = 0 #[0.01, 0.03, 0.1, 1] #nA


v = h.Vector().record(soma(0.5)._ref_v) # membrane potential vector
t = h.Vector().record(h._ref_t)         # timestamp vector


# PLOT RESULTS
import matplotlib.pyplot as plt


# RUN SIMULATION
#h.finitialize(h.v_init)
#h.continuerun(500* ms)
##### plot v1 ####
#plt.figure()
#plt.plot(t, v)
#plt.xlabel('t (ms)')
#plt.ylabel('v (mV)')
##plt.show()


##### plot v2 ####
model = "cell_Mid"
#mylist1 = [1.0, 2.0, 2.5, 5.0] #Conductance values 
mylist1 = [1.0]
fname = model + str(mylist1)
#SAVE DATA FILE AND PLOT FOR EACH CONDUCTANCE - 
###############################################
a = 1 # number of rows
b = len(mylist1)
c = 1  # initialize plot counter
fig = plt.figure(figsize=(6,4))

for soma(0.5).ch_Scn1a_md264834.gNav11bar in mylist1:
    cond = soma(0.5).ch_Scn1a_md264834.gNav11bar
    
    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 10}) 
    plt.title('Conductance Nav1.1= {}'.format(cond)) 
    amps = [0.04] #[0.01, 0.05, 0.1]
    colors = ['magenta'] #['red', 'blue', 'black']
    
    for amp, color in zip(amps, colors):
        iclamp.amp = amp
        h.finitialize(h.v_init * mV)
        h.continuerun(500* ms)
        plt.plot(t,v, color=color)
        plt.ylim((-80,70))
        plt.xlabel('t (ms)')
        plt.ylabel('v (mV)')
        plt.legend(amps)
    c = c+1

plt.show()
plt.savefig('FIGSmodel/%s.png' % (fname))





