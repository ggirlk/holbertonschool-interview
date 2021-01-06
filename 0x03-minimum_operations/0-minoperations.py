#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    count = 0
    if not isinstance(n, int) or n < 0:
        return 0

    k = n**0.5
    #k = round(k*2)
    return int(k*2)
