#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """
    ********************************************
    ****determine the fewest number of coins****
    *******needed to meet a given amount********
    ********************************************
    @coins: is a list of the values of the coins
            in the possession
    @total: given amount
    Return:
            fewest number of coins needed to meet total
            *** If total is 0 or less, return 0
            *** If total cannot be met by any number
                of coins you have, return -1
    """
    if total <= 0:
        return 0

    res = []
    sub = [0]
    for i in range(len(coins)):
        if coins[i-1] + coins[i] + sub[i] > total:
                return -1
        else:
            if (coins[i-1] + coins[i] + sub[i] < total):
                sub.append(coins[i-1] + coins[i])
                res.append(total - (coins[i-1] + coins[i]) - sub[i])
            else:
                sub.append((coins[i] + coins[i-1]))
                res.append(total - sum(sub) + 1)
    return min(res)
