def solution(H, W, D):
    cnt = 0
    arr = []

    for i in D:
        if i >= H:
            arr.append(i - H)
            cnt += 1
        else:
            arr.sort()
            for j in range(len(arr)):
                if arr[j] >= H - i:
                    cnt += 1
                    arr.pop(j)
                    break
            
    return cnt