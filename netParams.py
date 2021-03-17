from netpyne import specs, sim

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters
from cfg import cfg

## Cell types
PYRcell = {'secs': {}}

PYRcell['secs']['soma'] = {'geom': {}, 'mechs': {}}  
PYRcell['secs']['soma']['geom'] = {'diam': 30, 'L': 30, 'Ra': 35.4, 'cm': 1} #123.0

PYRcell['secs']['soma']['mechs']['pas'] = {'g': 1.8e-6, 'e': -65} 	
PYRcell['secs']['soma']['mechs']['ch_Cacna1b_cp6'] = {'gCav2_2bar': 0.0001} 
PYRcell['secs']['soma']['mechs']['ch_Cacna1c_cp3'] = {'gLbar': 0.0001} 		
PYRcell['secs']['soma']['mechs']['ch_Cacna1i_cp42'] = {'gCav3_3bar': 0.0001} 		
PYRcell['secs']['soma']['mechs']['ch_Scn1a_md264834'] = {'gNav11bar': 2.0} 	# 0.00001
PYRcell['secs']['soma']['mechs']['ch_Hcn2_cp10'] = {'gHCN2bar': 0.010}		
PYRcell['secs']['soma']['mechs']['ch_Hcn4_cp12'] = {'gHCN4bar': 0.001}		
PYRcell['secs']['soma']['mechs']['ch_Kcnc1_md74298'] = {'gk': 0.015} 		
PYRcell['secs']['soma']['mechs']['ch_Kcna1ab1_md80769'] = {'gbar': 0.015} 

netParams.cellParams['PYR'] = PYRcell

print()
for secName in PYRcell['secs']:
	print(secName)
	for mechName, mech in PYRcell['secs'][secName]['mechs'].items():
		print(mechName, mech)
		print()
		 
## Population parameters
netParams.popParams['ragp'] = {'cellType': 'PYR', 'numCells': 1}

# Stimulation parameters
netParams.stimSourceParams['iclamp'] = {'type': 'IClamp', 'amp': 0.1, 'dur': 200, 'delay': 100} #0.1
netParams.stimTargetParams['iclamp->PYR'] = {'source': 'iclamp', 'conds': {'cellType': 'PYR'}, 'sec': 'soma', 'loc': 0.5}


