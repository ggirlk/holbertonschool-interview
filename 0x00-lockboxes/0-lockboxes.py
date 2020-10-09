#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    k=[]
    test = True
    if type(boxes) is not list or len(boxes) == 0:
        return False
    for boxe in boxes:
        for key in boxe:
            if key == 0:
                return False
            if key not in k:
                k.append(key)

    for i in range(0, len(boxes)):
        if i not in k:
            test = False
        if type(boxes[i]) is list and len(boxes[i]) == 0:
            test = True

    return test
