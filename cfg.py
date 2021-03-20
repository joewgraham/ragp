from netpyne import specs, sim


# Simulation options
cfg = specs.SimConfig()       # object of class cfg to store simulation configuration

cfg.hParams = {'celsius': 35, 'v_init': -61} #, 'clamp_resist': 0.001}
cfg.duration = 0.025          # 500;5000 for v_init; Duration of the simulation, in ms
cfg.dt = 0.025                # Internal integration timestep to use
cfg.verbose = False           # Show detailed messages 
cfg.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}
#cfg.recordTraces['iScn'] = {'sec':'soma','loc':0.5,'var':'ina_ch_Scn1a_md264834'}
#cfg.recordTraces['iKcnc'] = {'sec':'soma','loc':0.5,'var':'ik'}


cfg.recordStep = 0.025           # Step size in ms to save data (eg. V traces, LFP, etc)
cfg.filename = 'ragpq3'         # Set file output name
cfg.savePickle = False        # Save params, network and sim output to pickle file

cfg.analysis['plotTraces'] = {'include': [0, 1, 2], 'saveFig': True}  # Plot recorded traces for this list of cells

