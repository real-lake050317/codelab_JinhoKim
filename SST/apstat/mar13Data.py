import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats
import math
import plotly.express as px
import plotly.graph_objects as go


men_data = [64, 64, 68, 69, 69, 69, 70, 70,
            70, 71, 72, 72, 74, 74, 74, 74, 74, 79]
women_data = [62, 62, 63, 63, 63, 64, 64, 64, 65, 65, 67, 67, 68, 69, 69, 72]


'''
plt.hist(men_data, bins=30, alpha=0.5, label='Men')
plt.hist(women_data, bins=30, alpha=0.5, label='Women')

plt.title('Height Distribution by Gender')
plt.xlabel('Height (cm)')
plt.ylabel('Frequency')

plt.legend()

plt.show()
'''

# change men_data to a numpy array

fig = go.Figure()
fig.add_trace(go.Histogram(x=men_data, name='Men', opacity=0.5,  # set the opacity to 0.5
                           marker_color='#0000FF'))
fig.add_trace(go.Histogram(x=women_data, name='Women', opacity=0.5,  # set the opacity to 0.5
                           marker_color='#FF0000'))

# Update the layout
fig.update_layout(
    title='Height Distribution by Gender',
    xaxis_title='Height (inches)',
    yaxis_title='Count',
    barmode='overlay',
    bargap=0.1,
)

# Show the figure
fig.show()
