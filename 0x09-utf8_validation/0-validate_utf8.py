#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    i = 0
    for ints in data:
        if (ints > 255):
            return False

    return True
