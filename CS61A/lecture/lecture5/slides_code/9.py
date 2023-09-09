def print_sums(n):
    print(n)
    def next_sum(k):
        return print_sums(n + k)
    return next_sum


if __name__ == "main__":
    print_sums(1)(3)(5)

