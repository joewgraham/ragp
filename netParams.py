from netpyne import specs, sim
import scipy.io as sio 
import array
import numpy

try:
    from __main__ import cfg  # import SimConfig object with params from parent module
except:
    from cfg import cfg  # if no simConfig in parent module, import directly from cfg module

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters

## LOAD ALL CELL TYPES
# from mat file
cell_identities = numpy.transpose(sio.loadmat('all_cellTypes.mat')['allcells_new12_unique_binary'])


## Cell parameters/rules
PYRcell = {'secs': {}}
PYRcell['secs']['soma'] = {'geom': {}, 'mechs': {}}  # soma params dict
PYRcell['secs']['soma']['geom'] = {'diam': 30, 'L': 30, 'Ra': 35.4, 'cm':1}  # soma geometry

genemod = {'Cacna1a':'ch_Cacna1a_md229585','Cacna1b':'ch_Cacna1b_cp6','Cacna1c':'ch_Cacna1c_cp3','Cacna1g':'ch_Cacna1g_md229585','Cacna1i':'ch_Cacna1i_cp42','Hcn1':'ch_Hcn1_cp9','Hcn2':'ch_Hcn2_cp10','Hcn3':'ch_Hcn3_cp11','Hcn4':'ch_Hcn4_cp12','Kcna1b1':'ch_Kcna1ab1_md80769','Kcnc1':'ch_Kcnc1_md74298','Scn1a':'ch_Scn1a_md264834'}


# 'ch_Cacna1a_cp5'
# 'ch_Cacna1a_md229585'
# 'ch_Cacna1g_cp41'
# 'ch_Cacna1g_md229585'
# 'ch_Hcn1_cp9'
# 'ch_Hcn1_md229585'

# PYRcell['secs']['soma']['mechs']['pas'] = {'g': 1.8e-6, 'e': -65} 	
# PYRcell['secs']['soma']['mechs']['ch_Cacna1b_cp6'] = {'gCav2_2bar': 0.0001} 
# PYRcell['secs']['soma']['mechs']['ch_Cacna1c_cp3'] = {'gLbar': 0.0001} 		
# PYRcell['secs']['soma']['mechs']['ch_Cacna1i_cp42'] = {'gCav3_3bar': 0.0001} 		
# PYRcell['secs']['soma']['mechs']['ch_Scn1a_md264834'] = {'gNav11bar': 2.0} 	# 0.00001
# PYRcell['secs']['soma']['mechs']['ch_Hcn2_cp10'] = {'gHCN2bar': 0.010}		
# PYRcell['secs']['soma']['mechs']['ch_Hcn4_cp12'] = {'gHCN4bar': 0.001}		
# PYRcell['secs']['soma']['mechs']['ch_Kcnc1_md74298'] = {'gk': 0.015} 		
# PYRcell['secs']['soma']['mechs']['ch_Kcna1ab1_md80769'] = {'gbar': 0.015} 

netParams.cellParams['PYR'] = PYRcell

## Population parameters
netParams.popParams['S'] = {'cellType': 'PYR', 'numCells': 20}
netParams.popParams['M'] = {'cellType': 'PYR', 'numCells': 20}

## Synaptic mechanism parameters
netParams.synMechParams['exc'] = {'mod': 'Exp2Syn', 'tau1': 0.1, 'tau2': cfg.synMechTau2, 'e': 0}  # excitatory synaptic mechanism

# Stimulation parameters
netParams.stimSourceParams['bkg'] = {'type': 'NetStim', 'rate': 10, 'noise': 0.5}
netParams.stimTargetParams['bkg->PYR'] = {'source': 'bkg', 'conds': {'cellType': 'PYR'}, 'weight': 0.01, 'delay': 5, 'synMech': 'exc'}

## Cell connectivity rules
netParams.connParams['S->M'] = {    #  S -> M label
    'preConds': {'pop': 'S'},       # conditions of presyn cells
    'postConds': {'pop': 'M'},      # conditions of postsyn cells
    'probability': 0.5,             # probability of connection
    'weight': cfg.connWeight,       # synaptic weight
    'delay': 5,                     # transmission delay (ms)
    'synMech': 'exc'}               # synaptic mechanism
