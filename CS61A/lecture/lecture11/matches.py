def matches(a, b):
    """Return the number of values k such that A[k] == B[k]
    >>> matches([1, 2, 3, 4, 5], [3, 2, 3, 0, 5])
    3
    >>> matches("abdomens", "indolence")
    4
    >>> matches("abcd", "dcba")
    0
    >>> matches("abcde", "edcba")
    1
    >>> matches("abcde", "abcdefghi")
    5
    >>> matches("abcd", "abetshersh")
    2
    """
    return sum([1 for (x, y) in zip(a, b) if x == y])

if __name__ == "__main__":
    import doctest
    doctest.testmod()
