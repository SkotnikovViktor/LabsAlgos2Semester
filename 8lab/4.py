dict_smejnosti = {}

count_top = int(input("Введите количество вершин графа: "))

for top in range(count_top):
    all_incedent_top_for_input_top = map(str, input(f"Введите(через пробел) все инцидентные вершины для вершины - {top + 1}: ").split(" "))
    dict_smejnosti.setdefault(str(top + 1), []).extend(list(all_incedent_top_for_input_top))

print(dict_smejnosti)


