#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    l = len(boxes)
    keys = []
    for box in boxes:
        for key in box:
            if key not in keys:
                if key != 0 and key < l:
                    keys.append(key)
    keys.sort()
    t = 1
    for i in keys:
        if type(boxes[i]) is list:
            if boxes[i]:
                t += 1
        else:
            return False
    if t == l - 1:
        return True
    return False