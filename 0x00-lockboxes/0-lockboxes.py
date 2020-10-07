#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    k = []
    for i in range(0, len(boxes) - 1):
        for j in range(0, len(boxes[i])):
            k.append(boxes[i][j])
    i = 0
    try:
        while boxes[i]:
            i += 1
    except:
        return False

    for i in range(1, len(boxes)):
        if not isinstance(boxes[i], list) and len(boxes[i]) == 0:
            return False
        if i not in k:
            return False
    return True
