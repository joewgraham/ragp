# NOTE: Code generates a figure w/ voltage v. time plots sub-plots for 3 phenotypically distinct single-compartment neuron models.
# It uses optimized values for parameters including ion channel conductances and current input for demonstrative purposes.

from neuron import h
from neuron.units import ms, mV
import matplotlib.pyplot as plt

h.load_file('stdrun.hoc')
h.v_init = -61*mV			

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1

soma.insert('pas')
soma(0.5).pas.e = -65
soma(0.5).pas.g = 1.8e-6

    
## NA ##
soma.insert('ch_Scn1a_md264834') #(Berecki et al., 2019)
soma(0.5).ch_Scn1a_md264834.gNav11bar = 1.0#(S/cm2) #2 SET W/ ANALYSIS

## K ##
soma.insert('ch_Kcna1ab1_md80769') 
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #0.011 #(S/cm2) 
soma.insert('ch_Kcnc1_md74298') 
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 #(S/cm2)

#soma.insert('ch_Kcnd1_****) ### NO MODEL; KA, channel-rapidly inactivating
#soma(0.5).ch_Kcnd1_md74298.gk = 0.015 #(S/cm2)


## CA ##
                                                        #a
soma.insert('ch_Cacna1b_cp6') #add channel suffix here  #b
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.0001 #(S/cm2)   
soma.insert('ch_Cacna1c_cp3') #add channel suffix here  #c
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.0001 #(S/cm2)
soma.insert('ch_Cacna1i_cp42') #add channel suffix here #i
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.0001 #(S/cm2) 

#soma.insert('ch_Cacna1g_cp41') #add channel suffix here #g
#soma(0.5).ch_Cacna1g_cp41.gCav3_1bar = 0.00001 #(S/cm2) SET W/ ANALYSIS
#soma.insert('ch_Cacna1g_md229585') #add channel suffix here 
#soma(0.5).ch_Caacna1g_md229585.pcabar  = 2.5e-4 (cm/s)


## HCN ##
#soma.insert('ch_Hcn1_cp9') #<----- use this model 
#soma(0.5).ch_Hcn1_cp9.gHCN1bar = 0.00001 #(S/cm2) 
##soma.insert('ch_Hcn1_md229585')
##soma(0.5).ch_Hcn1_md229585.gbar = 0.00001  #(mho/cm2)) #SET w/ ANALYSIS	
soma.insert('ch_Hcn1_md189154')
soma(0.5).ch_Hcn1_md189154.gbar = 0.0001	#(mho/cm2)

#soma.insert('ch_Hcn2_cp10') 
#soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.010

#soma.insert('ch_Hcn3_cp11') 
#soma(0.5).ch_Hcn3_cp11.gHCN3bar = 10e-5 #(S/cm2)

#soma.insert('ch_Hcn4_cp12') 
#soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.001

    
    # STIMULUS: CURRENT CLAMP
iclamp = h.IClamp(soma(0.5))
iclamp.delay = 50 #ms
iclamp.dur = 200 #ms
tstop = 500 #ms
iclamp.amp = 0 #[0.01, 0.03, 0.1, 1] #nA        # current input values

v = h.Vector().record(soma(0.5)._ref_v)         # membrane potential vector
t = h.Vector().record(h._ref_t)                 # timestamp vector

    # PLOT RESULTS
mylist1 = [10e-5, 10e-4, 10e-3, 10e-2, 10e-1, 1.0] #[1.0, 2.0, 2.5, 5.0] # conductance values 
a = 1                                           # number of rows
b = len(mylist1) #b = len(mylist1)               # number of cols
c = 1  
fig = plt.figure(figsize=(16,4))
colors = ['r', 'b', 'k']
#fname = str(mylist1)

for soma(0.5).ch_Hcn1_md189154.gbar in mylist1:
    cond = soma(0.5).ch_Hcn1_md189154.gbar
        
    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 10}) 
    plt.title('Conductance= {}'.format(cond))

    amps = [0.01, 0.05, 0.1]
 
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
 
try:
    plt.savefig('FIGSmodel/%s.png' % (fname))
    #plt.show()
except:
    plt.show()