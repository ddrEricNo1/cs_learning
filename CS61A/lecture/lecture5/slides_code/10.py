from operator import add


def curry2(f):
    return lambda x: lambda y: f(x, y)


if __name__ == "__main__":
    print(curry2(add)(30)(12))
    print(curry2(add)(30))