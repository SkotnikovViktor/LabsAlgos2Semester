def heapif(massive, n, i):
    larg = i # Корень дерева 
    left = 2 * i + 1 # Образвание левого дочернего поддерева 
    right = 2 * i + 2 # Образование правого дочернего поддерва

    if left < n and massive[i] < massive[left]:
        larg = left
    
    if right < n and massive[larg] < massive[right]:
        larg = right
    

    if larg != i:
        massive[i], massive[larg] = massive[larg],massive[i]
    
        heapif(massive, n, larg)


def sorting(massive):
    n = len(massive)

    for i in range(n, -1, -1):
        heapif(massive, n, i)
    
    for i in range(n - 1, 0, -1):
        massive[i], massive[0] = massive[0], massive[i]
        heapif(massive, i, 0)


massive = [9,8,7,6,5,4,3,2,1]
sorted(massive)
print(massive)


    

