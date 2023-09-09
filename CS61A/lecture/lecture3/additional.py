def same_length(a, b):
    """Return true if positive integers A and B have the same number of digits when written in decimal.
    >>> same_length(50, 70)
    True
    >>> same_length(50, 100)
    False
    >>> same_length(1000, 100000)
    False
    """
    return num_digits(a) == num_digits(b)


def num_digits(a, radix=10):
    """Return number of decimal digits in A, base RADIX"""
    a_count = 1
    while a >= radix:
        a = a // radix
        a_count += 1
    return a_count