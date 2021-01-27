#!/usr/bin/python3
""" doc """
import sys


if __name__ == "__main__":
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

    def printstats(fileSize, status):
        """ doc """
        print("File size: {}".format(fileSize))
        for key in status:
            if status[key] != 0:
                print("{}: {}".format(key, status[key]))
        return 0

    try:
        for line in sys.stdin:
            words = line.split()
            if len(words) > 2:
                i += 1
            if words[-2] in status.keys():
                status[words[-2]] += 1
            fileSize += int(words[-1])

            if i == 10:
                printstats(fileSize, status)
                i = 0
            
    except KeyboardInterrupt:
        printstats(fileSize, status)
        raise
