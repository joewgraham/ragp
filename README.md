# Intrinsic Cardiac Nervous System principal neuron model -  NEURON and NetPyNE

mod files are from:
https://senselab.med.yale.edu/ModelDB/ShowModel?model=3800

# Description: 
Code for principle neuron model in (1) NEURON and (2) NetPyNE simulation environemts with graphical output

# Contents
  NEURON: ragp.py\
  NetPyNE: init.py, cfg.py, netParams.py,'example_plot_netpyne.png'\
  NMOD: ‘mod’ folder containing ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod\
 (alt: Files: .py...; Folders: mod, figures)\

# Usage
## Clone repository

## Open a new Terminal window

## Install NEURON
    Enter: pip3 install neuron (also installs NMOD compiler)
    Enter: which nrnivmodl (indicates successful installation of NMOD compiler and points to local compiler)

## Compile mod files 
    Enter: nrnivmodl mod
    
## If NEURON model
### Run simulation
    Enter: ragp.py
### Output
    Plot of voltage (mV) v. time (ms)
    
## If NetPyNE model
### Install NetPyNE
    Enter: pip3 install netpyne
### Run simulation
    Enter: python3 -i init.py -or- ipython init.py 
### Output
    Plot of voltage (mV) v. time (s) is generated and saved as ‘test_plot_netpyne.png’ 

