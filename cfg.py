from netpyne import specs, sim


# Simulation options
cfg = specs.SimConfig()       # object of class cfg to store simulation configuration

cfg.hParams = {'celsius': 37, 'v_init': -64.5} #, 'clamp_resist': 0.001}
cfg.duration = 1         # Duration of the simulation, in SEC
cfg.dt = 0.00025                # Internal integration timestep to use
cfg.verbose = True           # Show detailed messages 
cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}
cfg.recordStep = 0.00025          # Step size in SEC to save data (eg. V traces, LFP, etc)
#cfg.filename = 'ragp_' + ''         # Set file output name. Set fname here - should agree w/ what's in database
#cfg.savePickle = False        # Save params, network and sim output to pickle file

cfg.analysis['plotTraces'] = {'include': [0, 1, 2], 'saveFig': True}  # Plot recorded traces for this list of cells
