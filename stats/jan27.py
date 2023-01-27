# import plt
import matplotlib.pyplot as plt

banner = [2567, 2817, 3084, 3239, 3372, 3484, 3572]
video = [1258, 1447, 1632, 1822, 1977, 2126, 2273]
type = [375, 371, 376, 380, 383, 385, 386]

days = [2019, 2020, 2021, "2022(E)", "2023(E)", "2024(E)", "2025(E)"]

plt.plot(days, banner, label = "Banner")
plt.plot(days, video, label = "Video")
plt.plot(days, type, label = "Type")

plt.title("Internet Advertising Market Size")

plt.xlabel("Year")
plt.ylabel("₩1B")

plt.legend()

plt.show()