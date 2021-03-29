from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -61*mV			

soma = h.Section(name='soma')
soma.L, soma.diam, soma.cm, soma.nseg = 30, 30, 1, 1


soma.insert('pas')
soma(0.5).pas.e = -65
soma(0.5).pas.g = 1.8e-6

###### CALCIUM ######
#soma.insert('ch_Cacna1a_md229585')  #add channel suffix here  GHK
#soma(0.5).ch_Cacna1a_md229585.pcabar =  2.2e-4 #(cm/s)
#soma.insert('ch_Cacna1a_cp5')  #add channel suffix here
#soma(0.5).ch_Cacna1a_gCav2_1.gbar = 0.00001 #(S/cm2) 

soma.insert('ch_Cacna1b_cp6') #add channel suffix here
soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 0.0001

soma.insert('ch_Cacna1c_cp3') #add channel suffix here
soma(0.5).ch_Cacna1c_cp3.gLbar = 0.0001

#soma.insert('ch_Cacna1d_md121060') #add channel suffix here
#soma(0.5).ch_Cacna1d_md121060.pmax = 4.25e-7	#(cm/s)
#soma.insert('ch_Cacna1d_cp41') #add channel suffix here
#soma(0.5).ch_Cacna1d_cp41.gCav3_1bar = 0.00001 #(S/cm2) 

#soma.insert('ch_Cacna1g_cp41') #add channel suffix here
#soma(0.5).ch_Cacna1g_cp41.gCav3_1bar = 0.00001 #(S/cm2) 
#soma.insert('ch_Cacna1g_md229585')  #add channel suffix here
#soma(0.5).ch_Cacna1g_md229585.pcabar = 2.5e-4 #(cm/s)

soma.insert('ch_Cacna1i_cp42') #add channel suffix here
soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 0.0001 #(S/cm2)
#soma.insert('ch_Cacna1i_md19920')
#soma(0.5).ch_Cacna1i_md19920.gbar = 0.008 #(mho/cm2)




###### SODIUM ######
### Berecki 2019 ###
soma.insert('ch_Scn1a_md264834') #add channel suffix here
soma(0.5).ch_Scn1a_md264834.gNav11bar = 1.0 #0.00001 #(S/cm2)
### Zheng 2019 ###
#soma.insert('ch_Scn1a_md256632') #add channel suffix here
#soma(0.5).ch_Scn1a_md256632.gnabar = 0.01 #(S/cm2)
### Traub 2003 ###
#soma.insert('ch_Naf_md20756') #add channel suffix here
#soma(0.5).ch_Naf_md20756.gbar = 0.0 	   #(mho/cm2)
### Rybak 1997 ###
#soma.insert('ch_Naf_rybak') #add channel suffix here
#soma(0.5).ch_Naf_rybak.gNabar=0.106103295 #(S/cm2) <0,1e9> 

###### HCN ######
#soma.insert('ch_Hcn1_md229585')  #add channel suffix here
#soma(0.5).ch_Hcn1_md229585.gbar = 0.0001 #(mho/cm2)
#soma.insert('ch_Hcn1_cp9')
#soma(0.5).ch_Hcn1_cp9.gHCN1bar =  0.00001 #(S/cm2) 

soma.insert('ch_Hcn2_cp10') #add channel suffix here
soma(0.5).ch_Hcn2_cp10.gHCN2bar = 0.010

#soma.insert('ch_Hcn3_cp11')  #add channel suffix here
#soma(0.5).ch_Hcn3_cp11.gHCN3bar = 0.00001 #(S/cm2) 

soma.insert('ch_Hcn4_cp12') #add channel suffix here
soma(0.5).ch_Hcn4_cp12.gHCN4bar = 0.001





###### POTASSIUM ######
soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.015 

soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.015 #0.011

##Kcns3 -- comprised of Kcnb1 (heteromeric) + Kcnb2 -- Kcnb1 might be better proxy. No mod files avail for Kcns3
#soma.insert('ch_Kcnb1_cp23') #add channel suffix here
#soma(0.5).ch_Kcnb1_cp23.gKv2_1bar = 0.00001 #(S/cm2) 

#soma.insert('ch_Kcnb2_cp24') #add channel suffix here
#soma(0.5).ch_Kcnb2_cp24.gKv2_2bar = 0.00001 #(S/cm2) = 


####################################################
###### REG PROTEINS #####
### use in NN only ###
#soma.insert('ch_Kcnip1_***')  #add channel suffix here
#soma(0.5).ch_Kcnip1_*** =

#soma.insert('ch_Kcne1_***')  #add channel suffix here
#soma(0.5).ch_Kcne1_.*** =

#soma.insert('ch_Kcnrg_***')  #add channel suffix here
#soma(0.5).ch_Kcnrg_.*** =

#soma.insert('ch_Kcnj_***')  #add channel suffix here
#soma(0.5).ch_Kcnj_.*** =


iclamp = h.IClamp(soma(0.5))
iclamp.delay = 50 #ms
iclamp.dur = 200 #ms #0.5
tstop = 500
iclamp.amp = 0 #0.1 #0.05 #0.1 #1 #nA


v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector


# PLOT RESULTS
import matplotlib.pyplot as plt


#### plot v2 ####
model = "cell_R" #"cell_Mid"
mylist1 = [1.0, 2.0, 2.5, 5.0] #Conductance values 
#mylist1 = [2.0]
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
    plt.title('Nav1.1 Conductance= {}'.format(cond)) #_Scna1 #Kcna1ab1
    amps = [0.01, 0.03, 0.1]
    colors = ['red', 'blue', 'black']
    
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


plt.savefig('FIGSmodel/%s.png' % (fname))
plt.show()


### RUN SIMULATION
#h.finitialize(h.v_init)
## continue sim thru 40 ms
#h.continuerun(500* ms)
##### plot v1 ####
#plt.figure()
#plt.plot(t, v)
#plt.xlabel('t (ms)')
#plt.ylabel('v (mV)')
#plt.show()
