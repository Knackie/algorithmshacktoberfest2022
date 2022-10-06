"""
tests for the module evaluate_postfix
"""
import pytest
import evaluate_postfix as epe


@pytest.mark.parametrize(
    "input_expr, expected",
    [
        ([5, 2, "/"], 2.5),
        ([5, 2, "+"], 7),
        ([5, 2, "-"], 3),
        ([5, 2, "*"], 10),
        ([5, 2, "**"], 25),
        ([5, 4, 5, "*", "+", 5, "/"], 5),
        ([1, 3, 8, "*", "+"], 25),
        ([4, 5, 6, "*", "+"], 34),
        ([2, 3, 1, "*", "+", 9, "-"], -4),
    ],
)
def test_evaluate_postfix_expr(input_expr, expected):
    """
    tests evaluate_postfix_expr agains example data
    """
    assert epe.evaluate_postfix_expr(input_expr) == expected


@pytest.mark.parametrize(
    "input_expr",
    [[5, "/"], [5, 2, "+", "*"], ["+"], [1, "+"], [1, "+", 2], [1, 2, "+", "-"]],
)
def test_evaluate_postfix_expr_raises_value_error(input_expr):
    """
    checks if evaluate_postfix_expr raises ValueError is the input expression is incorrect
    """
    with pytest.raises(ValueError):
        epe.evaluate_postfix_expr(input_expr)
