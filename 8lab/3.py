from DFS import *

list_sm = translate_from_matrix_sm_to_list_sm(input_matrix_sm()) # Используем из прошлого файла 

"""graph - лист смежности, node - начальная вершина"""
"""Обход в ширину"""
def BFS(graph, node, visite = None):
    if visite is None:
        visite = set()


    visite.add(node)
    FIFO = [node]


    while len(FIFO) != 0:
        yzel = FIFO[0]
        del FIFO[0]
        for eni in graph[yzel]:
            if eni not in visite:
                visite.add(eni)
                FIFO.append(eni)
    

    else:
        return visite
    

print(BFS(list_sm, "1"))
