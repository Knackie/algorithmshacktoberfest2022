import numpy as np
import copy
import time
import queue as Q


class NodeClass:
    w = 1

    def __init__(self, content, predecessor, goal):
        self.content = content
        self.f = 0  # admissible
        self.fp = 0  # non-admissible
        self.g = 0  # cost function
        self.h = 0  # heuristic function
        self.predecessor = predecessor
        self.size = self.content.shape[0]
        self.goal = goal

    def is_goal(self):
        if np.array_equal(self.content, self.goal):
            return True
        else:
            return False

    def calculate_h(self):
        h_value = 0
        for i in range(self.size):
            for j in range(self.size):
                if self.goal[i, j] != self.size ** 2 and self.content[i, j] != self.goal[i, j]:
                    a, b = np.where(self.content == self.goal[i, j])
                    h_value += abs(a[0] - i) + abs(b[0] - j)
        self.h = h_value

    def calculate_g(self):
        # g value
        parent = self.predecessor
        self.g = parent.g + 1

    def calculate_f(self):
        # f value
        self.fp = self.g + self.w * self.h
        self.f = self.g + self.h

    def calculate_costs(self):
        self.calculate_h()
        self.calculate_g()
        self.calculate_f()

    def __str__(self):
        output = ''
        output += 'fp(%0.2f) = g(%0.2f) + %0.1f*h(%0.2f)\n' % (self.fp, self.g, self.w, self.h)
        for i in range(self.size):
            for j in range(self.size):
                if self.content[i, j] == self.size ** 2:
                    output += '%2s' % 'b'
                else:
                    output += '%2d' % self.content[i, j]
                output += ' '
            output += '\n'
        return output

    def __eq__(self, other):
        if np.array_equal(self.content, other.content):
            return True
        else:
            return False

    def generate_successor(self):
        successors_list = []

        i, j = np.where(self.content == self.size ** 2)
        i = i[0]
        j = j[0]

        # Move blank up
        if i != 0:
            temp = copy.deepcopy(self.content)
            temp_value = temp[i - 1][j]
            temp[i - 1][j] = self.size ** 2
            temp[i][j] = temp_value
            successors_list.append(NodeClass(temp, self, self.goal))

        # Move blank down
        if i != (self.content.shape[0] - 1):
            temp = copy.deepcopy(self.content)
            temp_value = temp[i + 1][j]
            temp[i + 1][j] = self.size ** 2
            temp[i][j] = temp_value
            successors_list.append(NodeClass(temp, self, self.goal))

        # Move blank left
        if j != 0:
            temp = copy.deepcopy(self.content)
            temp_value = temp[i][j - 1]
            temp[i][j - 1] = self.size ** 2
            temp[i][j] = temp_value
            successors_list.append(NodeClass(temp, self, self.goal))

        # Move blank right
        if j != (self.content.shape[1] - 1):
            temp = copy.deepcopy(self.content)
            temp_value = temp[i][j + 1]
            temp[i][j + 1] = self.size ** 2
            temp[i][j] = temp_value
            successors_list.append(NodeClass(temp, self, self.goal))

        return successors_list


def shuffle_board(board, n):
    temp = copy.deepcopy(board)
    for i in range(n):
        # random direction
        direction = np.random.choice(range(4), 1)
        a, b = np.where(temp == board.shape[0] ** 2)
        a = a[0]
        b = b[0]
        # Move blank up
        if direction == 0 and a != 0:
            temp_value = temp[a - 1][b]
            temp[a - 1][b] = temp.shape[0] ** 2
            temp[a][b] = temp_value

        # Move blank down
        if direction == 1 and a != board.shape[0] - 1:
            temp_value = temp[a + 1][b]
            temp[a + 1][b] = board.shape[0] ** 2
            temp[a][b] = temp_value

        # Move blank left
        if direction == 2 and b != 0:
            temp_value = temp[a][b - 1]
            temp[a][b - 1] = board.shape[0] ** 2
            temp[a][b] = temp_value

        # Move blank right
        if direction == 3 and b != board.shape[0] - 1:
            temp_value = temp[a][b + 1]
            temp[a][b + 1] = board.shape[0] ** 2
            temp[a][b] = temp_value

    return temp


def get_min(temp):
    min_index = 0
    for i in range(len(temp)):
        if temp[i].fp < temp[min_index].fp:
            min_index = i

    min_index2 = min_index
    for i in range(len(temp)):
        if temp[i].fp == temp[min_index].fp:
            if temp[i].h < temp[min_index2].h:
                min_index2 = i

    return temp[min_index2]


# 8-Puzzle
goal_node = np.array([[1, 2, 3], [8, 9, 4], [7, 6, 5]])
# 15-Puzzle
# goal_node = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])

# Shuffle
startNode = shuffle_board(goal_node, 200)
# Source: http://www.d.umn.edu/~jrichar4/8puz.html
# Source: https://www.geeksforgeeks.org/a-search-algorithm/

startNode = NodeClass(startNode, None, goal_node)
startNode.calculate_h()
startNode.calculate_f()
print('Start Node')
print(startNode)

open_list = [startNode]
closed_list = []
iters = 0
start_time = time.time()

try:
    # for i in range(2):
    while True:
        # Find node with least f
        node = get_min(open_list)
        iters += 1

        # print 'O:%d, C:%d' % (len(open_list),len(closed_list))
        # print 'Min Node is:------------------------------------------------'
        # print node

        open_list.remove(node)

        # Check if successor is the goal node
        if node.is_goal():
            # raise an exception
            print('Goal is:****************************************************')
            print(node)
            print('Total number of moves: %d' % iters)
            print('Total time is: %5f' % (time.time() - start_time))
            raise StopIteration()

        # Generate successors
        temp = node.generate_successor()

        # Iterate over children
        for j in range(len(temp)):
            # Calculate costs
            temp[j].calculate_costs()
            # print temp[j]
            # Check for better duplicates in open_list
            if temp[j] in open_list:
                k = open_list.index(temp[j])
                # print 'In Closed with g= %0.2f' % open_list[k].g
                if temp[j].g >= open_list[k].g:
                    continue
                else:
                    open_list.remove(temp[j])
                    open_list.append(temp[j])

            # Check for better duplicates in closed_list
            elif temp[j] in closed_list:
                k = closed_list.index(temp[j])
                # print 'In Closed with g= %0.2f' % closed_list[k].g
                if temp[j].g >= closed_list[k].g:
                    continue
                else:
                    closed_list.remove(temp[j])
                    open_list.append(temp[j])
            else:
                open_list.append(temp[j])
        closed_list.append(node)
except StopIteration:
    pass