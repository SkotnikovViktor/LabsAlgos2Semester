import random

count_delen = 0
count_sr = 0 


def quicksort(arr):
    global count_sr, count_delen
    if len(arr) <= 1:
        return arr
    count_sr += 1


    #pivot = arr[len(arr) // 2] # Опорный элемент - средний
    #pivot = arr[0] # Опорный элемент - первый 
    pivot = arr[-1] # Опорный элемент - последний     
    
    left  = [x for x in arr if x < pivot]
    mid   = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    count_delen += 3



    return quicksort(left) + mid + quicksort(right)



def getter():
    return [count_sr, count_delen]