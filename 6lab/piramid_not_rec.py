import time
import random

def heapify_iterative(arr: list, n: int, i: int) -> None:
    while True:
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2


        if left < n and arr[left] > arr[largest]:
            largest = left
        if right < n and arr[right] > arr[largest]:
            largest = right

   
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            i = largest  
        else:
            break  


def heap_sort(arr: list) -> list:
    n = len(arr)


    for i in range(n // 2 - 1, -1, -1):
        heapify_iterative(arr, n, i)


    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        heapify_iterative(arr, i, 0)         

    return arr


n = [1000,2000,3000,4000,5000]

start = time.time()
result = heap_sort([random.randint(0,5000) for  x in range(n[4])])
end = time.time()



print(f"Результат - {result}\nВремя выполнения - {end - start}")