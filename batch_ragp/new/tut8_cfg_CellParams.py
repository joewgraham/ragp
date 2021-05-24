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
cfg.analysis['plotTraces'] = {'include': [0], 'ylim': [-95, 60], 'saveFig': True}  # Plot recorded traces for this list of cells

cfg.saveDataInclude = ['simData', 'simConfig', 'netParams', 'net']

# Variable parameters (used in netParams)
cfg.synMechTau2 = 5
cfg.connWeight = 0.01

cfg.dimension   = 18.8
cfg.Ra          = 123.0
cfg.gnaBar      = 0.12
cfg.gkBar       = 0.036
cfg.gL          = 0.003
cfg.eLeak       = -70

#------------------------------------------------------------------------------
# Current inputs 
#------------------------------------------------------------------------------
cfg.addIClamp=True
if cfg.addIClamp:
    cfg.startStimTime = 500
    cfg.clampAmplitude=0.2
    cfg.stimDur=500
    
    cfg.IClamp0 = { 'pop': 'S', 'sec': 'soma', 'loc': 0.5, 'start': 200, 'dur': 400, 'amp': cfg.clampAmplitude}
