#!/usr/bin/python3
"""Log parsing."""

import sys

TOTAL_SIZE = 0
STATUS_CODES = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
LINE_COUNT = 0


def print_stats():
    """Print statistics."""
    print("File size: {}".format(TOTAL_SIZE))
    for code in sorted(STATUS_CODES.keys()):
        if STATUS_CODES[code] > 0:
            print("{}: {}".format(code, STATUS_CODES[code]))


try:
    for line in sys.stdin:
        LINE_COUNT += 1
        data = line.split()
        try:
            size = int(data[-1])
            TOTAL_SIZE += size
        except ValueError:
            pass
        try:
            status = data[-2]
            if status in STATUS_CODES:
                STATUS_CODES[status] += 1
        except IndexError:
            pass
        if LINE_COUNT % 10 == 0:
            print_stats()
    print_stats()
except KeyboardInterrupt:
    print_stats()
    raise
