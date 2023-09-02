def interleaving_digits(a, b):
    """Given two numbers A and B, containing the same number of digits, 
    returns the result of interleaving the digits of A and B, starting with
    the first digit A, then the first digit B, then the second digit A, etc
    >>> interleaving_digits(1, 2)
    12
    >>> interleaving_digits(0, 1)
    1
    >>> interleaving_digits(1, 0)
    10
    >>> interleaving_digits(123, 456)
    142536
    """
    if a < 10:
        return 10 * a + b
    else:
        return interleaving_digits(a // 10, b // 10) * 100 + interleaving_digits(a % 10, b % 10)
