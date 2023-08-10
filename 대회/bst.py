class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return TreeNode(val)
    if val <= root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def find_min_value_node(node):
    current = node
    while current.left:
        current = current.left
    return current

def delete_node(root, key):
    if not root:
        return root
    
    if key < root.val:
        root.left = delete_node(root.left, key)
    elif key > root.val:
        root.right = delete_node(root.right, key)
    else:
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        
        temp = find_min_value_node(root.right)
        root.val = temp.val
        root.right = delete_node(root.right, temp.val)
    
    return root

def find_nearest_larger_bst(root, x):
    nearestLarger = None

    while root:
        if root.val > x:
            nearestLarger = root.val
            root = root.left
        else:
            root = root.right
    
    return nearestLarger

def find_nearest_larger_and_remove(arr, x):
    root = None
    for num in arr:
        root = insert(root, num)
    
    nearest_larger = find_nearest_larger_bst(root, x)
    if nearest_larger is not None:
        root = delete_node(root, nearest_larger)
    
    return nearest_larger, root

# Example usage
array = [1, 5, 9, 12, 15, 18]
x = 10
nearest_larger, updated_root = find_nearest_larger_and_remove(array, x)

print("Nearest larger:", nearest_larger)  # Output: 12
