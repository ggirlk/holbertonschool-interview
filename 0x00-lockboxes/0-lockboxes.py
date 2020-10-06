#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    k = []
    t = True
    for i in range(1, len(boxes) - 1):
        for j in range(0, len(boxes[i])):
            k.append(boxes[i][j])

    for i in range(1, len(boxes) - 1):
        if not isinstance(boxes[i], list) and len(boxes[i]) == 0:
            t = False
        if i not in k:
            t = False
        else:
            t = True
    return t
