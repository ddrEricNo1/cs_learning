def num_partitions(n, k):
    """Return number of distincy ways to express N as a sum of positive integers each of which is <= K,
    where K > 0. (Empty sum is 0)"""
    if n < 0:
        return 0
    elif k == 1:
        return 1
    else:
        return num_partitions(n - k, k) + num_partitions(n, k - 1)