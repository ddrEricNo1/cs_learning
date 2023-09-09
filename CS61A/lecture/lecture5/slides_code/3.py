def f():
    return 0


def g():
    print(f())


def f():
    return 1


if __name__ == "__main__":
    g()