#!/usr/bin/python3
"""
Created on Mon Jul 27 05:52:28 2020

@author: khouloud
"""

def canUnlockAll(boxes):
    k = []
    t = True
    for i in range(0, len(boxes)):
    	k.append(i)

    for i in range(0 ,len(boxes) - 1):
    	if len(boxes[i]) == 0:
    		t = False
    	for j in range(0, len(boxes[i])):
	   		if boxes[i][j] not in k:
	   			t = False
    return t