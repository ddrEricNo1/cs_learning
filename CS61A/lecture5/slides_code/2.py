def f():
    return 0


g = f

def f():
    return 1   


if __name__ == "__main__":
    print(g())