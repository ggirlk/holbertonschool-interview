#!/usr/bin/python3
""" doc """
import sys

i = 0
status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
fileSize = 0
for line in sys.stdin:
    words = line.split()
    if words[-2] in status.keys():
        status[words[-2]] += 1
    fileSize += int(words[-1])
    i += 1
    if i == 10 or line == "^C":
        i = 0
        print("File size: {}".format(fileSize))
        fileSize = 0
        for key in status:
            if status[key] != 0:
                print("{}: {}".format(key, status[key]))
