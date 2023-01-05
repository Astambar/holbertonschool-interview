#!/usr/bin/python3
"""
file creation minOperations
"""


def minOperations(n):
    """minOperation"""
    if n == 1 or n == 0:
        return 0

    total = 0
    for i in range(2, n+1):
        found_factor = False
        while n % i == 0:
            found_factor = True
            n = n / i
            total += i
        if not found_factor:
            break
    return total

