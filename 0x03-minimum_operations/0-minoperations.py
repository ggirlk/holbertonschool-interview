#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    count = 0
    if not isinstance(n, int) or n < 0:
        return 0
    k = 0
    op = 0
    while True:
        if k == 0:
            count += 1
            op = (op * 2) + 1
            k = 2
        else:
            count += 1
            k -= 1
            op += 1
        if op >= n:
            if op == n:
                return count
            else:
                return 0
        
        
        
