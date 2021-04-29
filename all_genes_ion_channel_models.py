# NOTE: Code generates a figure w/ voltage v. time plots sub-plots using all gene/IC models in the study and optimized conducances
# based on testing. Total Na ch: 1; total K ch: 2; total Ca ch:6; total Hcn ch: 4
# VARIATIONS: (nb - ** indicates tonic v. phasic dependening on conductance for a given IC model, ++ indicates non ghk Ca)
## Na: Scn1a (5): **
## K: Kcnc1 (3); Kcnd1 (0)
## Ca: Cacnac1c (2 - 1 generic L type): **, Cacnag1 (2): **, ++; Cacnca1i (2)
## Ca ghk(): 
## Hcn: Hcn1 (3), Hcn2 (1), Hcn3 (1), Hcn4 (1) 

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
soma(0.5).ch_Scn1a_md264834.gNav11bar = 1.0#(S/cm2) #2.01 SET W/ ANALYSIS

## K ##
soma.insert('ch_Kcna1ab1_md80769') 
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #phasic at 0.1 nA, #0.011 tonic at 0.05nA and 0.1nA #(S/cm2) 
soma.insert('ch_Kcnc1_md74298') 
soma(0.5).ch_Kcnc1_md74298.gk = 0.015
#soma.insert('ch_Kcnc1_cp25') 
#soma(0.5).ch_Kcnc1_cp25.gKv3_1bar = 0.001 #(S/cm2
#soma.insert('ch_Kcnc1_cp27') 
#soma(0.5).ch_Kcnc1_cp27.gKv3_1bar = 0.001 #(S/cm2

#soma.insert('ch_Kcnd1_****) ### NO MODEL; KA, channel-rapidly inactivating
#soma(0.5).ch_Kcnd1_md74298.gk = 0.015 #(S/cm2)

## CA ghk() ##
#a
soma.insert('ch_Cacna1a_cp5')
soma(0.5).ch_Cacna1a_cp5.gCav2_1bar = 0.0001 #S/cm2 #TESTED
##soma.insert('ch_Cacna1a_md229585')
##soma(0.5).ch_Cacna1a_md229585.pcabar = 2.2e-4 #(cm/s)
#b
soma.insert('ch_Cacna1b_cp6')
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 1e-4 #S/cm2 #TESTED

#c
#soma.insert('ch_Cacna1c_cp3')
#soma(0.5).ch_Cacna1c_cp3.gLbar = 1e-5 #S/cm2 #TESTED

#d
#soma.insert('ch_Cacna1d_md121090')
#soma(0.5).ch_Cacna1d_md121090.pmax = 4.25e-7	#(cm/s)

#g
#soma.insert('ch_Cacna1g_cp41')
#soma(0.5).ch_Cacna1g_cp41.gCav3_1bar = 1e-5 #S/cm2 #TESTED
#soma.insert('ch_Cacna1g_md229585')
#soma.insert(0.5).ch_Cacna1g_md229585.pcabar = 2.5e-4 #(cm/s)

#i1
#soma.insert('ch_Cacna1i_cp42')
#soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 1e-5 #S/cm2 #TESTED
#soma.insert('ch_Cacna1i_md19920')
#soma(0.5).ch_Cacna1i_md19920.gbar = 1e-5 #mho/cm2


## HCN ##
#soma.insert('ch_Hcn1_cp9') #<----- use this model 
#soma(0.5).ch_Hcn1_cp9.gHCN1bar = 0.0001 #phasic component # tonic: 0.0001 #(S/cm2) 
#soma.insert('ch_Hcn1_md229585')
#soma(0.5).ch_Hcn1_md229585.gbar = 0.00001  #(mho/cm2)) 
#soma.insert('ch_Hcn1_md189154')
#soma(0.5).ch_Hcn1_md189154.gbar = 0.0001	#(mho/cm2)

soma.insert('ch_Hcn2_cp10') 
soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.0001 #0.0001 - both phasic and tonic. 0.0001 doublet. 
#soma.insert('ch_Hcn3_cp11') 
#soma(0.5).ch_Hcn3_cp11.gHCN3bar = 0.0001 #(S/cm2)
#soma.insert('ch_Hcn4_cp12') 
#soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.001 #or tonic 0.001


# STIMULUS: CURRENT CLAMP
iclamp = h.IClamp(soma(0.5))
iclamp.delay = 50 #ms
iclamp.dur = 200 #ms
tstop = 500 #ms
iclamp.amp = 0 #[0.01, 0.03, 0.1, 1] #nA        # current input values

v = h.Vector().record(soma(0.5)._ref_v)         # membrane potential vector
t = h.Vector().record(h._ref_t)                 # timestamp vector
#mylist1 = [1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e-0]   #conductance vals
fname = 'models_04_genes_8_scn1a'

