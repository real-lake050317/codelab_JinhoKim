a, b = map(int, input().split())

arr = [i for i in range(1, a+1)]

ans = []
idx = 0

for i in range(a):
    idx += b - 1
    if idx >= len(arr):
        idx = idx % len(arr)

    ans.append(str(arr.pop(idx)))

print('<', ', '.join(ans), '>', sep='')