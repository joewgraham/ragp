# Intrinsic Cardiac Nervous System principal neuron model -  NEURON and NetPyNE

The mod files are from here:
https://senselab.med.yale.edu/ModelDB/ShowModel?model=3800

# Description: 
Code for principle neuron model in (1) NEURON and (2) NetPyNE simulation environemts with graphical output

# Contents
  NetPyNE: init.py, cfg.py, netParams.py,'example_plot_netpyne.png'
  NEURON: ragp.py
  NMOD: ‘mod’ folder containing ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod
 (alt: Files: .py...; Folders: mod, figures)

# Usage
## Clone repository

## Open a new Terminal window

## Install NEURON
    Enter: pip3 install neuron (This will also install the NMOD compiler)
    Enter: which nrnivmodl (This will indicate successful installation of NMOD compiler - should point to local compiler)

## Compile mod files 
    Enter: nrnivmodl mod
    
## NEURON model
### Run simulation
    Enter: ragp.py
### Output
    Plot of voltage (mV) v. time (ms)
    
## NetPyNE model
### Install NetPyNE
    Enter: pip3 install netpyne
### Run simulation
    Enter: python3 -i init.py or ipython init.py 
### Output
    Plot of voltage (mV) v. time (s) is generated and saved as ‘test_plot_netpyne.png’ 

