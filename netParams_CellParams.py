from netpyne import specs, sim

try:
    from __main__ import cfg  # import SimConfig object with params from parent module
except:
    from tut8_cfg_CellParams import cfg  # if no simConfig in parent module, import directly from tut8_cfg module

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters

## Cell parameters/rules
PYRcell = {'secs': {}}
PYRcell['secs']['soma'] = {'geom': {}, 'mechs': {}}  # soma params dict
PYRcell['secs']['soma']['geom'] = {'diam': cfg.dimension, 'L': cfg.dimension, 'Ra': cfg.Ra}  # soma geometry
PYRcell['secs']['soma']['mechs']['hh'] = {'gnabar': cfg.gnaBar, 'gkbar': cfg.gkBar, 'gl': cfg.gL, 'el': cfg.eLeak}  # soma hh mechanism
netParams.cellParams['PYR'] = PYRcell

## Population parameters
netParams.popParams['S'] = {'cellType': 'PYR', 'numCells': 20}
netParams.popParams['M'] = {'cellType': 'PYR', 'numCells': 20}

## Synaptic mechanism parameters
netParams.synMechParams['exc'] = {'mod': 'Exp2Syn', 'tau1': 0.1, 'tau2': cfg.synMechTau2, 'e': 0}  # excitatory synaptic mechanism
netParams.synMechParams['inh'] = {'mod': 'Exp2Syn', 'tau1': 0.1, 'tau2': cfg.synMechTau2, 'e': -80}  # excitatory synaptic mechanism

# Stimulation parameters
# netParams.stimSourceParams['bkg'] = {'type': 'NetStim', 'rate': 10, 'noise': 0.5}
# netParams.stimTargetParams['bkg->PYR'] = {'source': 'bkg', 'conds': {'cellType': 'PYR'}, 'weight': 0.01, 'delay': 5, 'synMech': 'exc'}

## Cell connectivity rules
netParams.connParams['S->M'] = {    #  S -> M label
    'preConds': {'pop': 'S'},       # conditions of presyn cells
    'postConds': {'pop': 'M'},      # conditions of postsyn cells
    'probability': 0.5,             # probability of connection
    'weight': cfg.connWeight,       # synaptic weight
    'delay': 5,                     # transmission delay (ms)
    'synMech': 'exc'}               # synaptic mechanism

#------------------------------------------------------------------------------
# Synaptic mechanism parameters
#------------------------------------------------------------------------------
# # excitatory synapses
# netParams.synMechParams['NMDA']             = {'mod': 'MyExp2SynNMDABB',    'tau1NMDA': 15, 'tau2NMDA': 150,                'e': 0}
# netParams.synMechParams['AMPA']             = {'mod': 'MyExp2SynBB',        'tau1': 0.05,   'tau2': 5.3,                    'e': 0}
# # inhibitory synapses
# netParams.synMechParams['GABAB']            = {'mod': 'MyExp2SynBB',        'tau1': 3.5,    'tau2': 260.9,                  'e': -93} 
# netParams.synMechParams['GABAA']            = {'mod': 'MyExp2SynBB',        'tau1': 0.07,   'tau2': 18.2,                   'e': -80}
# netParams.synMechParams['GABAASlow']        = {'mod': 'MyExp2SynBB',        'tau1': 2,      'tau2': 100,                    'e': -80}
# netParams.synMechParams['GABAASlowSlow']    = {'mod': 'MyExp2SynBB',        'tau1': 200,    'tau2': 400,                    'e': -80}

ESynMech    = ['exc']
SOMESynMech = ['inh']
SOMISynMech = ['inh']
PVSynMech   = ['inh']
NGFSynMech  = ['inh']

#------------------------------------------------------------------------------
# Current inputs (IClamp)
#------------------------------------------------------------------------------
if cfg.addIClamp:
    for key in [k for k in dir(cfg) if k.startswith('IClamp')]:
        params = getattr(cfg, key, None)
        [pop,sec,loc,start,dur,amp] = [params[s] for s in ['pop','sec','loc','start','dur','amp']]

        # cfg.analysis['plotTraces']['include'].append((pop,0))  # record that pop

        # add stim source
        # netParams.stimSourceParams[key] = {'type': 'IClamp', 'delay': start, 'dur': dur, 'amp': amp}
        netParams.stimSourceParams[key] = { 'type': 'IClamp', 
                                            'delay': start, 
                                            'dur': cfg.stimDur if cfg.stimDur is not None else dur, 
                                            'amp': cfg.clampAmplitude if cfg.clampAmplitude is not None else amp}
        
        # connect stim source to target
        netParams.stimTargetParams[key+'_'+pop] =  {
            'source': key, 
            'conds': {'pop': pop},
            'sec': sec, 
            'loc': loc}