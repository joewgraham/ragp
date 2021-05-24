from netpyne import specs
from netpyne.batch import Batch

def changeIClamp():
        # Create variable of type ordered dictionary (NetPyNE's customized version)
        params = specs.ODict()

        # fill in with parameters to explore and range of values (key has to coincide with a variable in simConfig)
        params['amp']=[0.05, 0.1] # 0.2, 0.4, 0.6]
       # params['amp']=[10, 100, 200, 400]
        # params['startStimTime'] = [0, 100, 200]

        # create Batch object with parameters to modify, and specifying files to use
        b = Batch(params=params, cfgFile='cfg_IClamp.py', netParamsFile='netParams_IClamp.py',)

        # Set output folder, grid method (all param combinations), and run configuration
        b.batchLabel = 'IClamp'
        b.saveFolder = 'tut8_data_IClamp'
        b.method = 'grid'
        b.runCfg = {'type': 'mpi_bulletin',
                            'script': 'init.py',
                            'skip': True}

        # Run batch simulations
        b.run()

def changeCellParameters():
        # Create variable of type ordered dictionary (NetPyNE's customized version)
        params = specs.ODict()

        # fill in with parameters to explore and range of values (key has to coincide with a variable in simConfig)
        params['eLeak'] = [-90, -80, -70, -60]
        # params['gnaBar'] = [0.12, 0.5, 1.0]
        # params['gkBar'] = [0.036,0.2,0.5]
        # params['gL']=[0.001, 0.003, 0.01]
        # params['Ra']=[50, 123, 250, 500]
        # params['dimension']=[1, 10, 18, 50]

        # create Batch object with parameters to modify, and specifying files to use
        b = Batch(params=params, cfgFile='cfg_CellParams.py', netParamsFile='netParams_CellParams.py',)

        # Set output folder, grid method (all param combinations), and run configuration
        b.batchLabel = 'CellParams'
        b.saveFolder = 'data_CellParams'
        b.method = 'grid'
        b.runCfg = {'type': 'mpi_bulletin',
                            'script': 'init.py',
                            'skip': True}

        # Run batch simulations
        b.run()

# Main code
if __name__ == '__main__':
        changeIClamp()
        # changeNetStims()
        # changeCellParameters()
        # changeNetworkParameters()