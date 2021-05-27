from netpyne import sim

simConfig, netParams = sim.readCmdLineArgs(simConfigDefault='cfg.py', netParamsDefault='netParams.py')
sim.create()
sim.simulate()
sim.analyze()

