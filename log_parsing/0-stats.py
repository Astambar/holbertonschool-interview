#!/usr/bin/python3
"""log_parsing"""

import sys


def parse_line(line, total_size, status_codes):
    """Parse une ligne de log"""
    data = line.split()
    try:
        size = int(data[-1])
        total_size += size
    except ValueError:
        pass
    try:
        status = data[-2]
        if status in status_codes:
            status_codes[status] += 1
    except IndexError:
        pass
    return total_size, status_codes


def print_stats(total_size, status_codes):
    """Affiche les statistiques"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def parse_logs():
    """Parse les logs depuis stdin"""
    total_size = 0
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }
    line_count = 0
    try:
        for line in sys.stdin:
            line_count += 1
            total_size, status_codes = parse_line(line,
                                                  total_size,
                                                  status_codes)
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)
        print_stats(total_size, status_codes)
    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise


if __name__ == '__main__':
    parse_logs()
