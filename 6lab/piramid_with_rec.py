import time
import random

def heapify(arr: list, n, i):

    largest = i         
    left = 2 * i + 1     
    right = 2 * i + 2   


    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):

    n = len(arr)


    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)


    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    return arr

n = [1000,2000,3000,4000,5000]

start = time.time()
result = heap_sort([random.randint(0,5000) for  x in range(n[4])])
end = time.time()



print(f"Результат - {result}\nВремя выполнения - {end - start}")