#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    if not isinstance(n, int) or n < 0:
        return 0
    k = op = 0
    H = 1
    state = "copy"
    while H < n:
        
        if state == "paste":
            H += H
            k += 1
            op += 1
            if k == 2:
                state = "copy"
        if state == "copy":
            k = 0
            H = H
            op += 1
            state = "paste"
    return op
