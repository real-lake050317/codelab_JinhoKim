# make a function that returns octal number from given binary number
def binToOctal(binNum):
    octal = ""
    while len(binNum) % 3 != 0:
        binNum = "0" + binNum
    for i in range(0, len(binNum), 3):
        octal += str(int(binNum[i:i+3], 2))
    while octal[0] == "0":
        octal = octal[1:]
    return octal


def decimalToOctal(decimal):
    if decimal == 0:
        return "0"
    octal = ""
    while decimal > 0:
        octal = str(decimal % 8) + octal
        decimal //= 8
    return octal


a = input()
b = ""

for i in a:
    e = str(bin(ord(i)))[2:].zfill(8)
    b += e

# print(b)
binNum = 0

while True:
    left = False
    right = False
    leftIdx = 0
    rightIdx = 0
    target = str(bin(binNum))[2:]

    for i in range(len(b)):
        temp = b[i:i+len(target)]
        if temp == target:
            left = True
            leftIdx = i
            break

    if left:
        b = b[:leftIdx] + b[leftIdx+len(target):]

    for i in range(len(b)-len(target), -1, -1):
        temp = b[i:i+len(target)]
        if temp == target:
            right = True
            rightIdx = i
            break

    if right:
        b = b[:rightIdx] + b[rightIdx+len(target):]

    if not left and not right:
        break

    binNum += 1

b = binToOctal(b)

print(b)

octalKey = 0

while True:
    left = False
    right = False
    leftIdx = 0
    rightIdx = 0
    target = str(decimalToOctal(octalKey))

    for i in range(len(b)):
        temp = b[i:i+len(target)]
        if temp == target:
            left = True
            leftIdx = i
            break

    if left:
        b = b[:leftIdx] + b[leftIdx+len(target):]

    for i in range(len(b)-len(target), -1, -1):
        temp = b[i:i+len(target)]
        if temp == target:
            right = True
            rightIdx = i
            break

    if right:
        b = b[:rightIdx] + b[rightIdx+len(target):]

    if not left and not right:
        if octalKey == 0:
            print("-1")
            exit()
        else:
            print(octalKey-1)
            exit()

    octalKey += 1
