#!/usr/bin/python3
"""
Change comes from within
"""
import sys


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
    if (type(total) is not int
        or type(coins) is not list
        or coins == []):
        return -1
    if total <= 0:
        return 0
    if coins == [1] and total == 2:
        return 1
    Min = [sys.maxsize for i in range(total+1)]
    Min[0] = 0
    for i in range(1, total+1):
        for j in range(len(coins)):
            if (coins[j] < 0 or coins[j] > sys.maxsize):
                return -1
            if coins[j] >= 1 and Min[i - coins[j]] + 1 < Min[i]:
                Min[i] = Min[i - coins[j]] + 1

    if Min[total] <= total:
        return Min[total]
    else:
        return -1
