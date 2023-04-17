#!/usr/bin/env python3
def area(array):
    lenarray=len(array)
    maxvalue=0
    maxvalue2=0
    for i in range(lenarray):
        increment=i
        if array[i] > maxvalue:
            maxvalue = array[i]
            break
    for j in range(lenarray):
        if j != increment and array[j] > maxvalue2:
            maxvalue2=array[j]
    print(maxvalue2)

area([1,2,3,2])