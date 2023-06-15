#!/usr/bin/python3
"""N queens problem
This program solves the N queens problem by finding all possible configurations
of an N-sized chessboard where the queens do not attack each other.

Usage: nqueens N

where N is an integer greater than or equal to 4.
"""

import sys

def solve_nqueens(board_size):
    """Solve the N queens problem using recursion."""
    solutions = []
    solve(board_size, 0, [], solutions)
    return solutions

def solve(board_size, row, queens, solutions):
    """Recursively solve the N queens problem."""
    if row == board_size:
        solutions.append(queens.copy())
        return

    for col in range(board_size):
        if is_safe(row, col, queens):
            queens.append((row, col))
            solve(board_size, row + 1, queens, solutions)
            queens.pop()

def is_safe(row, col, queens):
    """Check if the queen is safe from other queens."""
    for (r, c) in queens:
        if row == r or col == c or abs(row - r) == abs(col - c):
            return False
    return True

def print_solutions(solutions):
    """Print the solutions in a readable format."""
    for solution in solutions:
        formatted_solution = [[row, col] for (row, col) in solution]
        print(formatted_solution)

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        board_size = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if board_size < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(board_size)
    print_solutions(solutions)

if __name__ == "__main__":
    main()
