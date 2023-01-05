#!/usr/bin/python3
def minOperations(n):
    """
    fonction minOperation
    """
    operations = 0
    current_characters = 1
    while current_characters < n:
        current_characters *= 2
        operations += 1
    if current_characters > n:
        operations += 1
    return operations
