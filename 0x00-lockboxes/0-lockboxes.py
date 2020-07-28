# -*- coding: utf-8 -*-
#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""

def canUnlockAll(boxes):
    k = 0
    for j in range(0, len(boxes) - 1):
            if j in boxes[j]:
                k = 1
    if k == 1:
        return False
    return True