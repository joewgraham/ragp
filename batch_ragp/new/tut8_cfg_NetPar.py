from netpyne import specs

# Simulation options
cfg = specs.SimConfig()     # object of class SimConfig to store simulation configuration

cfg.duration = 1*1e3        # Duration of the simulation, in ms
cfg.dt = 0.025              # Internal integration timestep to use
cfg.verbose = False         # Show detailed messages
cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
cfg.recordStep = 0.1        # Step size in ms to save data (eg. V traces, LFP, etc)
cfg.filename = 'tut8'       # Set file output name
cfg.saveJson = True
cfg.printPopAvgRates = True
cfg.analysis['plotRaster'] = {'saveFig': True}                   # Plot a raster
# cfg.analysis['plotTraces'] = {'include': [0], 'saveFig': True}  # Plot recorded traces for this list of cells
cfg.analysis['plot2Dnet']   = { 'saveFig': True}

cfg.saveDataInclude = ['simData', 'simConfig', 'netParams', 'net']

# Variable parameters (used in netParams)
cfg.synMechTau2 = 5
cfg.connWeight = 0.01

cfg.conProb=0.5
cfg.connDelay=5
cfg.synMech='exc'

#------------------------------------------------------------------------------
# Targeted NetStim inputs 
#------------------------------------------------------------------------------
cfg.addTargetedNetStim=True
if cfg.addTargetedNetStim:
    
    cfg.startStimTime=200
    cfg.synMech = 'exc'
    cfg.stimPop = None
    cfg.numStims    = 200
    cfg.netWeight   = 0.1
    cfg.interStimInterval=15

    cfg.TargetedNetStim00= { 
                        'pop':              'S', 
                        'ynorm':            [0,1], 
                        'sec':              'soma', 
                        'loc':              0.5, 
                        'synMech':          'exc', 
                        'synMechWeightFactor': [1.0],
                        'start':            200, 
                        'interval':         cfg.interStimInterval, 
                        'noise':            1, 
                        'number':           cfg.numStims, 
                        'weight':           cfg.netWeight, 
                        'delay':            0,
                        'targetCells':      [0, 2, 5, 10, 15]
                        }

