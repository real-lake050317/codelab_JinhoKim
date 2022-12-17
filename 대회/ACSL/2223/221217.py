n, b, s = input().split()
n = int(n)
b = int(b)
s = int(s, b)

nums = []
baseTransition = ""
count = [0] * 16
hex = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"]

def changeBase(num, b, numerals="0123456789abcdef"):
    if (num == 0):
        return numerals[0]
    else:
        return changeBase(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b]

for i in range(s, s + n):
    nums.append(i)

for i in nums:
    baseTransition += str((changeBase(i, b)))

for i in baseTransition:
    count[hex.index(i)] += 1

print(max(count))