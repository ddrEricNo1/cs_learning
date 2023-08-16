def f():
    return 0


def g():
    return f()


def h(k):
    def f():
        return 1
    p = k
    return p()


if __name__ == "__main__":
    print(h(g))