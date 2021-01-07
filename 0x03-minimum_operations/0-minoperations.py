#!/usr/bin/python3
""" Minimum Operations """
import math


def minOperations(n):
    if n < 1:
        return 0
    try:
        k = (n) ** 0.5
        return math.ceil(k*2)
    except Exception:
        return 0
