#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ doc """
    if not isinstance(n, int) or n < 0:
        return 0
    op = 1
    H = 1
    state = "copy"
    while H <= n//2:
        if state == "copy":
            step = H
            op += 1
            state = "paste"
        if state == "paste" and H <= n//2:
            H += step
            op += 1
        if state == "paste" and H <= n//2:
            H += step
            op += 1
            state = "copy" 
    return op
