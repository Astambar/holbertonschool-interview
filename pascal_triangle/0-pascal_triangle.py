#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""triangle de pascal"""


def pascal_triangle(n):
    """
    Construit le triangle de Pascal jusqu'à la ligne n.

    Args:
        n (int): Le nombre de lignes du triangle de Pascal à construire.

    Returns:
        list: Le triangle de Pascal sous la forme d'une liste de listes.
    """
    if n <= 0:
        return []  # Retourne un tableau vide si n est inférieur ou égal à 0

    triangle = construire_triangle(n)
    return triangle


def construire_triangle(n):
    """
    Construit le triangle de Pascal jusqu'à la ligne n.

    Args:
        n (int): Le nombre de lignes du triangle de Pascal à construire.

    Returns:
        list: Le triangle de Pascal sous la forme d'une liste de listes.
    """
    triangle = []
    for i in range(n):
        ligne = construire_ligne(i)
        triangle.append(ligne)
    return triangle


def construire_ligne(n):
    """
    Construit une ligne du triangle de Pascal.

    Args:
        n (int): L'indice de la ligne à construire.

    Returns:
        list: La ligne du triangle de Pascal sous la forme d'une liste.
    """
    ligne = [1] * (n + 1)
    if n >= 2:
        for j in range(1, n):
            ligne[j] = calculer_coefficient(n, j)
    return ligne


def calculer_coefficient(n, k):
    """
    Calcule le coefficient binomial C(n, k) du triangle de Pascal.

    Args:
        n (int): La valeur de n du coefficient binomial.
        k (int): La valeur de k du coefficient binomial.

    Returns:
        int: Le coefficient binomial C(n, k).
    """
    coefficient = factorielle(n) // (factorielle(k) * factorielle(n - k))
    return coefficient


def factorielle(n):
    """
    Calcule la factorielle d'un nombre.

    Args:
        n (int): Le nombre dont on souhaite calculer la factorielle.

    Returns:
        int: La factorielle de n.
    """
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorielle(n - 1)
