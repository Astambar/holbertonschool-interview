#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""_summary_

Returns:
    _type_: _description_
"""
import sys

def is_safe(board, row, col):
    # Vérifie si une reine peut être placée en (row, col) sur le plateau
    for i in range(row):
        if board[i] == col or board[i] - col == i - row or board[i] - col == row - i:
            return False
    return True

def solve_nqueens(board, row, n):
    # Résout le problème des N reines en utilisant le backtracking
    if row == n:
        print(board)
        return

    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, n)

if __name__ == "__main__":
    # Vérification des arguments de ligne de commande
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Création d'un plateau de taille N × N initialisé avec des zéros
    board = [0] * n

    # Résolution du problème des N reines
    solve_nqueens(board, 0, n)
