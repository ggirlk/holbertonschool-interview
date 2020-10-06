#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""


def canUnlockAll(boxes):
    k = []
    for i in range(0, len(boxes)):
        for j in range(0, len(boxes[i])):
            k.append(boxes[i][j])

    i=1
    try:
        while boxes[i]:        
            if not isinstance(boxes[i], list) and len(boxes[i]) == 0:
                return False
            if i not in k:
                return False        
            i += 1
    except:
        return False
        
    return True
