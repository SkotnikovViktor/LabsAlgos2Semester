from matplotlib import pyplot as plt

fig = plt.figure()
ax = fig.subplots(1,1) 

ax.bar([1],[0.006000], label = "Без барьера", width = 0.1)
ax.bar([1.5],[0.001000], label = "С барьером", width = 0.1)


ax.legend(loc = 9)
ax.set_xlabel("Кол-во данных")
ax.set_ylabel("Потраченное время (с)")
ax.set_xticks([1,1.5])
ax.set_xticklabels(["2-000-000", "2-000-000"])

plt.show()