# extracing v and t lists after running netpyne based simulation
#Add to cfg.py or put at top of code that requires lists v and t (eg - parameter_plot.py)
#import json
#import matplotlib.pyplot as plt
#import scipy.io
import numpy as np


v = sim.allSimData['V_soma']['cell_0']
t = sim.allSimData['t']

V=np.v
t=np.v 

for i in range(0, len(list_name)): 
    list_name[i] = int(list_name[i])