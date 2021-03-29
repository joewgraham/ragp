# Intrinsic Cardiac Nervous System Neuronal Models
https://senselab.med.yale.edu/ModelDB/, https://channelpedia.epfl.ch/, or literature as cited in code

# Description: 
Code for right atrial ganglionic plexus (RAGP) model in NEURON and Principal Neuron (PN) model in NetPyNE simulation environments\
n.b. - the latter serves as proof-of-principle for creating neuronal models in NetPyNE

# Contents
## Code:
  NEURON (RAGP model): ion_channel_models.py, TBD\
  NetPyNE (PN model): init.py, cfg.py, netParams.py\
  Analysis: TBD
## NMOD:
  'genemods' folder for RAGP model with mod files for ion channels selected from transcriptomic data\
  ‘mod’ folder for PN model with ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod
# Usage
## Open a new Terminal window
## Clone repository
## Install NEURON
    pip3 install neuron  
### Confirm installation and location of NMOD compiler
     which nrnivmodl 
## Compile mod files (PN or RAGP)
     nrnivmodl mod
### or
     nrnivmodl genemods 
        
## If NEURON model (RAGP)
### Run a simulation
    python3 -i ion_channel_models.py
#### Output
    1x3 figure of subplots showing voltage (mV) v. time (ms) for transcriptomic models cell_L, cell_Mid, and
    cell_R, respectively\
    n.b.: Conductance of Nav1.1 set to 1.0 S/cm2, IClamp amp set to 0.03 nA for demonstrative purposes
### Run simulation analysis with multiple conductances and/or current (nA) values for any number of genemod files
    TBD 
#### Output
    Figure of m genes x n conductance values, with subplots showing of voltage (mV) v. time (ms) for 1 or more input amps (nA)
    
## If NetPyNE model (PN)
### Install NetPyNE
    pip3 install netpyne
### Run a simulation
    python3 -i init.py
### Output
    Plot of voltage (mV) v. time (ms)
