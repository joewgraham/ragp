# Intrinsic Cardiac Nervous System Principal Neuron Model -  NEURON and NetPyNE

mod files are from:
https://senselab.med.yale.edu/ModelDB/ShowModel?model=3800

# Description: 
Code for Principle Neuron model in either NEURON or NetPyNE simulation environments

# Contents
## Code:
  NEURON: ragp.py\
  NetPyNE: init.py, cfg.py, netParams.py
## NMOD:
  ‘mod’ folder with ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod
## Figures:
  'images' folder with example plots (example_plot_netpyne.png) and dir for saved output figures

# Usage
## Open a new Terminal window
## Clone repository
## Install NEURON
    pip3 install neuron  
### Confirm installation and location of NMOD compiler
     which nrnivmodl 
## Compile mod files
    nrnivmodl mod
    
    
## If NEURON model
### Run a simulation
    python3 -i ragp.py
### Output
   Plot of voltage (mV) v. time (ms)
    
    
## If NetPyNE model
### Install NetPyNE
    pip3 install netpyne
### Run a simulation
    python3 -i init.py
### Output
   Plot of voltage (mV) v. time (ms)
