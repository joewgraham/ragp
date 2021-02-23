# extracing v and t lists after running netpyne based simulation
#Add to cfg.py or put at top of code that requires lists v and t (eg - parameter_plot.py)
import json
import matplotlib.pyplot as plt
import scipy.io

v = sim.allSimData['V_soma']['cell_0']
t = sim.allSimData['t']
