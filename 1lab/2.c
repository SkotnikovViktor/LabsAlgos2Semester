#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000 2000

int line_search_with_barier(int *massive, int element_search){
    int end_element = massive[SIZE_2000 - 1]; // Сохраняем последний элемент массива
    massive[SIZE_2000 - 1] = element_search; // Записываем вместо последнего элемента массива, наш искомый элемент
    
    int i = 0;
    while (massive[i] != element_search){ // Перебираем все элементы, пока не встретим искомый
        i++;
    }

    if (i < (SIZE_2000 - 1) || end_element == element_search){
        // Идёт проверка, если элемент встретился раньше, чем в конце массива
        // ИЛИ последний оригинального массива равен искомому 
        return i+1; // Возвращаем номер, а не номер элемента!!
    }

    return -1; // Если не найдено, то возвращаем -1


}


int main(void){
    
    srand(time(NULL));
    int massive_2000[SIZE_2000];

    for (int i = 0; i < SIZE_2000 - 1; i++) massive_2000[i] = 1 + rand() % 100; massive_2000[SIZE_2000 - 1] = 999;

    printf("Number finder element - %d", line_search_with_barier(massive_2000, 999));
}