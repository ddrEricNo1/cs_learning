def reverse_digits(n):
    """a function that reverses the digits in a number.
    >>> reverse_digits(1234)
    4321
    >>> reverse_digits(0)
    0
    >>> reverse_digits(100)
    1
    >>> reverse_digits(121)
    121
    """
    assert type(n) is int and n >= 0
    if n < 10:
        return n
    else:
        return reverse_digits(n // 10) + (n % 10) * 10 ** (num_digits(n) - 1)


def num_digits(n):
    count = 1
    while n >= 10:
        count += 1
        n //= 10
    return count
        
if __name__ == "__main__":
    import doctest
    doctest.testmod();