#!/usr/bin/env python3
def find_duplicate(list_of_integers):
    # Find the intersection point of the two runners (tortoise and hare).
    tortoise = list_of_integers[0]
    hare = list_of_integers[0]
    while True:
        tortoise = list_of_integers[tortoise]
        hare = list_of_integers[list_of_integers[hare]]
        if tortoise == hare:
            break

    # Find the "entrance" to the cycle.
    ptr1 = list_of_integers[0]
    ptr2 = tortoise
    while ptr1 != ptr2:
        ptr1 = list_of_integers[ptr1]
        ptr2 = list_of_integers[ptr2]

    return ptr1

print(find_duplicate([1,3,4,2,2]))
print(find_duplicate([3,1,3,4,2]))