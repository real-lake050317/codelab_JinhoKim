n, p = map(int, input().split())
pnum = int(str(n)[len((str(n))) - p])
a = ""

# Calculate number of prime factors of n
def primeFactors(n):
    ans = []
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            ans.append(i)
            n = n / i
    if n > 2:
        ans.append(n)

    return len(list(set(ans)))


for i in range(len(str(n))):
    if (i < len(str(n))- p):
        a += str(int(str(n)[i]) + pnum)
    elif (i == len(str(n)) - p):
        a += str(primeFactors(n))
    else:
        a += str(abs(int(str(n)[i])-pnum))

print(a)