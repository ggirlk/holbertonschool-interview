#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    for ints in data:
        k = (ints.bit_length() << 7)
        if k > 1024:
            return False

        """if (ints.bit_length() >= 8):
            return False"""

    return True
