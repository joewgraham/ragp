from netpyne import specs, sim

# Create network and run simulation
from cfg import cfg
from netParams import netParams
import matplotlib.pyplot as plt
plt.ion()


print("Starting sim ...")
sim.createSimulateAnalyze(netParams=netParams, simConfig=cfg)
print("Finished sim.")  

# fig_dict, data_dict = sim.analysis.plotTraces() #ylim=[-80,60]
# fig0 = fig_dict['_gid_0']
# for ax in fig0.axes:
#     ax.set_xlabel('Time (ms)')
#     ax.set_ylabel('Membrane Voltage (mV)')
#     ax.set_title('')
# fig0.savefig('AP.png')
   

