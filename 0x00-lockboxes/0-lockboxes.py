#!/usr/bin/python3
"""lockboxes function unlocked boxe"""


def canUnlockAll(boxes):
    """
    The canUnlockAll function checks if all boxes can be unlocked.
    It takes a list of lists as an argument and returns True or False.

    :param boxes: Store the boxes
    :return: True if all boxes can be unlocked
    :doc-author: Trelent
    """

    keys = [0]
    lenboxe = len(boxes)

    for idx, box in enumerate(boxes):
        if box:
            for key in box:
                if key not in keys and key != idx and key < lenboxe:
                    keys.append(key)
    return len(keys) == lenboxe
