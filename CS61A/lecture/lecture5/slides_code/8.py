def f(x):
    def g(y):
        x = y
    g(4)
    return x


if __name__ == "__main__":
    print(f(3))