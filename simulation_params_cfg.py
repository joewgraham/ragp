###############################################################################
# SIMULATION PARAMETERS
###############################################################################

# Simulation parameters
simConfig.duration = 1*1e3 # Duration of the simulation, in ms
simConfig.dt = 0.1 # Internal integration timestep to use
simConfig.createNEURONObj = 1  # create HOC objects when instantiating network
simConfig.createPyStruct = 1  # create Python structure (simulator-independent) when instantiating network
simConfig.verbose = False  # show detailed messages

# Recording
simConfig.recordTraces = {'Vsoma':{'sec':'soma','loc':0.5,'var':'v'}}

# # Analysis and plotting
simConfig.analysis['plotRaster'] = {'orderInverse': True, 'saveFig': True}


###############################################################################
# RUN SIM
###############################################################################

sim.createSimulateAnalyze()