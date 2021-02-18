#!/usr/bin/python3
""" doc """


def validUTF8(data):
    """ doc """
    try:
        maskeddata = []
        for n in data:
            maskeddata.append((n & 255))  
        bytes(maskeddata).decode("UTF-8")
        return True
    except:
        return False
