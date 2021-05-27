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
cell_identities = np.bool_(np.transpose(np.genfromtxt('allcells_new12_unique_binary.csv', delimiter=',')))
cell = cell_identities[cellnum]

# order in genemod MUST be preserved to match cell_identities channel order
genemod = {'ch_Cacna1a_cp5':{'gCav2_1bar': 0.00001},  'ch_Cacna1b_cp6':{'gCav2_2bar': 0.0001},
           'ch_Cacna1c_cp3':{'gLbar': 0.0001},        'ch_Cacna1g_cp41':{'gCav3_1bar': 0.00001},
           'ch_Cacna1i_cp42':{'gCav3_3bar': 0.0001},  'ch_Hcn1_cp9':{'gHCN1bar': 0.00001},
           'ch_Hcn2_cp10':{'gHCN2bar': 0.010},           'ch_Hcn3_cp11':{'gHCN3bar': 0.00001},
           'ch_Hcn4_cp12':{'gHCN4bar': 0.001},           'ch_Kcna1ab1_md80769':{'gbar': 0.015},
           'ch_Kcnc1_md74298':{'gk': 0.015},            'ch_Scn1a_md264834':{'gNav11bar': 1.0}}


## Cell parameters/rules
CEL = {'secs': {}}
CEL['secs']['soma'] = {'geom': {}, 'mechs': {}}  # soma params dict
CEL['secs']['soma']['geom'] = {'diam': 30, 'L': 30, 'Ra': 35.4, 'cm':1}  # soma geometry
CEL['secs']['soma']['mechs']['pas'] = {'g': 1.8e-6, 'e': -65}


for mod,onoff in zip(genemod,cell):
      if onoff == 1:
          CEL['secs']['soma']['mechs'][mod]=genemod[mod]


netParams.cellParams['CEL'] = CEL

## Population parameters
netParams.popParams['U'] = {'cellType': 'CEL', 'numCells': 1}

#------------------------------------------------------------------------------
# Current inputs (IClamp)
#------------------------------------------------------------------------------
if cfg.addIClamp:
    for key in [k for k in dir(cfg) if k.startswith('IClamp')]:
        params = getattr(cfg, key, None)
        [pop,sec,loc,start,dur,cfg.amp] = [params[s] for s in ['pop','sec','loc','start','dur','amp']]

        #cfg.analysis['plotTraces']['include'].append((pop,0))  # record that pop

        # add stim source
        # netParams.stimSourceParams[key] = {'type': 'IClamp', 'delay': start, 'dur': dur, 'amp': amp}
        netParams.stimSourceParams[key] = { 'type': 'IClamp', 
                                            'delay': cfg.startStimTime if cfg.startStimTime is not None else start, 
                                            'dur': cfg.stimDur if cfg.stimDur is not None else dur, 
                                            'amp': cfg.amp} #if cfg.amp is not None else amp}
        
        # connect stim source to target
        netParams.stimTargetParams[key+'_'+pop] =  {
            'source': key, 
            'conds': {'pop': pop},
            'sec': sec, 
            'loc': loc}