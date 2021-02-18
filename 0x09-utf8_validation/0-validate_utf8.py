#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    if data:
        try:
            bytes(data).decode("UTF-8")
            return True
        except:
            return False
    return False
