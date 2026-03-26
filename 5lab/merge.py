# Сортировка слиянием

def delenie(massive):
    if len(massive) <= 1:
        return massive

    med = len(massive) // 2

    left = massive[:med]
    right = massive[med:]

    left = delenie(left)
    right = delenie(right)

    return merge(left, right)


def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])

    return result


massive = [10,9,8,7,6,5,4,3,2,1]
sorted_massive = delenie(massive)
print(sorted_massive)

    

    
