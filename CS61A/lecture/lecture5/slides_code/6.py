def f(p, k):
    def g():
        print(k)

    
    if k == 0:
        f(g, 1)
    else:
        p()


if __name__ == "__main__":
    print(f(None, 0))