#!/usr/bin/python3
"""
Fichier de création min opération
"""


def minOperations(n):
    """
    fonction en opération minimal
    """
    if n == 1 or n == 0:
        return 0

    count = 0
    divisible = False
    result = n

    for i in range(2, n+1):
        if result % i == 0:
            divisible = True
            result = result / i
            count += i
        else:
            if divisible:
                divisible = False
                result = n
            else:
                continue
    return count
