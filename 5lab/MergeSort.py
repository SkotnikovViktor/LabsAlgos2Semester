import random

count_delen = 0
count_sr = 0 

def delenie(massive):
    global count_delen, count_sr
    if len(massive) <= 1:
        return massive
    count_sr += 1

    med = len(massive) // 2

    left = massive[:med]
    right = massive[med:]
    count_delen += 2

    left = delenie(left)
    right = delenie(right)


    return merge(left, right)


def merge(left, right):
    global count_sr
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        
        else:
            result.append(right[j])
            j += 1
        
        count_sr += 3

    
    result.extend(left[i:])
    result.extend(right[j:])

    return result




def getter():
    return [count_sr, count_delen]
    
