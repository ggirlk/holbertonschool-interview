#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    if type(data) is not list:
        return False
    for ints in data:
        if (ints.bit_length() > 8
            or type(ints) is not int):
             return False
    return True
