import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the equation parameters
daily_profit = 300
cost_per_user = 5000
developer_cost = 5000000
users_per_developer = 7000

# Define the partial differential equation for revenue
def revenue_pde(x, t, R):
    developers = np.floor(x/users_per_developer)
    u = developers * 5000000 / 7000
    dRdt = - (daily_profit - cost_per_user) * R
    for i in range(1, len(x)-1):
        d2Rdx2 = (R[i+1,0] - 2*R[i,0] + R[i-1,0]) / (x[i+1] - x[i])**2
        dRdt[i,0] += u[i] * (cost_per_user - developer_cost) * d2Rdx2
    return dRdt

# Set up the 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Set up the x and t ranges
x = np.arange(0, 100000, 1000)
t = np.arange(0, 5*365, 5)

# Create a meshgrid of x, t, and R values
X, T, R = np.meshgrid(x, t, [0])

# Set the initial condition for revenue
R0 = np.zeros_like(X)

# Use the initial condition to solve the partial differential equation over time
from scipy.integrate import solve_ivp
sol = solve_ivp(lambda t, R: revenue_pde(X, t, R), (0, 5*365), R0.flatten(), method='BDF', dense_output=True)

# Plot the 3D surface of the solution
for i in range(len(t)):
    R[:,i,:] = sol.sol(t[i]).reshape(X.shape)

ax.plot_surface(X, T, R[:,:,0], cmap='coolwarm')
ax.set_xlabel('Number of users')
ax.set_ylabel('Time (days)')
ax.set_zlabel('Revenue (KRW)')
ax.set_title('Business Revenue Model')

plt.show()
