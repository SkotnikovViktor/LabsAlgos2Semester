def heapify(arr: list, n: int, i: int) -> None:

    largest = i          # Изначально считаем корень наибольшим
    left = 2 * i + 1     # Левый потомок
    right = 2 * i + 2    # Правый потомок

    # Если левый потомок существует и больше корня
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Если правый потомок существует и больше текущего наибольшего
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Если наибольший элемент не корень, меняем их местами
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        # Рекурсивно вызываем heapify для затронутого поддерева
        heapify(arr, n, largest)


def heap_sort(arr: list) -> list:

    n = len(arr)

    # 1. Построение max-кучи
    # Начинаем с последнего нелистового узла и двигаемся к корню
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # 2. Поочередное извлечение максимальных элементов
    for i in range(n - 1, 0, -1):
        # Перемещаем текущий корень (максимум) в конец массива
        arr[i], arr[0] = arr[0], arr[i]
        # Восстанавливаем свойство кучи для уменьшенного массива
        heapify(arr, i, 0)

    return arr


print(heap_sort([9,8,7,6,5,4,3]))