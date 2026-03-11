#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000000 2000000


int binary_search(int *massive, int left, int right, int find_element){

    if (left > right){
        return -1;
    }

    int medium = left + (right - left) / 2;

    if (massive[medium] == find_element){
        return medium + 1; // Возвращается номер элемента 
    }

    else if (massive[medium] < find_element){
        return binary_search(massive, left, medium - 1, find_element);
    }

    else if (massive[medium] > find_element){
        return binary_search(massive, medium + 1, right, find_element);
    }
}



int main(void){
    struct timespec start, end;
    double elapsed;

    int *massive_2000000 = (int*)malloc(SIZE_2000000 * sizeof(int));


    massive_2000000[SIZE_2000000 - 1] = 999;

    int j = 0;
    for (int i = 0; i < SIZE_2000000 - 1; i++){
        massive_2000000[i] = j++;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    int result = binary_search(massive_2000000,0,SIZE_2000000-1,999);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Result -> %d\n", result);
    printf("Time -> %.9f second\n", elapsed);

}