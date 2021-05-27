from netpyne import specs
from netpyne.batch import Batch

def batch():
        params = specs.ODict()
        params['amp'] = [0.05, 0.1]
        params['cellnum'] = [3, 53, 101] # [x for x in range(115)]
        b = Batch(params=params, cfgFile='cfg.py', netParamsFile='netParams.py',)
        # Set output folder, grid method (all param combinations), and run configuration
        b.batchLabel = '21may27a'
        b.saveFolder = 'data'
        b.method = 'grid'
        b.runCfg = {'type': 'mpi_bulletin', 'script': 'init.py', 'skip': True}
        b.run()

batch()
