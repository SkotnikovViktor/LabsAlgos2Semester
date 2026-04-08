import MergeSort
import QuckSort
import random
import time


for i in range(4):
    massive = [random.randint(0, i* 500) for x in range(i * 100)]
    start = time.time()
    b = QuckSort.quicksort(massive)
    end = time.time()
    print(f"Количество элементов - {len(massive)}\nВремя выполнения - {end - start}")


