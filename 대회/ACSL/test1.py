import sys
import math
 
# structure of a node of binary tree
class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
 
# Helper function that allocates a new node with the
#given data and NULL left and right pointers.
def getNode(data):
        return Node(data)
 
# Function to check if there is a path from root
# to the given node. It also populates
# 'arr' with the given path
def getPath(root, rarr, x):
 
    # if root is NULL
    # there is no path
    if not root:
        return False
     
    # push the node's value in 'arr'
    rarr.append(root.data)
 
    # if it is the required node
    # return true
    if root.data == x:
        return True
     
    # else check whether the required node lies
    # in the left subtree or right subtree of
    # the current node
    if getPath(root.left, rarr, x) or getPath(root.right, rarr, x):
        return True
     
    # required node does not lie either in the
    # left or right subtree of the current node
    # Thus, remove current node's value from
    # 'arr'and then return false
    rarr.pop()
    return False
 
# Function to print the path between
# any two nodes in a binary tree
def printPathBetweenNodes(root, n1, n2):
 
    # vector to store the path of
    # first node n1 from root
    path1 = []
 
    # vector to store the path of
    # second node n2 from root
    path2 = []
    getPath(root, path1, n1)
    getPath(root, path2, n2)
 
    # Get intersection point
    i, j = 0, 0
    intersection=-1
    
    while(i != len(path1) or j != len(path2)):
 
        # Keep moving forward until no intersection
        # is found
        if (i == j and path1[i] == path2[j]):
            i += 1
            j += 1
        else:
            intersection = j - 1
            break
 
    # Print the required path
    for i in range(len(path1) - 1, intersection - 1, -1):
        print("{} ".format(path1[i]), end = "")
    for j in range(intersection + 1, len(path2)):
        print("{} ".format(path2[j]), end = "")
     
# Driver program
if __name__=='__main__':
 
    # binary tree formation
    root = getNode(0)
    root.left = getNode(1)
    root.left.left = getNode(3)
    root.left.left.left = getNode(7)
    root.left.right = getNode(4)
    root.left.right.left = getNode(8)
    root.left.right.right = getNode(9)
    root.right = getNode(2)
    root.right.left = getNode(5)
    root.right.right = getNode(6)
    node1=7
    node2=4
    printPathBetweenNodes(root,node1,node2)