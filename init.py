from netpyne import specs, sim

# Create network and run simulation
from cfg import cfg
from netParams import netParams
import matplotlib.pyplot as plt
import csv
plt.ion()


print("Starting sim ...")
#sim.createSimulateAnalyze(netParams, cfg)
sim.createSimulateAnalyze(netParams=netParams, simConfig=cfg)
print("Finished sim.")  

# fig_dict, data_dict = sim.analysis.plotTraces() #ylim=[-80,60]
# fig0 = fig_dict['_gid_0']
# for ax in fig0.axes:
#     ax.set_xlabel('Time (ms)')
#     ax.set_ylabel('Membrane Voltage (mV)')
#     ax.set_title('')
# fig0.savefig('AP.png')
   
gEdictnp = {'v':sim.net.cells[0].secs.soma.hObj(0.5).v, 'ina':sim.net.cells[0].secs.soma.hObj(0.5).ina,'ik':sim.net.cells[0].secs.soma.hObj(0.5).ik, 'ica':sim.net.cells[0].secs.soma.hObj(0.5).ica, 'ipas':sim.net.cells[0].secs.soma.hObj(0.5).pas.i, 'ena':sim.net.cells[0].secs.soma.hObj(0.5).ena, 'ek':sim.net.cells[0].secs.soma.hObj(0.5).ek, 'eca':sim.net.cells[0].secs.soma.hObj(0.5).eca,'epas':sim.net.cells[0].secs.soma.hObj(0.5).pas.e, 'gpas':sim.net.cells[0].secs.soma.hObj(0.5).pas.g}
#å'gNa':sim.net.cells[0].secs.soma.hObj(0.5).ch_Scn1a_md264e834.gNav11, 'gKcnc':sim.net.clls[0].secs.soma.hObj(0.5).ch_Kcnc1_md74298.gkcnc,'gKcna':sim.net.cells[0].secs.soma.hObj(0.5).ch_Kcna1ab1_md80769.gk, 'gHcn1':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn1_cp9.gHCN1,'gHcn2':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn2_cp10.gHCN2, 'gHcn3':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn3_cp11.gHCN3,'gHcn4':sim.net.cells[0].secs.soma.hObj(0.5).ch_Hcn4_cp12.gHCN4, 'gCan1a':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1a_cp5.gCav2_1,'gCa1b':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1b_cp6.gCav2_2, 'gCa1c':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1c_cp3.gL,'gCa1g':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1g_cp41.gCav3_1, 'gCan1i':sim.net.cells[0].secs.soma.hObj(0.5).ch_Cacna1i_cp42.gCav3_3,'S/w':'NetPyNE'}
print(gEdictnp)

filenp = open('gEdump.csv','a') # Appends to existing file
cw = csv.DictWriter(filenp, gEdictnp.keys())
cw.writeheader()
cw.writerow(gEdictnp)
filenp.close()

