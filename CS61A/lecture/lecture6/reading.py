def sum_digits(n):
    """Return the sum of the digits of positive integer n"""
    # base case
    if n < 10:
        return n
    else:
        all_but_last, last = n // 10, n % 10
        return sum_digits(all_but_last) + last


# an example of mutual recursion
def is_even(n):
    if n == 0:
        return True
    else:
        return is_odd(n - 1)
    

def is_odd(n):
    if n == 0:
        return False
    else:
        return is_even(n - 1)
    

if __name__ == "__main__":
    print(sum_digits(11))