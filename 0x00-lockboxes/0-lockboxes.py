#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    if not boxes or len(boxes) < 2:
        return False
    l = len(boxes)
    t = 1
    keys = [0]
    for key in keys:
        for n in boxes[key]:
            if n not in keys:
                if n != key and n < l:
                    t += 1
                    keys.append(n)
    if t == l:
        return True
    return False
