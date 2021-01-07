#!/usr/bin/python3
""" Minimum Operations """
import math


def minOperations(n):
    if n < 0:
        return 0
    k = n ** 0.5
    return math.ceil(k*2)
