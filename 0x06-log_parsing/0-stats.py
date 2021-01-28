#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    num = 0

    def printStats(status_codes, total_size):
        """ doc """
        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            print("{}: {:d}".format(c, status_codes[c]))
    try:
        for line in sys.stdin:
            parsed = line.split()

            if len(parsed) >= 2:
                total_size += int(parsed[-1])
                code = int(parsed[-2])

                if code in status_codes.keys():
                    status_codes[code] += 1
                else:
                    status_codes[code] = 1
                num += 1
                if (num % 10 == 0):
                    printStats(status_codes, total_size)

        printStats(status_codes, total_size)
    except KeyboardInterrupt:
        printStats(status_codes, total_size)
        raise

