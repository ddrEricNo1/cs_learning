def sum_squares(N):
    """Return the sum of K**2 for K from 1 to N"""
    if N < 1:
        return 0
    else:
        # return sum of k**2 for K from 1 to N-1 + N**2
        return sum_squares(N - 1) + N ** 2