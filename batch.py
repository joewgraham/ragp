from netpyne import specs
from netpyne.batch import Batch

#def batchTauWeight():

def batchAmp():
        # Create variable of type ordered dictionary (NetPyNE's customized version)
        params = specs.ODict()

        # fill in with parameters to explore and range of values (key has to coincide with a variable in simConfig)
        #params['synMechTau2'] = [3.0, 5.0, 7.0]
        #params['connWeight'] = [0.005, 0.01, 0.15]
        params['amp'] = [0.05, 0.1]
        #params['cellnum'] = range(115)

        # create Batch object with parameters to modify, and specifying files to use
        b = Batch(params=params, cfgFile='cfg.py', netParamsFile='netParams.py',)

        # Set output folder, grid method (all param combinations), and run configuration
        b.batchLabel = 'amp'
        b.saveFolder = 'data'
        b.method = 'grid'
        b.runCfg = {'type': 'mpi_bulletin',
                            'script': 'init.py',
                            'skip': True}

        # Run batch simulations
        b.run()

# Main code
if __name__ == '__main__':
        #batchTauWeight()
        batchAmp()