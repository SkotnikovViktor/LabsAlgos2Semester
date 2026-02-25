#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000000 2000000

int main(void){
    struct timespec start, end;
    double elapsed;

    // Заполняем массив
    int *massive_2000000 = (int*)malloc(SIZE_2000000 * sizeof(int));
    

    massive_2000000[SIZE_2000000 - 1] = 999;

    int j = 0;
    for (int i = 0; i < SIZE_2000000 - 1; i++){
        massive_2000000[i] = j++;
    }
    // Массив заполнен числами в порядке возрастания
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    // Бинарный поиск
    int find_element = 999;
    int left = 0, right = SIZE_2000000 - 1;
    int medium = left + (right - left) / 2;

    while (massive_2000000[medium] != find_element){
        medium = left + (right - left) / 2;

        if (massive_2000000[medium] < find_element){
            right = medium - 1;
        }

        else if (massive_2000000[medium] > find_element){
            left = medium + 1;
        }
    } 
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Time -> %.9f second\n", elapsed);



}