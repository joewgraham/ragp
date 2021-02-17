from neuron import h
from neuron.units import ms, mV

h.load_file('stdrun.hoc')
h.v_init = -60*mV			#need to revisit - is it -44.5 mV?

soma = h.Section(name='soma')
soma.L, soma.diam,soma.nseg = 30, 30, 1
soma.cm = 1


# leak channel
soma.insert('pas')
soma(0.5).pas.e = -72
soma(0.5).pas.g = 0.001

#soma.insert('ch_Cacna1b_cp6') #add channel suffix here
#soma(0.5).ch_Cacna1b_cp6.gCav2_2bar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Cacna1c_cp3') #add channel suffix here
#soma(0.5).ch_Cacna1c_cp3.gLbar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Cacna1i_cp42') #add channel suffix here
#soma(0.5).ch_Cacna1i_cp42.gCav3_3bar = 1e-2 #1e-4 #1e-3 #1e-2 #1e-1 #1

#soma.insert('ch_Scn1a_cp35') #add channel suffix here
#soma(0.5).ch_Scn1a_cp35.gNabar = 1e-1 #1e-4 #1e-3 #1e-2 #1e-1 #1

soma.insert('Naf')
soma(0.5).Naf.gNabar = 0.106103295 *0.25

soma.insert('ch_Kcnc1_md74298') #add channel suffix here
soma(0.5).ch_Kcnc1_md74298.gk = 0.01 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Kcna1ab1_md80769') #add channel suffix here
#soma(0.5).ch_Kcna1ab1_md80769.gbar = 0.001 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1
#soma.insert('ch_Kcna1_md232813') #add channel suffix here
#soma(0.5).ch_Kcna1_md232813.gkcnabar = 0.01 #1e-5 #1e-4 #1e-3 #1e-2 #1e-1 #1

#soma.insert('iar') #add channel suffix here
#soma(0.5).iar.shift = -6
#soma(0.5).iar.ghbar = 0.0008

iclamp = h.IClamp(soma(0.5))
iclamp.delay = 5 #ms
iclamp.dur =  140 #ms
iclamp.amp = 2 #1.0 #5 #nA

v = h.Vector().record(soma(0.5)._ref_v)             # membrane potential vector
t = h.Vector().record(h._ref_t)                     # timestamp vector

## RUN SIMULATION
h.finitialize()
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

