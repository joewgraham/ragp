from netpyne import specs

# Simulation options
cfg = specs.SimConfig()     # object of class SimConfig to store simulation configuration

cfg.duration = 500#1*1e3        # Duration of the simulation, in ms
cfg.tstop = 500
cfg.dt = 0.025              # Internal integration timestep to use
cfg.verbose = False         # Show detailed messages
cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
cfg.recordStep = 0.1        # Step size in ms to save data (eg. V traces, LFP, etc)
cfg.filename = 'output'       # Set file output name
cfg.saveJson = True
cfg.savePickle = True
cfg.printPopAvgRates = True
cfg.analysis['plotRaster'] = {'saveFig': True}                   # Plot a raster
cfg.analysis['plotTraces'] = {'include': [0], 'saveFig': True}  # Plot recorded traces for this list of cells

cfg.saveDataInclude = ['simData', 'simConfig', 'netParams', 'net']

cfg.hParams = {}
# Variable parameters (used in netParams)quit
#cfg.synMechTau2 = 5
#cfg.connWeight = 0.01
#------------------------------------------------------------------------------
# Current inputs 
#------------------------------------------------------------------------------
cfg.addIClamp=True
if cfg.addIClamp:
    cfg.startStimTime = 50
    cfg.amp=0.1
    cfg.stimDur=200
    
    cfg.IClamp0 = { 'pop': 'U', 'sec': 'soma', 'loc': 0.5, 'start': cfg.startStimTime, 'dur': cfg.stimDur, 'amp': cfg.amp}