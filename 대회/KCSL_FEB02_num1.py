inputs  = list(input().split())
alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
type = inputs[0]
init = int(inputs[1])
second = int(inputs[2])
key = inputs[3]
key_num = alphabets.index(key)
message_list = inputs[4:]
message = ''
d_list = []
d_flag = 0
ans = []
e_flag = 0
fib = [init, second]

for i in range(2, 200):
    fib.append(fib[i-2] + fib[i-1])

if (type == 'E'):
    for i in message_list:
        message += i
        message += ' '
    for i in message:
        if (e_flag%2 == 0):
            offset = ord(alphabets[(key_num + fib[e_flag])%26])
        else:
            offset = ord(alphabets[(key_num - fib[e_flag])%26])
        ascii = ord(i)
        ans.append(ascii + offset*3)
        e_flag += 1
    
    for i in range(len(ans)-1):
        print(ans[i], end = ' ')
else:
    for i in message_list:
        if (d_flag%2 == 0):
            d_list.append(int(i) - ord(alphabets[(key_num + fib[d_flag])%26])*3)
        else:
            d_list.append(int(i) - ord(alphabets[(key_num - fib[d_flag])%26])*3)
        d_flag += 1
    for i in d_list:
        message += chr(i)
    print(message)