for i in range(5):
    n, p = input().split()
    p = len(n) - int(p)
    for i in range(len(n)):
        if (i == p):
            print(n[i], end='')
        elif (i > p):
            print(str(abs(int(n[i]) - int(n[p]))), end='')
        else: 
            print(str((int(n[i]) + int(n[p]))%10), end='')
    print()