#fig = plt.figure(figsize=(21,4))
fig = plt.figure(figsize=(5,4))
#a = 1                                           # number of rows
#b = len(mylist1) #b = len(mylist1)               # number of cols
#c = 1                                           # initialize plot counter
amps = [0.01, 0.05, 0.1]
colors = ['r', 'b', [0.4, 0.4, 0.4]]

for amp, color in zip(amps, colors):
    iclamp.amp = amp
    h.finitialize(h.v_init * mV)
    h.continuerun(500* ms)
    plt.plot(t,v, color=color)
    plt.ylim((-80,80))
    plt.xlabel('t (ms)')
    plt.ylabel('v (mV)')
    plt.legend(amps)
#c = c+1
plt.savefig('FIGS_modeltypes/%s.png' % (fname))
plt.show()

#######################################
#######################################
for soma(0.5).ch_Cacna1i_md19920.gbar in mylist1:
        cond = soma(0.5).ch_Cacna1i_md19920.gbar
        
        plt.subplot(a, b, c)
        plt.rcParams.update({'font.size': 8}) 
        plt.title(fname + ', ' + 'Cond. = {}'.format(cond))

        amps = [0.01, 0.05, 0.1]
        colors = ['r', 'b', 'k']

        for amp, color in zip(amps, colors):
            iclamp.amp = amp
            h.finitialize(h.v_init * mV)
            h.continuerun(500* ms)
            plt.plot(t,v, color=color)
            plt.ylim((-80,80))
            plt.xlabel('t (ms)')
            plt.ylabel('v (mV)')
            plt.legend(amps)
        c = c+1
 
plt.savefig('FIGS_modeltypes/%s.png' % (fname))
plt.show()

####### END ############################################

########################################################
################### FOR TESTING ONLY ###################

## PLOT RESULTS
amps = [0.01, 0.05, 0.1, 0.5]
colors = ['r','k','b', 'm']
fname = ''

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

#for amp in amps:
#    iclamp.amp = amp
#    h.finitialize(h.v_init * mV)
#    h.continuerun(500* ms)     
#    plt.plot(t,v)
#    plt.ylim((-80,80))
#    plt.xlabel('t (ms)')
#    plt.ylabel('v (mV)')
#    plt.legend(amps) 
    
try:
    plt.savefig('FIGS_ICmodels/%s.png' % (fname))
    plt.show()
except:
    plt.show()



########################################################
################### FOR TESTING ONLY ###################


mylist1 = [1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e-0] #[1.0, 2.0, 2.5, 5.0] # conductance values 
a = 1                                           # number of rows
b = len(mylist1) #b = len(mylist1)              # number of cols
c = 1  
fig = plt.figure(figsize=(16,4))
colors = ['r', 'b', 'k']
#fname = str(mylist1)
fname = 'sim_prev_min_4' 



for soma(0.5).ch_Hcn4_cp12.gHCN4bar in mylist1:
    cond = soma(0.5).ch_Hcn4_cp12.gHCN4bar
        
    plt.subplot(a, b, c)
    plt.rcParams.update({'font.size': 10}) 
    plt.title('Conductance= {}'.format(cond))

    amps = [0.01, 0.05, 0.1]
 
    for amp, color in zip(amps, colors):
        iclamp.amp = amp
        h.finitialize(h.v_init * mV)
        h.continuerun(500* ms)
        plt.plot(t,v, color=color)
        plt.ylim((-80,80))
        plt.xlabel('t (ms)')
        plt.ylabel('v (mV)')
        plt.legend(amps)
    c = c+1
 
try:
    plt.savefig('FIGS_ICmodels/%s.png' % (fname))
    plt.show()
except:
    plt.show()


#################################################################################################
## CA ## NON ghk()
#soma.insert('ch_Cacna1a_cp5')                          
#soma(0.5).ch_Cacna1a_cp5.gCav2_1bar = 0.0001 #(S/cm2) 
#soma.insert('ch_Cacna1b_cp6') #add channel suffix here 
#soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.0001 #(S/cm2)   
#soma.insert('ch_Cacna1c_cp3') #add channel suffix here  #c
#soma(0.5).ch_Cacna1c_cp3.gLbar = 0.001 #(tonic) #10e-3 (phasic) #(S/cm2)
#soma.insert('ch_Cacna1c_md121060')
#soma(0.5).ch_Cacna1c_md121060.
#d - no mod file
#soma.insert('ch_Cacna1g_cp41')                         #g
#soma(0.5).ch_Cacna1g_cp41.gCav3_1bar = 0.0001 #tonic, #0.001 #phasic
###soma.insert('ch_Cacna1g_md229585') # external ghk() <-- UNABLE TO TEST
###soma(0.5).ch_Caacna1g_md229585.pcabar  = 2.5e-4 #(cm/s)                                                   
#soma.insert('ch_Cacna1i_cp42') #add channel suffix here #i
#soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.00001 #(S/cm2) 
#soma.insert('ch_Cacna1i_md19920')
#soma(0.5).ch_Cacna1i_md19920.gbar = 0.0001