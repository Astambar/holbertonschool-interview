#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """
    makeChange function
    """
    if total <= 0:
        return 0
    # Initialiser un tableau pour stocker
    # le nombre minimum de pièces pour chaque montant
    min_coins = [float('inf')] * (total + 1)
    min_coins[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                min_coins[i] = min(min_coins[i], min_coins[i - coin] + 1)

    if min_coins[total] == float('inf'):
        return -1

    return min_coins[total]
