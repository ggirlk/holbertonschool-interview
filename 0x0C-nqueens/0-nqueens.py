#!/usr/bin/env python3
""" N queens """
import sys


if __name__ == '__main__':
    if len(sys.argv) > 1:
        try:
            board_size = int(sys.argv[1])
        except Exception:
            print("N must be a number\n")
            exit(1)
        if board_size < 4:
            print("N must be at least 4\n")
            exit(1)

    else:
        print("Usage: nqueens N\n")
        exit(1)
