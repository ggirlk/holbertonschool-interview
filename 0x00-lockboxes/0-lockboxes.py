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
            if key not in k:
                k.append(key)
    i = 0
    for boxe in boxes:
        if i == 0:
            test = True
        if i not in k:
            test = False
        if type(boxe) is list and len(boxe) == 0:
            test = True
        # if type(boxe) is list and len(boxe) == 0 and i != len(boxes) - 1:
        #     test = False
        i += 1

    return test
