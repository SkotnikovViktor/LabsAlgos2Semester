import time

def rach_sort(massive):

    n = len(massive)
    gaps = n
    swapped = True

    while gaps > 1 or swapped:

        if gaps > 1:
            gaps = int(gaps / 1.3)

        swapped = False
        
        for i in range(n - gaps):
            if massive[i] > massive[i + gaps]:
                massive[i], massive[i + gaps] = massive[i + gaps], massive[i]
                swapped = True
    
    return []


massive = [i for i in range(2**15)][::-1] 


start_time = time.time()
result = rach_sort(massive)
end_time = time.time()

print(f"Время выполнения - {end_time - start_time}\nКоличество сравнений - {result[1]}\nКоличество перестановок - {result[0]}")

# O(n * log n)
# O(n^2 / 2)
# O(n ^ 2)