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

# gEdictnp = {'v':sim.net.cells[0].secs.soma.hObj(0.5).v, 'ina':sim.net.cells[0].secs.soma.hObj(0.5).ina, 'ik':sim.net.cells[0].secs.soma.hObj(0.5).ik, 'ica':sim.net.cells[0].secs.soma.hObj(0.5).ica, 'ena':sim.net.cells[0].secs.soma.hObj(0.5).ena, 'ek':sim.net.cells[0].secs.soma.hObj(0.5).ek, 'eca':sim.net.cells[0].secs.soma.hObj(0.5).eca, 'epas':sim.net.cells[0].secs.soma.hObj(0.5).pas.e, 'gpas':sim.net.cells[0].secs.soma.hObj(0.5).pas.g, 'gNa':sim.net.cells[0].secs.soma.hObj(0.5).ch_Scn1a_md264834.gNav11, 'gKcnc':sim.net.cells[0].secs.soma.hObj(0.5).ch_Kcnc1_md74298.gkcnc, 'gKcna':sim.net.cells[0].secs.soma.hObj(0.5).ch_Kcna1ab1_md80769.gk,'gHcn2':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn2_cp10.gHCN2, 'gHcn4':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn4_cp12.gHCN4, 'gCa1b':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1b_cp6.gCav2_2, 'gCa1c':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1c_cp3.gL, 'gCan1i':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1i_cp42.gCav3_3}
# print(gEdictnp)

# filenp = open('gEdump.csv','a')
# cwnp = csv.DictWriter(filenp)
# cwnp.writerow(gEdictnp)
# filenp.close()
