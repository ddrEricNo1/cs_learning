def double_eights(n):
    """Return true if n has two eights in a row.
    >>> double_eights(8)
    False
    >>> double_eights(88)
    True
    >>> double_eights(2882)
    True
    >>> double_eights(880088)
    True
    >>> double_eights(12345)
    False
    >>> double_eights(80808080)
    False
    """
    "*** YOUR CODE HERE ***"
    flag = False
    while n > 0:
        digit = n % 10
        n //= 10
        if digit == 8 and flag == True:
            return True
        elif digit == 8:
            flag = True
        else:
            flag = False
    return False



    
