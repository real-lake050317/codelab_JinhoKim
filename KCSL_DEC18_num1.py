for i in range(5):
    ans = ''
    hour = 0; sec = 0; min = 0
    length = [1, 1, 2, 3, 5]
    a = input()
    letters = []
    for j in a:
        letters.append(j)
    for j in range(5):
        if letters[j] == 'R':
            hour += 1*length[j]
        elif letters[j] == 'G':
            min += 5*length[j]
        elif letters[j] == 'B':
            sec += 5*length[j]
        elif letters[j] == 'Y':
            hour += 1*length[j]
            min += 5*length[j]
        elif letters[j] == 'M':
            hour += 1*length[j]
            sec += 5*length[j]
        elif letters[j] == 'C':
            min += 5*length[j]
            sec += 5*length[j]
    if sec >= 60:
        sec -= 60
        min += 1
    if min >= 60:
        min -= 60
        hour += 1
    if hour > 12:
        hour -= 12
    if hour<10:
        ans += '0' + str(hour) + ':'
    else:
        ans += str(hour) + ':'
    if min<10:
        ans += '0' + str(min) + ':'
    else:
        ans += str(min) + ':'
    if sec<10:
        ans += '0' + str(sec)
    else:
        ans += str(sec)
    print(ans)