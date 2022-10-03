class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def left_view_iterative(root_node):
    if not root_node:
        return None

    left_view = []

    queue = [root_node]
    level = max_level = 0

    while len(queue):
        level_count = len(queue)
        level += 1

        for __ in range(level_count):
            node = queue.pop(0)

            if level > max_level:
                left_view.append(node.data)
                max_level = level

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return left_view


if __name__ == "__main__":
    # Build tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    #root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.right.right = Node(8)
    root.right.right.right.left = Node(9)

    # Print left view binary tree
    print(left_view_iterative(root))
