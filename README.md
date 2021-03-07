# Intrinsic Cardiac Nervous System Principal Neuron Model -  NEURON and NetPyNE

mod files are from:
https://senselab.med.yale.edu/ModelDB/ShowModel?model=3800 and https://channelpedia.epfl.ch/

# Description: 
Code for Principle Neuron model in either NEURON or NetPyNE simulation environments

# Contents
## Code:
  NEURON: ragp.py, extremes.py, middle_genes_test.py
  NetPyNE: init.py, cfg.py, netParams.py
## NMOD:
  ‘mod’ folder with ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod
  'genemods' folder with mod files for ion channels selected from transcriptomic data. Note not all are used in each single neuron model

# Usage
## Open a new Terminal window
## Clone repository
## Install NEURON
    pip3 install neuron  
### Confirm installation and location of NMOD compiler
     which nrnivmodl 
## Compile mod files
    nrnivmodl mod
### or
    nrnivmodl genemods 
        
## If NEURON model
### Run a simulation
    Variations of PN model: python3 -i ragp.py, python3 -i extremes.py, python3 -i middle_genes_test.py
#### Output
    Plot of voltage (mV) v. time (ms)
### Run a simulation with multiple conductances and/or current (nA) values for any number of genemod files
    python -i ragpy-amplitudes.py
#### Output
    n genes x m conductance values, plots of voltage (mV) v. time (ms)
### Run a simulation generating m, h, n tau and inf values for a given neuron model
    python3 -i XXXXXX.py
    
## If NetPyNE model
### Install NetPyNE
    pip3 install netpyne
### Run a simulation
    python3 -i init.py
### Output
    Plot of voltage (mV) v. time (ms)
