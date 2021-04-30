from netpyne import specs, sim

# Network parameters
netParams = specs.NetParams()  # object of class NetParams to store the network parameters
from cfg import cfg

## Cell types
PYRcell = {'secs': {}}

PYRcell['secs']['soma'] = {'geom': {}, 'mechs': {}}  
PYRcell['secs']['soma']['geom'] = {'diam': 30, 'L': 30, 'Ra': 35.4, 'cm': 1} #123.0 <--- why did Ra change?

PYRcell['secs']['soma']['mechs']['pas'] = {'g': 1.8e-6, 'e': -65} 	
#Ca
PYRcell['secs']['soma']['mechs']['ch_Cacna1a_cp5.mod'] = {'CagCav2_1bar': 1e-5} 
PYRcell['secs']['soma']['mechs']['ch_Cacna1b_cp6'] = {'gCav2_2bar':  1e-4} #0.0001
PYRcell['secs']['soma']['mechs']['ch_Cacna1c_cp3'] = {'gLbar': 1e-5} #original 0.0001 
PYRcell['secs']['soma']['mechs']['ch_Cacna1g_cp41'] = {'gCav3_1bar': 1e-5} 
PYRcell['secs']['soma']['mechs']['ch_Cacna1i_cp42'] = {'gCav3_3bar': 1e-5}  #original 0.0001
#Na
PYRcell['secs']['soma']['mechs']['ch_Scn1a_md264834'] = {'gNav11bar': 1.0} 	# 0.00001
#K		
PYRcell['secs']['soma']['mechs']['ch_Kcnc1_md74298'] = {'gk': 0.1} #changed to 0.1  		
PYRcell['secs']['soma']['mechs']['ch_Kcna1ab1_md80769'] = {'gbar': 0.015} 
#HCN
PYRcell['secs']['soma']['mechs']['ch_Hcn1_cp9'] = {'gHCN1bar': 0.0001}
PYRcell['secs']['soma']['mechs']['ch_Hcn2_cp10'] = {'gHCN2bar': 0.0001} #original 0.010	
PYRcell['secs']['soma']['mechs']['ch_Hcn3_cp11'] = {'gHCN3bar': 0.0001}
PYRcell['secs']['soma']['mechs']['ch_Hcn4_cp12'] = {'gHCN4bar': 0.001} 

# PYRcell['secs']['soma']['ions']['k']['e'] = -74
PYRcell['secs']['soma']['ions'] = {'k': {'e': -74}}

# sim.net.cells[0].secs.soma.hObj(0.5).ek = -74
# h.ion_style("k_ion", 0, 1, 0, 0, 0,sec=soma) 

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
netParams.stimSourceParams['iclamp'] = {'type': 'IClamp', 'amp': 0.1, 'dur': 200, 'delay': 200} #amp 0.1; del 100; dur 200
netParams.stimTargetParams['iclamp->PYR'] = {'source': 'iclamp', 'conds': {'cellType': 'PYR'}, 'sec': 'soma', 'loc': 0.5}


