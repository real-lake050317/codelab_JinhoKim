def changeBase(num, b, numList="0123456789abcdef"):
    if (num == 0):
        return numList[0]
    else:
        return changeBase(num // b, b, numList).lstrip(numList[0]) + numList[num % b]

def findModeCount(num, base, start):
    num = int(num)
    base = int(base)
    start = int(start, base)
    nums = []
    baseTransition = ""
    count = [0] * 16
    hex = ["0", "1", "2", "3", "4", "5", "6", "7",
           "8", "9", "a", "b", "c", "d", "e", "f"]

    for i in range(start, start + num):
        nums.append(i)

    for i in nums:
        baseTransition += str(changeBase(i, base))

    for i in baseTransition:
        count[hex.index(i)] += 1

    return max(count)

n, b, s = input().split()

print(findModeCount(n, b, s))
