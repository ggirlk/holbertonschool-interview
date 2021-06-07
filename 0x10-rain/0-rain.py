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
    k = 0
    for i in range(len(walls)-1):
        if walls[i] > walls[i+1]:
            m = walls[i]
            k = walls[i+1]
        if walls[i] <= walls[i+1]:
            count += m - k

    return count
