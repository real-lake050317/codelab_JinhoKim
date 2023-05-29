class Node:
    def __init__(self, value): 
      self.value = value
      self.left = None 
      self.right = None

class BinarySearchTree:
    def __init__(self, head):
        self.head = head
    
    def insert_node(self, value):
        self.base_node = self.head 
        while True:
            if self.base_node.value >= value: 
                if self.base_node.left != None: 
                    self.base_node = self.base_node.left 
                else: 
                    self.base_node.left = Node(value) 
                    break
            else: 
                if self.base_node.right != None: 
                    self.base_node = self.base_node.right 
                else: 
                    self.base_node.right = Node(value) 
                    break
	
    def search_node(self, value):
        self.base_node = self.head 
        
        while self.base_node: 
            if self.base_node.value == value: 
                return True 
                break
            
            elif self.base_node.value > value:
                if self.base_node.left != None:
                    self.base_node = self.base_node.left
                else:
                    return False
            
            elif self.base_node.value < value:
                if self.base_node.right != None:
                    self.base_node = self.base_node.right 
                else:
                    return False

a = list(map(int, input().split()))

head = Node(a[0])
bt = BinarySearchTree(head)

for i in range(1, len(a)):
    bt.insert_node(a[i])

def print_tree(node, level=0):
    if node != None:
        print_tree(node.right, level+1)
        print('     ' * level, node.value)
        print_tree(node.left, level+1)

print_tree(head)

print(bt.find_path_sum(1, 3))