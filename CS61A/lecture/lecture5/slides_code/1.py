def f():
    return 0


def g():
    print(f())


def h():
    def f():
        return 1

    g()


if __name__ == "__main__":
    print(h())