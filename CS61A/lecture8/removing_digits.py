def removing_digits(n, digit):
    """Assumes N >= 0, 0 <= DIGIT <= 9, return a number whose base-10 representation is the same as N, but with 
    all instances of DIGIT removed. If all digits removed, return 0.
    >>> removing_digits(123, 3)
    12
    >>> removing_digits(1234, 5)
    1234
    >>> removing_digits(1234, 1)
    234
    >>> removing_digits(11111, 1)
    0
    """
    if n == 0:
        return 0
    if n % 10 == digit:
        return removing_digits(n // 10, digit)
    return n % 10 + removing_digits(n // 10, digit) * 10

if __name__ == "__main__":
    import doctest
    doctest.testmod()
    