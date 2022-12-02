str = input()
rev = ""
ans = []

dgt = 1
temp = 0
flg = 0

while True:
    rev = str[::-1]
    if flg == 0: # 앞에서부터
        if (int(str[:dgt]) > temp):
            temp = int(str[:dgt])
            ans.append(temp)
            str = str[dgt:]
        else:
            while (int(str[:dgt]) <= temp):
                dgt += 1
            temp = int(str[:dgt])
            ans.append(temp)
            str = str[dgt:]
        rev = str[::-1]
        flg = 1
    else:
        if (int(rev[:dgt]) > temp):
            temp = int(rev[:dgt])
            ans.append(temp)
            rev = rev[dgt:]
        else:
            while (int(rev[:dgt]) <= temp):
                dgt += 1
            temp = int(rev[:dgt])
            ans.append(temp)
            rev = rev[dgt:]
        str = rev[::-1]
        flg = 0
    
    if (len(str) == 0 or int(str) < temp):
        break

for i in ans:
    print(i, end=" ")