#!/usr/bin/python3
"""minOperations(n) """


def prime_factors(n):
    """Trouve les facteurs premiers de n.

    Args:
        n (int): Le nombre dont on veut trouver les facteurs premiers.

    Returns:
        list: La liste des facteurs premiers de n.
    """
    factors = []
    factor = 2

    while factor * factor <= n:
        while n % factor == 0:
            factors.append(factor)
            n //= factor
        factor += 1

    if n > 1:
        factors.append(n)

    return factors


def minOperations(n):
    """Calcule le nombre minimum d'opérations pour obtenir n caractères H.

    L'éditeur de texte ne peut exécuter que deux opérations :
        Copier tout et Coller.

    Args:
        n (int): Le nombre de caractères H à obtenir.

    Returns:
        int: Le nombre minimum d'opérations pour obtenir n caractères H.
             Si n est impossible à atteindre, renvoie 0.
    """
    if n <= 1:
        # Il est impossible d'obtenir un nombre de caractères H
        # inférieur ou égal à 1
        return 0

    # Trouver les facteurs premiers de n
    factors = prime_factors(n)

    # Le nombre minimum d'opérations est égal
    # à la somme des facteurs premiers de n
    return sum(factors)
