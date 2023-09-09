def improve(update, close, guess=1):
    while not close(guess):
        guess = update(guess)
    return guess


def approx_eq(x, y, tolerance=1e-15):
    return abs(x - y) < tolerance


def newton_update(f, df):
    """newton_update表示函数f及其导数df沿着这条切线到0的计算过程"""
    def update(x):
        return x - f(x) / df(x)
    return update


def find_zeros(f, df):
    def near_zeros(x):
        return approx_eq(f(x), 0)
    return improve(newton_update(f, df), near_zeros)


def square_root_newton(a):
    def f(x):
        return x * x - a

    def df(x):
        return 2 * x
    
    return find_zeros(f, df)


# 牛顿法可以推广到n次方根
def power(x, n):
    """返回 x * x * x ... * x, n个x相乘"""
    product, k = 1, 0
    while k < n:
        product, k = product * x, k + 1
    return product


def nth_root_of_a(n, a):
    def f(x):
        return power(x, n) - a
    
    def df(x):
        return n * power(x, n - 1)
    return find_zeros(f, df)


# currying的pow形式
def curried_pow(x):
    def h(y):
        return pow(x, y)
    return h


# 在python等更通用的的语言中，当我们需要一个只接受单个参数的函数时，currying很有用，例如map模式可以将单参数应用于一串值
def map_to_range(start, end, f):
    while start < end:
        print(f(start))
        start += 1


# 返回给定的双参数函数的currying版本
def curry2(f):
    def g(x):
        def h(y):
            return f(x, y)
        return h
    return g


# inverse uncurrying transformation
def uncurry2(g):
    """Return a two-argument version of the given curried function"""
    def f(x, y):
        return g(x, y)
    return f


if __name__ == "__main__":
    #print(square_root_newton(64))
    print(nth_root_of_a(3, 64))