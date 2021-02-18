#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    try:
        bytes(data).decode("utf-8")
        return True
    except:
        return False

        """if (ints.bit_length() >= 8):
            return False"""

    return True
