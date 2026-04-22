count_top = int(input("Введите количество вершин: ")) # count_degree * degree = количество ячеек в массиве


list_massive_pos = []
count_degree = 0


for i in range(count_top):
    n = input("Введите значения для первой строки матрицы смежности (через пробел): ")
    
    count_degree += sum(map(int, n.split())) # Подсчёт степеней вершины
    list_massive_pos.append(list(map(int, n.split())))
    

if count_degree % 2 != 0:
    print("Такого графа не существует!")

elif count_degree % 2 == 0:
    print(f"Количество степеней вершины - {count_degree}\nКоличество рёбер - {count_degree // 2}")