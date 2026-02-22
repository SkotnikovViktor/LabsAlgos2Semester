#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000 2000

int main(void){
    // Заполняем массив
    int massive_2000[SIZE_2000];
    

    massive_2000[SIZE_2000 - 1] = 999;

    int j = 0;
    for (int i = 0; i < SIZE_2000 - 1; i++){
        massive_2000[i] = j++;
    }
    // Массив заполнен числами в порядке возрастания
    
    // Бинарный поиск
    int find_element = 999;
    int left = 0, right = SIZE_2000 - 1;
    int medium = left + (right - left);

    while (massive_2000[medium] != find_element){
        medium = left + (right - left);

        if (massive_2000[medium] < find_element){
            right = medium - 1;
        }

        else if (massive_2000[medium] > find_element){
            left = medium + 1;
        }
    } 

    printf("number - %d", medium + 1);



}