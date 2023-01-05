#!/usr/bin/python3
"""
file creation minOperations
"""


def minOperations(n):
    """
    method minOperations
    """
    if n == 1 or n == 0:
        return 0

    init = 2
    count = 0

    while n > 1:
        if n % init == 0:
            n = n / init
            count += init
        else:
            init += 1
    return count

