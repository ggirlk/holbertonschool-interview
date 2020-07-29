#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""

def canUnlockAll(boxes):
    k = 0
    t = 0
    for i in range(0, len(boxes[k]) - 1):
        for j in range(0, len(boxes) - 1):
        	if j not in boxes[k]:
        		t = 1
        k += 1
    if t == 1:
    	return False
    return True