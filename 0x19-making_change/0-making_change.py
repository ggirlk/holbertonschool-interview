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
    if (type(total) is not int and total > 10**4):
        return -1
    if total <= 0:
        return 0
    Min = [(2**31 - 1) for i in range(total+1)]
    Min[0] = 0
    for i in range(total+1):
        for j in range(len(coins)):
            if (coins[j] < 1 and coins[j] > (2**31 - 1)):
                return -1
            if coins[j] >= 1 and Min[i - coins[j]] + 1 < Min[i]:
                Min[i] = Min[i - coins[j]] + 1

    if Min[total] <= total:
        return Min[total]
    else:
        return -1
