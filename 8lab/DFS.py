def input_matrix_sm():
    """Создание матрицы смежности"""

    count_top = int(input("Введите количество вершин: ")) 

    list_massive_pos = []



    for i in range(count_top):
        n = input("Введите значения для первой строки матрицы смежности (через пробел): ")

        list_massive_pos.append(list(map(int, n.split())))

    """Конец создания матрицы смежности, она хранится в list_massive_pos"""

    return list_massive_pos




def translate_from_matrix_sm_to_list_sm(list_massive_pos):
    """Перевод в слоарь смежности"""
    dict_smejnosti = {}

    for i in range(len(list_massive_pos)):
        for j in range(len(list_massive_pos)):
            if list_massive_pos[i][j] != 0:
                #ict_smejnosti[str(i+1)].append(j+1)
                dict_smejnosti.setdefault(str(i + 1), []).append(str(j + 1))

    """Результат получается библиотека из массивов смежных вершин """

    return dict_smejnosti




def DFS(graph, node, visite = None):
    if visite is None:
        visite = set()
    
    visite.add(node)
    path = [node]

    for nei in graph[node]:
        if nei not in visite:
            path.extend(DFS(graph, nei, visite))

    return path



print(f"Результат - {DFS(translate_from_matrix_sm_to_list_sm(input_matrix_sm()), "4")}")