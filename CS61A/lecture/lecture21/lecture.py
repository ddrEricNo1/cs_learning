# 零钱兑换问题
def count_change(amount, coins=(50, 25, 10, 5, 1)):
    """Return the number of ways to make change for AMOUNT, where the coin denominations are given by COINS"""
    if amount == 0:
        return 1
    elif len(coins) == 0 or amount < 0:
        return 0
    else:
        return count_change(amount - coins[0], coins) + count_change(amount, coins[1: ])


def count_change1(amount, coins=(50, 25, 10, 5, 1)):
    memo_table = {}
    def count_change(amount, coins):
        key = (amount, coins)
        if key not in memo_table:
            memo_table[key] = full_count_change(amount, coins)
        return memo_table[key]
    
    def full_count_change(amount, coins):
        # original recursive solution goes here verbatim
        # when it calls count_change, calls memozied version
        if amount == 0:
            return 1
        elif len(coins) == 0 or amount < 0:
            return 0
        else:
            return full_count_change(amount - coins[0], coins) + full_count_change(amount, coins[1: ])
    return count_change(amount, coins)