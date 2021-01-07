#!/usr/bin/python3
""" Minimum Operations """
import math


def minOperations(n):
    if not isinstance(n, int) or n < 0:
        return 0
    if n <= 2:
        return 2
    op = 1
    H = 1
    state = "copy"
    while H <= n/2:
        if state == "copy":
            h = H
            op += 1
            state = "paste"
        if state == "paste" and H <= n/2:
            H += h
            op += 1
        if state == "paste" and H <= n/2:
            H += h
            op += 1
            state = "copy" 
    return op
