def mexp(base: int, exp: int, m: int) -> int:
    result = 1

    while exp > 0:
        if (exp & 1) > 0:
            result = (result * base) % m
        exp >>= 1
        base = (base * base) % m

    return result


assert mexp(3, 3, 5), 2
