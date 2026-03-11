#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000000 2000000 

int line_search(int *massive, int fine_element, int size){
    for (int i = 0; i < size; i++){
        if (massive[i] == fine_element){
            return i+1;
        }
    }
    return -1;
}

int main(void){
    clock_t start, end;
    double cpu_time_used;
    
    srand(time(NULL));
    
    int *massive = malloc(SIZE_2000000 * sizeof(int));
    
    for (int i = 0; i < SIZE_2000000 - 1; i++) 
        massive[i] = 1 + rand() % 100; 
    massive[SIZE_2000000 - 1] = 999;
    
    start = clock();
    int result = line_search(massive, 999, SIZE_2000000);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  

    printf("Result -> %d\n", result);
    printf("Time ->  %f second\n", cpu_time_used);

    
    free(massive);
    return 0;
}