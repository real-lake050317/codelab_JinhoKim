class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

a = input()

letters = []
values = []

for i in a:
    if len(letters) == 0:
        letters.append(i)
        values.append(0)
    else:
        for j in range(len(letters)):
            if ord(i) <= ord(letters[j]):
                letters.insert(j, i)
                if j == 0:
                    values.insert(0, values[0] + 1)
                else:
                    values.insert(j, max(values[j-1], values[j]) + 1)
                break
        else:
            letters.append(i)
            values.append(values[-1] + 1)


def makeTree(val, str):
    pivot = val.index(min(val))
    root = Node(val[pivot])
    string_tree = Node(str[pivot])
    if pivot != 0:
        root.left, string_tree.left = makeTree(val[:pivot], str[:pivot])
    if pivot != len(val) - 1:
        root.right, string_tree.right = makeTree(val[pivot+1:], str[pivot+1:])
    return root, string_tree

root, tree = makeTree(values, letters)

def printTree(root):
    if root == None:
        return
    print(root.value, end="")
    printTree(root.left)
    printTree(root.right)

def printTreeFromTheBottom(root):
    if root == None:
        return
    printTreeFromTheBottom(root.left)
    printTreeFromTheBottom(root.right)
    print(root.value, end="")

printTree(tree)
print(" ", end=" ")
printTreeFromTheBottom(tree)