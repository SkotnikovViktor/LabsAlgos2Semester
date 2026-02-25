from matplotlib import pyplot as plt

fig = plt.figure()

ax = fig.subplots(1,1) 

ax.bar([1],[0.000002900 * 1e9], label = "С рекурсией", width = 0.1)
ax.bar([1.5],[0.000000600 * 1e9], label = "Без рекурсии", width = 0.1)



ax.legend(loc = 9)
ax.set_xlabel("Кол-во данных")
ax.set_ylabel("Потраченное время (нс)")
ax.set_yscale('log')
ax.set_title("Сравнение бинарного поиска с рекурсией и без")
ax.set_xticks([1,1.5])
ax.set_xticklabels(["2-000-000 (2 м)", "2-000-000 (2 м)"])

plt.show()