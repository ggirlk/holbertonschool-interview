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
    if total <= 0:
        return 0
    if total <= 0:
        return 0

    res = 0
    for i in range(len(coins)):
        if (coins[i] <= total):
            sub_res = makeChange(coins, total-coins[i])

            # Check for INT_MAX to avoid overflow and see if
            # result can minimized
            if (sub_res != sys.maxsize and sub_res + 1 < res):
                res = sub_res + 1
    return res
