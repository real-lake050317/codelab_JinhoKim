cnt = 0
arr = [8, 6, 2, 9, 3, 5, 7, 1, 4, 0]

for i in range(0, 9):
    for j in range(i+1, 10):
        if i == arr[j]:
            z1 = i
            z2 = j
            while z1 < z2:
                t = arr[z1]
                arr[z1] = arr[z2]
                arr[z2] = t
                cnt += 1
                z1 += 1
                z2 -= 1

print(cnt)
