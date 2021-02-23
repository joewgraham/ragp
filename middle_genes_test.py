from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -60		

soma = h.Section(name='soma')
soma.L, soma.diam,soma.nseg, soma.cm = 30, 30, 1, 0.884194128
soma.Ra = 123

# leak channel
soma.insert('pas')
soma(0.5).pas.e = -43
soma(0.5).pas.g = 0.001 #1.768388

#soma.insert('ch_Cacna1b_cp6') #add channel suffix here
#soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Cacna1c_cp3') #add channel suffix here
#soma(0.5).ch_Cacna1c_cp3.gLbar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Cacna1i_cp42') #add channel suffix here
#soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 1e-1 #1e-4 #1e-3 #1e-2 #1e-1 #1

soma.insert('Naf')
soma(0.5).Naf.gNabar = 0.106103295

soma.insert('KDR')
soma(0.5).KDR.gDrbar = 0.031830989

#soma.insert('ch_Kcnc1_md74298') #add channel suffix here
#soma(0.5).ch_Kcnc1_md74298.gk = 0.031830989 #0.01 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
#soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.001 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Kcna1_md232813') #add channel suffix here
#soma(0.5).ch_Kcna1_md232813.gkcnabar = 0.01 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1

soma.insert('SynE')
soma(0.5).SynE.tauE = 30
soma(0.5).SynE.gnE = 0.000424413
soma(0.5).SynE.eSynE= -10
#soma.insert('iar') #add channel suffix here
#soma(0.5).iar.shift = -6
#soma(0.5).iar.ghbar = 0.0008

#IClamp = h.IClamp(soma(0.5))
#IClamp.delay = 0 #ms
#IClamp.dur =  140 #ms
#IClamp.amp = 0 #1.0 #5 #nA

v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

## RUN SIMULATION
h.finitialize(h.v_init)
# continue sim thru ?140 ms
h.continuerun(140 * ms)

# PLOT RESULTS
import matplotlib.pyplot as plt

plt.figure()
plt.plot(t, v)
plt.xlabel('t (ms)')
plt.ylabel('v (mV)')
plt.show()

###### CFG --- merging NEURON w/ Netpyne organization, transitioning to netpyne ####
#from netpyne import specs, sim
#cfg = specs.SimConfig()					# object of class SimConfig to store simulation configuration
#cfg.duration = 1.5*1e3 #1*1e3 						# Duration of the simulation, in ms
#cfg.dt = 0.02								# Internal integration timestep to use
#cfg.verbose = 1							# Show detailed messages 
#cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
#cfg.recordStep = 0.02 			
#cfg.filename = 'model_output'  			# Set file output name
#cfg.saveJson = True
#cfg.analysis['plotTraces'] = {'include': [0], 'saveFig': True} # Plot recorded traces for this list of cells
#cfg.hParams['celsius'] = 37
#cfg.hParams['v_init'] = -85.7 #-85.3

## Create network and run simulation
#sim.createSimulateAnalyze(netParams = netParams, simConfig = cfg)

