#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    for ints in data:
        if (ints.bit_length() > 8):
            return False
        if (ints <= 0):
            return False
    return True
