#!/usr/bin/python3
def minOperations(n):
    operations = 0
    # Set the current number of characters in the file to 1
    current_characters = 1
    while current_characters < n:
        # Paste the current contents of the file
        current_characters *= 2
        operations += 1
    if current_characters > n:
        # Copy all the characters in the file
        operations += 1
    return operations
