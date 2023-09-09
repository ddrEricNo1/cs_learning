def gcd(a, b):
    """Return the greatest common diviser between these two numbers"""
    return gcd(b, a % b) if b != 0 else a


def make_rat(n, d):
    """The rational number N/D, assuming N, D are integers. D!= 0"""
    g = gcd(n, d)
    n //= g 
    d //= g
    return (n, d)


def numer(r):
    """The numerator of rational number R in lowest term"""
    return r[0]


def denom(r):
    """The denominator of rational number R in lowest term.
    Always positive."""
    return r[1]

def add_rat(x, y):
    return make_rat(numer(x) * denom(y) + numer(y) * denom(x), denom(x), denom(y))

def mul_rat(x, y):
    return make_rat(numer(x) * numer(y), denom(x) * denom(y))

def equal_rat(x, y):
    return numer(x) * denom(y) == numer(y) * denom(x)

def str_rat(r):
    return str(numer(r)) if denom(r) == 1 else f"{numer(r)}/{denom(r)}"