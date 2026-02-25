#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000000 200000

int line_search_with_barier(int *massive, int element_search, int size){
    int end_element = massive[size - 1]; // Сохраняем последний элемент массива
    massive[size - 1] = element_search; // Записываем вместо последнего элемента искомый элемент
    
    int i = 0;
    while (massive[i] != element_search){ // Перебираем элементы, пока не встретим искомый
        i++;
    }
    
    
    massive[size - 1] = end_element;

    if (i < (size - 1) || end_element == element_search){
        return i + 1; 
    }

    return -1; 
}

int main(void){
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    

    int *massive_2000000 = (int*)malloc(SIZE_2000000 * sizeof(int));
    

    for (int i = 0; i < SIZE_2000000 - 1; i++) {
        massive_2000000[i] = 1 + rand() % 100;
    }
    massive_2000000[SIZE_2000000 - 1] = 999;
    

    

    start = clock();
    int result = line_search_with_barier(massive_2000000, 999, SIZE_2000000);
    end = clock();

    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Time -> %f second\n", cpu_time_used);


    free(massive_2000000);
    
    return 0;
}