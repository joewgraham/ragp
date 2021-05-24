from netpyne import specs, sim

try:
    from __main__ import cfg  # import SimConfig object with params from parent module
except:
    from cfg import cfg  # if no simConfig in parent module, import directly from tut8_cfg module

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters

## Cell parameters/rules
PYRcell = {'secs': {}}
PYRcell['secs']['soma'] = {'geom': {}, 'mechs': {}}  # soma params dict
PYRcell['secs']['soma']['geom'] = {'diam': 18.8, 'L': 18.8, 'Ra': 123.0}  # soma geometry
PYRcell['secs']['soma']['mechs']['hh'] = {'gnabar': 0.12, 'gkbar': 0.036, 'gl': 0.003, 'el': -70}  # soma hh mechanism
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

if cfg.addPreIClamp:
    for key in [k for k in dir(cfg) if k.startswith('PreIClamp')]:
        params = getattr(cfg, key, None)
        [pop,sec,loc,start,dur,amp] = [params[s] for s in ['pop','sec','loc','start','dur','amp']]

        # cfg.analysis['plotTraces']['include'].append((pop,0))  # record that pop

        # add stim source
        # netParams.stimSourceParams[key] = {'type': 'IClamp', 'delay': start, 'dur': dur, 'amp': amp}
        netParams.stimSourceParams[key] = { 'type': 'IClamp', 
                                            'delay': start, 
                                            'dur': cfg.stimDur_pre if cfg.stimDur_pre is not None else dur, 
                                            'amp': cfg.clampAmplitude_pre if cfg.clampAmplitude_pre is not None else amp}
        
        # connect stim source to target
        netParams.stimTargetParams[key+'_'+pop] =  {
            'source': key, 
            'conds': {'pop': pop},
            'sec': sec, 
            'loc': loc}

#------------------------------------------------------------------------------
# NetStim inputs - FROM CFG.PY
#------------------------------------------------------------------------------
if cfg.addNetStim:
    for key in [k for k in dir(cfg) if k.startswith('NetStim')]:
        params = getattr(cfg, key, None)
        [pop, sec, loc, synMech, synMechWeightFactor, start, interval, noise, number, weight, delay] = \
        [params[s] for s in ['pop', 'sec', 'loc', 'synMech', 'synMechWeightFactor', 'start', 'interval', 'noise', 'number', 'weight', 'delay']] 

        #cfg.analysis['plotTraces']['include'] = [(pop,0)]

        if synMech == ESynMech:
            wfrac = cfg.synWeightFractionEE
        elif synMech == SOMESynMech:
            wfrac = cfg.synWeightFractionSOME
        else:
            wfrac = [1.0]

        # add stim source
        netParams.stimSourceParams[key] = { 'type':     'NetStim', 
                                            'start':    cfg.startStimTime       if cfg.startStimTime is not None        else start, 
                                            'interval': cfg.interStimInterval   if cfg.interStimInterval is not None    else interval, 
                                            'noise':    noise, 
                                            'number':   cfg.numStims            if cfg.numStims is not None             else number}

        # netParams.stimSourceParams[key] = {'type': 'NetStim', 'start': start, 'interval': interval, 'noise': noise, 'number': number}

        # connect stim source to target
        # for i, syn in enumerate(synMech):
        netParams.stimTargetParams[key+'_'+pop] =  {
            'source': key, 
            'conds': {'pop': pop},
            'sec': sec, 
            'loc': loc,
            'synMech': synMech,
            # 'weight': weight,
            'weight': cfg.netWeight if cfg.netWeight is not None else weight,
            'synMechWeightFactor': synMechWeightFactor,
            'delay': delay}

#------------------------------------------------------------------------------
# Targeted NetStim inputs - FROM CFG.PY
#------------------------------------------------------------------------------
# The difference of this one to the "NetStim" is that this one allows you to target specific cells within a pop

