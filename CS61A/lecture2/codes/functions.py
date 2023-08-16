def incr(n):
    def f(x):
        return n + x 
    return f

 
if __name__ == "__main__":
    res = incr(5)(6)
    print(res)

