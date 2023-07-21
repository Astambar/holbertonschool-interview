#!/usr/bin/python3
"""_0-rain.py_
"""


def rain(walls):
    """
    Calcule le nombre d'unités carrées d'eau
      qui seront retenues après la pluie.
    """
    left = 0
    right = len(walls) - 1
    left_max = right_max = total_rain = 0

    while left <= right:
        if walls[left] <= walls[right]:
            if walls[left] > left_max:
                left_max = walls[left]
            else:
                total_rain += left_max - walls[left]
            left += 1
        else:
            if walls[right] > right_max:
                right_max = walls[right]
            else:
                total_rain += right_max - walls[right]
            right -= 1

    return total_rain
