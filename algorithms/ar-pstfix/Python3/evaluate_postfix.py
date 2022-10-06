"""
provides implementation of the function evaluate_postfix_expr
"""

import inspect


def _prepare_operands(stack, in_operation):
    number_of_operands = len(inspect.signature(in_operation).parameters)
    if len(stack) < number_of_operands:
        raise ValueError()
    return tuple((stack.pop() for _ in range(number_of_operands)))


def _proc_operation(stack, in_operation):
    stack.append(in_operation(*_prepare_operands(stack, in_operation)))


def evaluate_postfix_expr(in_expr):
    """
    evaluates given postfix expression
    """
    operations = {
        "+": lambda a, b: b + a,
        "-": lambda a, b: b - a,
        "*": lambda a, b: b * a,
        "/": lambda a, b: b / a,
        "**": lambda a, b: b ** a,
    }

    stack = []
    for _ in in_expr:
        if _ in operations:
            _proc_operation(stack, operations[_])
        else:
            stack.append(_)
    if len(stack) != 1:
        raise ValueError()
    return stack.pop()
