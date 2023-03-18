with open('data.txt', 'r') as file:
    data = file.read()

data = data.split('\n')

print(data)

dict = {}

cnt = 0

for i in data:
    a, b = i.split(' ')
    dict[cnt] = {a, b}
    cnt += 1

print(dict)

# sort data by number data inside each key


