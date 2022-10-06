"""
tests for the module z_function.py
"""

import pytest
import z_function


@pytest.mark.parametrize(
    "input_str, expected",
    [
        ("aaaaa", [0, 4, 3, 2, 1]),
        ("abbabb", [0, 0, 0, 3, 0, 0]),
        ("aaabaab", [0, 2, 1, 0, 2, 1, 0]),
        ("abacaba", [0, 0, 1, 0, 3, 0, 1]),
        ("xyz$abcxyxyzabc", [0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0]),
        ("aabaacd", [0, 1, 0, 2, 1, 0, 0]),
        ("abababab", [0, 0, 6, 0, 4, 0, 2, 0]),
    ],
)
def test_z_function(input_str, expected):
    """
    test of z_function against example data
    """
    assert z_function.z_function(input_str) == expected
