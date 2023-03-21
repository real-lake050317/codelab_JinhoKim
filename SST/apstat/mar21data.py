import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as stats
import math
import plotly.express as px
import plotly.graph_objects as go

arr = [123, 118, 115, 121, 130, 127, 112, 120, 116, 136, 131, 128, 139, 110, 133, 122, 133, 119, 135, 109]

data = np.array(arr)

# calculate the mean and standard deviation of the data
mean = np.mean(data)
std = np.std(data, ddof=1)

# calculate the 95% confidence interval
conf_int = stats.norm.interval(0.95, loc=mean, scale=std)

# calculate the 95% confidence interval for the mean
conf_int_mean = stats.norm.interval(0.95, loc=mean, scale=std/np.sqrt(len(data)))

print(conf_int)
print(conf_int_mean)