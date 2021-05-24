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
cfg.analysis['plotTraces'] = {'include': [0], 'saveFig': True}  # Plot recorded traces for this list of cells

cfg.saveDataInclude = ['simData', 'simConfig', 'netParams', 'net']

# Variable parameters (used in netParams)
cfg.synMechTau2 = 5
cfg.connWeight = 0.01



#------------------------------------------------------------------------------
# Current inputs 
#------------------------------------------------------------------------------
cfg.addIClamp=False
if cfg.addIClamp:
    cfg.startStimTime = 500
    cfg.clampAmplitude=0.2
    cfg.stimDur=500
    
    cfg.IClamp0 = { 'pop': 'S', 'sec': 'soma', 'loc': 0.5, 'start': 400, 'dur': 100, 'amp': cfg.clampAmplitude}

cfg.addPreIClamp = False
if cfg.addPreIClamp:
    cfg.startStimTime = 0
    cfg.stimDur_pre = None
    cfg.clampAmplitude_pre = -0.1

    cfg.PreIClamp0 = { 'pop': 'S', 'sec': 'soma', 'loc': 0.5, 'start': 400, 'dur': 150, 'amp': cfg.clampAmplitude_pre}
    
#------------------------------------------------------------------------------
# NetStim inputs 
#------------------------------------------------------------------------------
cfg.addNetStim=True
if cfg.addNetStim:
    
    cfg.numStims    = 200
    cfg.netWeight   = 0.1
    cfg.startStimTime = 200
    cfg.interStimInterval=15

    cfg.NetStim1    = { 'pop':              'S', 
                        'ynorm':            [0,1], 
                        'sec':              'soma', 
                        'loc':              0.5, 
                        'synMech':          'exc', 
                        'synMechWeightFactor': [1.0],
                        'start':            cfg.startStimTime, 
                        'interval':         cfg.interStimInterval, 
                        'noise':            1, 
                        'number':           cfg.numStims, 
                        'weight':           cfg.netWeight, 
                        'delay':            0}

#------------------------------------------------------------------------------
# Targeted NetStim inputs 
#------------------------------------------------------------------------------
cfg.addTargetedNetStim=False
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

#------------------------------------------------------------------------------
# GroupNetStim inputs
#------------------------------------------------------------------------------
cfg.addGroupNetStim = False
if cfg.addGroupNetStim:
    cfg.groupWeight = 0.1
    cfg.groupRate = 1000/cfg.interStimInterval

    cfg.GroupNetStimW1  = { 'nstype':       'pop', 
                            'numStims':     200, 
                            'pop':          'S', 
                            'ynorm':        [0,1], 
                            # 'cellRule':     'CT5A_reduced', 
                            'secList':      'soma', 
                            'allSegs':      True, \
                            'synMech':      'exc', 
                            'start':        500, 
                            'interval':     1000/cfg.groupRate, 
                            'noise':        0.6, 
                            'number':       1, 
                            'weight':       cfg.groupWeight , 
                            'delay':        0}