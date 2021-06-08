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
    i = maxleft = maxright = 0
    j = len(walls) - 1
    while i < j:
        if walls[i] < walls[j]:
            if walls[i] < maxleft:
                count += maxleft - walls[i]
            maxleft = max(maxleft, walls[i])
            i += 1
        else:
            if walls[j] < maxright:
                count += maxright - walls[j]
            maxright = max(maxright, walls[j])
            j -= 1
    return count
