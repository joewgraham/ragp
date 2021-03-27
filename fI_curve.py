from netpyne import specs, sim
from neuron import h
import json
from matplotlib import pyplot as plt
h.load_file("stdrun.hoc")

netParams = specs.NetParams() 


############## POP PARAMS ###########################################################################

# netParams.popParams['CC_pop']= {'cellType': 'CC', 'numCells': 4, 'cellModel': 'HH_reduced'}
# netParams.popParams['CS_pop']= {'cellType': 'CS', 'numCells': 4, 'cellModel': 'HH_reduced'}

netParams.popParams['PV_pop'] = {'cellType': 'PV', 'numCells': 1, 'cellModel': 'HH_reduced'}
#netParams.popParams['VIP_pop'] = {'cellType': 'VIP', 'numCells': 4, 'cellModel': 'HH_reduced'}
#netParams.popParams['SST_pop'] = {'cellType': 'SST', 'numCells': 4, 'cellModel': 'HH_reduced'}



############ LOAD CELL RULES #############################################################################


### PV cells
netParams.loadCellParamsRule(label='PV_reduced', fileName='cells/PV_reduced_cellParams.json')
netParams.cellParams['PV_reduced']['conds'] = {'cellType': 'PV', 'cellModel': 'HH_reduced'} 

### SST cells
#netParams.loadCellParamsRule(label='SOM_reduced', fileName='cells/SOM_reduced_cellParams.json')
#netParams.cellParams['SOM_reduced']['conds'] = {'cellType': 'SOM', 'cellModel': 'HH_reduced'} 

### VIP cells
#netParams.loadCellParamsRule(label='VIP_reduced', fileName='cells/VIP_reduced_cellParams.json')
#netParams.cellParams['VIP_reduced']['conds'] = {'cellType': 'VIP', 'cellModel': 'HH_reduced'} 

### CC cells

### CS cells



######################### MODIFICATION OF ANY PARAMS #########################


############################ Add in Stimulation Source (IClamp) #########################
# Runing the simulation wtih different amplitude values:
current = []
firingRate = []

amp = [0, -0.1, -0.2, -0.25, -0.3, -0.35, -0.4, -0.45, -0.5] #, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8]  # CURRENT INPUTS 
for i, key in enumerate(amp):
    netParams.stimSourceParams['Input'] = {'type': 'IClamp', 'del': 500, 'dur': 1000, 'amp': key}
    netParams.stimTargetParams['Input->PV'] = {'source': 'Input', 'sec':'soma', 'loc': 0.5, 'conds': {'pop':'PV'}}

    #netParams.stimSourceParams[i] = {'type': 'IClamp', 'delay': 500, 'dur': 1000, 'amp': key} 
    #netParams.stimTargetParams[i] = {'source': i, 'conds': {'pop': 'PV2', 'cellList':[ i ]}, 'sec': 'soma', 'loc': 0.5}

    current.append(key)

    cfg = specs.SimConfig()					# object of class SimConfig to store simulation configuration
    cfg.duration = 2*1e3 #1*1e3 						# Duration of the simulation, in ms
    cfg.dt = 0.1								# Internal integration timestep to use
    cfg.verbose = 1							# Show detailed messages 
    cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
    cfg.recordStep = 0.1 			
    cfg.filename = 'model_output'  			# Set file output name
    cfg.saveJson = True
    #cfg.analysis['plotTraces'] = {'include': ['all'], 'oneFigPer': 'trace', 'overlay': 'True', 'saveFig': True} # Plot recorded traces for this list of cells
    cfg.hParams['celsius'] = 20 #24 # 24C for claustrum #37 # SHOULD BE 37C 

    #Run the stimultaion:
    sim.createSimulateAnalyze(netParams = netParams, simConfig = cfg)

    # Firing rate :
    numSpikes = len(sim.simData['spkt']) #float(len(sim.simData['spkt']))
    #numCells = float(len(sim.net.cells))
    #duration = 1 # 1second is true duration 
    netFiring = numSpikes #numSpikes/numCells/duration

    #y axis:
    firingRate.append(netFiring)



#PLot IF curve
plt.plot(current, firingRate, 'bs', linestyle='dashed')
plt.xlabel('Current (nA)')
plt.ylabel('Frequency (Hz)')
# plt.xlim(0, 0.51)
#plt.ylim(0,110)
plt.show()

######################### cfg params ##################################################

# cfg = specs.SimConfig()					# object of class SimConfig to store simulation configuration
# cfg.duration = 2*1e3 #1*1e3 						# Duration of the simulation, in ms
# cfg.dt = 0.1								# Internal integration timestep to use
# cfg.verbose = 1							# Show detailed messages 
# cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
# cfg.recordStep = 0.1 			
# cfg.filename = 'model_output'  			# Set file output name
# cfg.saveJson = True
# #cfg.analysis['plotTraces'] = {'include': ['all'], 'oneFigPer': 'trace', 'overlay': 'True', 'saveFig': True} # Plot recorded traces for this list of cells
# cfg.hParams['celsius'] = 24 # 24C for claustrum #37 # SHOULD BE 37C 

## Create network and run simulation
sim.createSimulateAnalyze(netParams = netParams, simConfig = cfg)