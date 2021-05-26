from netpyne import specs, sim
import scipy.io as sio 
import numpy as np
import csv

try:
    from __main__ import cfg  # import SimConfig object with params from parent module
except:
    from cfg import cfg  # if no simConfig in parent module, import directly from cfg module

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters

## LOAD ALL CELL TYPES
#from csv
cellnum = 53
cell_identities = np.int_(np.transpose(np.genfromtxt('allcells_new12_unique_binary.csv', delimiter=',')))
cell = cell_identities[cellnum]

# order in genemod MUST be preserved to match cell_identities channel order
genemod = {'ch_Cacna1a_cp5':{'gCav2_1bar': 0.00001},  'ch_Cacna1b_cp6':{'gCav2_2bar': 0.0001},
           'ch_Cacna1c_cp3':{'gLbar': 0.0001},        'ch_Cacna1g_cp41':{'gCav3_1bar': 0.00001},
           'ch_Cacna1i_cp42':{'gCav3_3bar': 0.0001},  'ch_Hcn1_cp9':{'gHCN1bar': 0.00001},
           'ch_Hcn2_cp10':{'gHCN2bar': 0.010},           'ch_Hcn3_cp11':{'gHCN3bar': 0.00001},
           'ch_Hcn4_cp12':{'gHCN4bar': 0.001},           'ch_Kcna1ab1_md80769':{'gbar': 0.015},
           'ch_Kcnc1_md74298':{'gk': 0.015},            'ch_Scn1a_md264834':{'gNav11bar': 2.0}}

# for i, j in zip(cell,genemod):
#     genemod[j]=i*list(genemod[j].values())

## Cell parameters/rules
CEL = {'secs': {}}
CEL['secs']['soma'] = {'geom': {}, 'mechs': {}}  # soma params dict
CEL['secs']['soma']['geom'] = {'diam': 30, 'L': 30, 'Ra': 35.4, 'cm':1}  # soma geometry
CEL['secs']['soma']['mechs']['pas'] = {'g': 1.8e-6, 'e': -65}
netParams.cellParams['CEL'] = CEL

## Population parameters
netParams.popParams['S'] = {'cellType': 'CEL', 'numCells': 20}
netParams.popParams['M'] = {'cellType': 'CEL', 'numCells': 20}

## Synaptic mechanism parameters
netParams.synMechParams['exc'] = {'mod': 'Exp2Syn', 'tau1': 0.1, 'tau2': cfg.synMechTau2, 'e': 0}  # excitatory synaptic mechanism

# Stimulation parameters
netParams.stimSourceParams['bkg'] = {'type': 'NetStim', 'rate': 10, 'noise': 0.5}
netParams.stimTargetParams['bkg->CEL'] = {'source': 'bkg', 'conds': {'cellType': 'PYR'}, 'weight': 0.01, 'delay': 5, 'synMech': 'exc'}

## Cell connectivity rules
netParams.connParams['S->M'] = {    #  S -> M label
    'preConds': {'pop': 'S'},       # conditions of presyn cells
    'postConds': {'pop': 'M'},      # conditions of postsyn cells
    'probability': 0.5,             # probability of connection
    'weight': cfg.connWeight,       # synaptic weight
    'delay': 5,                     # transmission delay (ms)
    'synMech': 'exc'}               # synaptic mechanism
