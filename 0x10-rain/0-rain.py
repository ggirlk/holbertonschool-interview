#!/usr/bin/python3
""" Rain """


def rain(walls):
    """
    For a given a list of non-negative integers representing
    the heights of walls with unit width 1 calculate how many
    square units of water will be retained after it rains.

    @walls: is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    *** Assume that the ends of the list (before index 0 and after index
        walls[-1]) are not walls, meaning they will not retain water. ***
        If the list is empty return 0.
    """
    count = 0
    m = 0
    for i in range(len(walls)-1):
        if walls[i] != 0:
            m = walls[i]
        if walls[i] == 0:
            k = 0
            for j in range(i, len(walls)-1):
                if walls[j] == 0:
                    k += 1
                else:
                    break
            if (walls[i+1] >= m):
                count += k * m
            else:
                count += k * walls[i+1]

    return count
