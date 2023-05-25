import numpy as np
import matplotlib.pyplot as plt
import math

def f(t, y):
    return (y**3-2*t*y)/(t**2)

def sol(t):
    return (10/(t**4+4/t))**(1/2)

def runge_kutta(h, t0, y0, t_end):
    num_steps = int((t_end - t0) / h)
    t = np.zeros(num_steps + 1)
    y = np.zeros(num_steps + 1)

    t[0] = t0
    y[0] = y0

    for i in range(num_steps):
        k1 = h * f(t[i], y[i])
        k2 = h * f(t[i] + h/2, y[i] + k1/2)
        k3 = h * f(t[i] + h/2, y[i] + k2/2)
        k4 = h * f(t[i] + h, y[i] + k3)

        t[i+1] = t[i] + h
        y[i+1] = y[i] + (k1 + 2*k2 + 2*k3 + k4) / 6

    return t, y

# Parameters
h = 0.5  # Step size
t0 = 1.0  # Initial time
y0 = math.sqrt(2)  # Initial condition
t_end = 10.0  # End time

# Solve the differential equation using Runge-Kutta method
t, y = runge_kutta(h, t0, y0, t_end)

# Calculate actual solution
sol_y = sol(t)

# Plotting the results
plt.plot(t, y, label='Numerical solution')
plt.plot(t, sol_y, label='Actual solution')
plt.xlabel('t')
plt.ylabel('y')
plt.title('Solution of $y\' = \\frac{y^3-2ty}{t^2}$ using Runge-Kutta method')
plt.legend()
plt.grid(True)
plt.show()
