#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    if not isinstance(n, int) or n < 0:
        return 0
    k = n**0.5
    return round(k*2)
