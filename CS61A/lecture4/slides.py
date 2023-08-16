from math import sin, cos, pi

def summation(N, term):
    k = 1
    sum = 0
    while k <= N:
        sum += term(k)
        k += 1
    return sum

def square(x):
    return x * x


def combine_func(op):
    """combine funcs(OP)(f, g)(x) = OP(f(x), g(x))"""
    def combined(f, g):
        def val(x):
            return op(f(x), g(x))
        return val
    return combined


if __name__ == "__main__":
    # print(summation(5, square))
    # print(summation(4, lambda x: x ** 3))
    # print(summation(5, lambda x: 1/x))
    # approximate e ** x
    # print(summation(10, lambda x: x ** (k - 1) / factorial(k - 1)))
    add_func = combine_func(lambda x, y: x + y)
    h = add_func(sin, cos)
    print(h(pi / 4))