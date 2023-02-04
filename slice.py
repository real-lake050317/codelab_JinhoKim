a = input()
b = a[:5] + a[7:]
print(b)
target = "10"
for i in range(len(b)-len(target), -1, -1):
    temp = b[i:i+len(target)]
    if temp == target:
        right = True
        rightIdx = i
        break

print(rightIdx)