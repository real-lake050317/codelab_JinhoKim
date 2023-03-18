class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# Create the root node
root = Node(1)

# Create the left and right children of the root
root.left = Node(2)
root.right = Node(3)

# Create the left and right children of the left child
root.left.left = Node(4)
root.left.right = Node(5)

# Create the left and right children of the right child
root.right.left = Node(6)
root.right.right = Node(7)
