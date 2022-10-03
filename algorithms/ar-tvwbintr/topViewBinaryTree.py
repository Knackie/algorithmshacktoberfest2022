
# Binary Tree's node structure
class Node:
    def __init__(self, val = None, left = None, right = None):
        self.value = val
        self.left = left
        self.right = right

# Method to get the Top View of Binary Tree
# An Iterative Approach, Do a level order traversal,
# and update the dictionary with values seen for the first time at each level
# Fill the result array using the dictionary
# Input : root node
# Output : [] A List with values of each node from left to right as seen from the top view
# Time Complexity : O(n)
def topViewOfBinaryTree(root):
    topView = []
    if root == None:
        return topView

    d = {}
    # A queue to store a tuple consisting (node, vertical_level)
    queue = []
    queue.append((root, 0))
    minLevel = 0
    maxLevel = 0

    while len(queue) > 0:
        n = len(queue)
        for x in range(0,n):

            (currNode, vLevel) = queue.pop(0)

            minLevel = min(minLevel, vLevel)
            maxLevel = max(maxLevel, vLevel)

            if str(vLevel) not in d:
                d[str(vLevel)] = currNode.value
            if currNode.left != None:
                queue.append((currNode.left, vLevel-1))
            if currNode.right != None:
                queue.append((currNode.right, vLevel+1))

    # fill the result list with values for each level
    for level in range(minLevel, maxLevel+1):
        topView.append(d[str(level)])

    return topView



# Driver Code
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(6)
root.right.left = Node(9)
root.right.right = Node(10)

print(topViewOfBinaryTree(root))