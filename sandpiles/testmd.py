#!/usr/bin/env python3


def double(list_integer):
    list_integer = []
    new_list = []
    for i in range(1, len(list_integer)):
        for j in range (0, i+1):
            if (list_integer[j] == new_list[i]):
                return list_integer[i]
        new_list.append(list_integer[i])
    return 0


print(double([1, 2, 3, 4, 2]))