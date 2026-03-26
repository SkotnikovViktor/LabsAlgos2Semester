import time


def shell_sort(massive):

    gap = len(massive) // 2
    count_move  = 0
    count_pere = 0


    while gap > 0:

        for i in range(gap, len(massive)):
            massive_value = massive[i]
            posit = i

            if massive[posit - gap] <= massive_value:
                count_pere += 1 # Количество сравнений 

            while posit >= gap and massive[posit - gap] > massive_value:
                massive[posit] = massive[posit - gap]
                posit -= gap
                massive[posit] = massive_value
                count_move += 1 # Количество перестановок
                count_pere += 1 # Количество сравнений успешных
    
        gap //= 2

    return [count_move, count_pere, massive]


massive = [i for i in range(2**15)][::-1]

start_time = time.time()
result = shell_sort(massive)
end_time = time.time()

print(f"Время выполнения - {end_time - start_time}\nКоличество сравнений - {result[1]}\nКоличество перестановок - {result[0]}")




# O(n * log n)
# O(n ^ 1.25)
# O(n ^ 2)