if cfg.addTargetedNetStim:
    for key in [k for k in dir(cfg) if k.startswith('TargetedNetStim')]:
        params = getattr(cfg, key, None)
        [pop, sec, loc, synMech, synMechWeightFactor, start, interval, noise, number, weight, delay, targetCells] = \
        [params[s] for s in ['pop', 'sec', 'loc', 'synMech', 'synMechWeightFactor', 'start', 'interval', 'noise', 'number', 'weight', 'delay', 'targetCells']] 

        #cfg.analysis['plotTraces']['include'] = [(pop,0)]

        if synMech == ESynMech:
            wfrac = cfg.synWeightFractionEE
        elif synMech == SOMESynMech:
            wfrac = cfg.synWeightFractionSOME
        else:
            wfrac = [1.0]

        # add stim source
        netParams.stimSourceParams[key] = { 'type':     'NetStim', 
                                            'start':    cfg.startStimTime       if cfg.startStimTime is not None        else start, 
                                            'interval': cfg.interStimInterval   if cfg.interStimInterval is not None    else interval, 
                                            'noise':    noise, 
                                            'number':   cfg.numStims            if cfg.numStims is not None             else number}

        # netParams.stimSourceParams[key] = {'type': 'NetStim', 'start': start, 'interval': interval, 'noise': noise, 'number': number}

        # connect stim source to target
        # for i, syn in enumerate(synMech):
        netParams.stimTargetParams[key+'_'+pop] =  {
            'source': key, 
            'conds': {'pop': cfg.stimPop if cfg.stimPop is not None else pop, 'cellList': targetCells},
            'sec': sec, 
            'loc': loc,
            'synMech': cfg.synMech if cfg.synMech is not None else synMech,
            # 'weight': weight,
            'weight': cfg.netWeight if cfg.netWeight is not None else weight,
            'synMechWeightFactor': synMechWeightFactor,
            'delay': delay}

#------------------------------------------------------------------------------
# GroupNetStim inputs - FROM CFG_CELL.PY
#------------------------------------------------------------------------------
if cfg.addGroupNetStim:
    # Group of NetStims
    for key in [k for k in dir(cfg) if k.startswith('GroupNetStim')]:
        params = getattr(cfg, key, None)
        nstype, numStims, pop, ynorm, cellRule, secList, allSegs, synMech, start, interval, noise, number, weight, delay = [params[s] for s in ['nstype', 'numStims', 'pop', 'ynorm', 'cellRule', 'secList', 'allSegs', 'synMech', 'start', 'interval', 'noise', 'number', 'weight', 'delay']]

        # cfg.analysis['plotTraces']['include'].append((pop,0))

        # print(str(netParams.cellParams[cellRule]))
        if not isinstance(secList, list):
            secList = list(netParams.cellParams[cellRule]['secLists'][secList])

        istim = 0
        segs = []

        if synMech == ESynMech:
            wfrac = cfg.synWeightFractionEE
        elif synMech == SOMESynMech:
            wfrac = cfg.synWeightFractionSOME
        else:
            wfrac = [1.0]

        if nstype == 'stim':  # implement as a stim - [jv] not being used
            while istim < numStims:
                for secName,sec in netParams.cellParams[cellRule]['secs'].items():
                    if secName in secList:
                        if allSegs:
                            nseg = sec['geom']['nseg']
                            for iseg in range(nseg):
                                segs.append([secName, (iseg+1)*(1.0/(nseg+1))])
                                istim += 1
                                if istim >= numStims: break
                        else:
                            segs.append([secName, 0.5])
                            istim += 1
                        
                        if istim >= numStims: break

            for istim, seg in enumerate(segs):

                # add stim source
                netParams.stimSourceParams[key+'_'+str(istim)] = {'type': 'NetStim', 'start': start, 'interval': interval, 'noise': noise, 'number': number}

                # connect stim source to target
                for i, syn in enumerate(synMech):
                    netParams.stimTargetParams[key+'_'+pop+'_'+syn+'_'+str(istim)] =  {
                        'source': key+'_'+str(istim), 
                        'conds': {'pop': pop, 'ynorm': ynorm},
                        'sec': seg[0], 
                        'loc': seg[1],
                        'synMech': syn,
                        'weight': weight*wfrac[i],
                        'delay': delay}

        elif nstype == 'pop':  # implement as a pop
            netParams.popParams[key] = {	'cellModel':'NetStim', 
                                            'numCells': numStims, 
                                            'rate': 	cfg.groupRate       if cfg.groupRate is not None        else 1000/interval,
                                            'noise': 	noise, 
                                            'start': 	start, 
                                            # 'start': 	cfg.startStimTime   if cfg.startStimTime is not None    else start, 
                                            'number':   number}
                                            # 'number': 	cfg.numGroupStims  if cfg.numGroupStims is not None  else number}
            
            netParams.connParams[key] = { 
                        'preConds': 	{'pop': key}, 
                        'postConds': 	{'pop': pop, 'ynorm': ynorm},
                        'synMech': 		synMech,
                        'weight': 		cfg.groupWeight if cfg.groupWeight is not None else weight, 
                        'synMechWeightFactor': wfrac,
                        'delay': 		delay,
                        'synsPerConn': 	1,
                        'sec': 			secList}
            
            netParams.subConnParams[key] = {
                        'preConds': 	{'pop': key}, 
                        'postConds': 	{'pop': pop, 'ynorm': ynorm},  
                        'sec': 			secList, 
                        'groupSynMechs': ESynMech, # removed to use only AMPA and see if it affects spatial summation, and not a combination of [AMPA, NMDA] 2020_05_28
                        'density': 		'uniform'} 

