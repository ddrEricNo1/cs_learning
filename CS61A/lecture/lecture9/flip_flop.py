def flip(flop):
    if flop > 1:
        return None
    flip = lambda flip: flip + 1
    return flip


def flop(flip):
    return flop


if __name__ == "__main__":
    flip(flop(1)(2))(3)