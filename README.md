# Intrinsic Cardiac Nervous System Principal Neuron Model -  NEURON and NetPyNE

mod files are from:
https://senselab.med.yale.edu/ModelDB/ShowModel?model=3800, https://channelpedia.epfl.ch/

# Description: 
Code for Principle Neuron model in either NEURON or NetPyNE simulation environments

# Contents
## Code:
  NEURON: ragp.py, middle_heatmap_genes.py (contains all ion channels currently used in models -- comment out prn), extremes.py (L heatmap)\
  NetPyNE: init.py, cfg.py, netParams.py\
  Analyis: ragp-amplitudes.py, parameter_plot_corrected.py
## NMOD:
  ‘mod’ folder with ahp.mod, cabuff.mod, cal.mod, can.mod, kaar.mod, kdr.mod, naf.mod, SynE.mod\
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
    Variations of PN model: python3 -i extremes.py (alt: ipython -i extremes.py), python3 -i middle_heatmap_genes.py
#### Output
    Plot of voltage (mV) v. time (ms)
### Run simulation analysis with multiple conductances and/or current (nA) values for any number of genemod files
    python -i ragp-amplitudes.py
#### Output
    m genes x n conductance values, plots of voltage (mV) v. time (ms)
### Run simulation analysis generating m, h, n tau and inf values for a given neuron model
    python3 -i plot_parameters_corrected.py
    
## If NetPyNE model
### Install NetPyNE
    pip3 install netpyne
### Run a simulation
    python3 -i init.py
### Output
    Plot of voltage (mV) v. time (ms)
