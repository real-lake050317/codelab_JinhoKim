import random

cnt = 0

for i in range(30):
    if random.randint(0, 1) == 0:
        cnt += 1
    
print("Heads: ", cnt, "\nTails: ", (30-cnt))
