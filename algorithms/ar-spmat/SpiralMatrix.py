def spiral_matrix(matrix):
    """
    Spiral Matrix implementations.


    The spiral matrix algorithm takes a 2-Dimensional array of N-rows and M-columns as an input, and orders the
    elements of this matrix in spiral order.

    Example:
    [1 , 2, 3]
    [4 , 5, 6]
    [7 , 8, 9]

    is printed out in the following order: 1, 2, 3, 6, 9, 8, 7, 4, 5

    :list matrix: 2-Dimensional Array
    :return: List ordered in spiral order
    :rtype: list
    """

    #
    # Auxiliar functions
    #
    def is_matrix_valid(matrix):
        """
        Validates if a matrix is valid.

        :return: Whether the matrix is valid or not
        :rtype: bool
        """
        # It has to be a list
        if not isinstance(matrix, list):
            return False

        # It cannot be an empty list
        if not len(matrix):
            return False

        # If it is just one line...it is valid
        if len(matrix) == 1:
            return True

        # The length of each row has to be the same
        line_length = len(matrix[0])
        for line in matrix[1:]:
            if len(line) != line_length:
                return False

        # Matrix is valid
        return True
        """
        Steps over the matrix given the direction.
        """
        pass

    #
    # Matrix/parameters validation
    #
    if not is_matrix_valid(matrix):
        raise ValueError('Invalid matrix. ')

    #
    # Spiral Matrix algorithm
    #
    # Set top/bottom/right/left limits
    top_limit = 1
    bottom_limit = len(matrix) - 1
    left_limit = 0
    right_limit = len(matrix[0]) - 1

    # Start iterating over the matrix
    pointer_position = [0, 0]
    direction = 'right'
    ordered_matrix = [matrix[0][0]]

    while len(ordered_matrix) < (len(matrix) * len(matrix[0])):
        if direction == 'right':
            pointer_position[1] = pointer_position[1] + 1
            ordered_matrix += [matrix[pointer_position[0]][pointer_position[1]]]

            if pointer_position[1] == right_limit:
                right_limit = right_limit - 1
                direction = 'down'

        elif direction == 'left':
            pointer_position[1] = pointer_position[1] - 1
            ordered_matrix += [matrix[pointer_position[0]][pointer_position[1]]]

            if pointer_position[1] == left_limit:
                left_limit = left_limit + 1
                direction = 'up'

        elif direction == 'up':
            pointer_position[0] = pointer_position[0] - 1
            ordered_matrix += [matrix[pointer_position[0]][pointer_position[1]]]

            if pointer_position[0] == top_limit:
                top_limit = top_limit + 1
                direction = 'right'

        elif direction == 'down':
            pointer_position[0] = pointer_position[0] + 1
            ordered_matrix += [matrix[pointer_position[0]][pointer_position[1]]]

            if pointer_position[0] == bottom_limit:
                bottom_limit = bottom_limit - 1
                direction = 'left'

    # Return
    return ordered_matrix

#
# Test Cases
#
matrix_1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]

print('Spiral matrix for Matrix 1: ')
print(spiral_matrix(matrix_1))

matrix_2 = [
    [1, 2, 3, 4, 5, 6],
    [7, 8, 9, 10, 11, 12],
    [13, 14, 15, 16, 17, 18],
    [19, 20, 21, 22, 23, 24],
    [25, 26, 27, 28, 29, 30],
]

print('Spiral matrix for Matrix 2: ')
print(spiral_matrix(matrix_2))
