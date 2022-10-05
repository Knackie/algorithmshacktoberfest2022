"""
provides implementation of the z function
"""


def z_function(in_str):
    """
    computes the Z function for given input string
    """
    res = [0 for _ in in_str]
    left = 0
    right = 0
    for pos in range(1, len(in_str)):
        if pos <= right:
            res[pos] = min(right - pos + 1, res[pos - left])
        while (
            pos + res[pos] < len(in_str) and in_str[res[pos]] == in_str[pos + res[pos]]
        ):
            res[pos] += 1
        if pos + res[pos] - 1 > right:
            left = pos
            right = pos + res[pos] - 1

    return res
