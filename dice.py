import random

def main():
    count = [0] * 6
    for i in range(30):
        number = random.randint(1, 6)
        count[number - 1] += 1
    print("Number\tCount")
    for i in range(6):
        print(i + 1, "\t", count[i])
    
main()