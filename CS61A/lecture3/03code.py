def smallest_factor(n):
    """Returns the smallest value k>1 that evenly divides N."""
    k = 2
    while k <= n:
        if n % k == 0:
            return k
        k += 1


def print_factor(n):
    """Print the prime factors of N.
    >>> print_factor(180)
    2
    2
    3
    3
    5
    """
    while n > 1:
        f = smallest_factor(n)
        print(f)
        n = n // f