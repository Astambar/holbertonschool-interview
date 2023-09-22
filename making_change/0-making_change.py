#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    if total < 0:
        return -1

    # Initialiser un tableau pour stocker le nombre minimum de pièces pour chaque montant
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] == float('inf'):
        return -1
    else:
        return dp[total]
