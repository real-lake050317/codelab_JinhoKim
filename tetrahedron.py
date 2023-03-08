import random

cnt = [0]*4

for i in range(30):
    cnt[random.randint(0, 3)] += 1

print("A: ", cnt[0], "\nB: ", cnt[1], "\nC: ", cnt[2], "\nD: ", cnt[3])