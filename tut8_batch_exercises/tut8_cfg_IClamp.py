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
# cfg.analysis['plotRaster'] = {'saveFig': True}                   # Plot a raster
cfg.analysis['plotTraces'] = {'include': [0], 'ylim': [-85, 60], 'saveFig': True}  # Plot recorded traces for this list of cells

cfg.saveDataInclude = ['simData', 'simConfig', 'netParams', 'net']

# Variable parameters (used in netParams)
cfg.synMechTau2 = 5
cfg.connWeight = 0.01

#------------------------------------------------------------------------------
# Current inputs 
#------------------------------------------------------------------------------
cfg.addIClamp=True
if cfg.addIClamp:
    cfg.startStimTime = 500
    cfg.clampAmplitude=0.2
    cfg.stimDur=100
    
    cfg.IClamp0 = { 'pop': 'S', 'sec': 'soma', 'loc': 0.5, 'start': cfg.startStimTime, 'dur': cfg.stimDur, 'amp': cfg.clampAmplitude}

cfg.addPreIClamp = False
if cfg.addPreIClamp:
    cfg.startStimTime = 0
    cfg.stimDur_pre = None
    cfg.clampAmplitude_pre = -0.1

    cfg.PreIClamp0 = { 'pop': 'S', 'sec': 'soma', 'loc': 0.5, 'start': 400, 'dur': 150, 'amp': cfg.clampAmplitude_pre}
    