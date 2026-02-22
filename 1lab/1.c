#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define SIZE_2000 2000 

int line_search(int *massive, int fine_element, int size){

    for (int i = 0; i < size; i++){
        if (massive[i] == fine_element){
            return i+1;
        }
    }

    return -1;
}


int main(void){

    srand(time(NULL));


    int massive_2000[SIZE_2000];

    for (int i = 0; i < SIZE_2000 - 1; i++) massive_2000[i] = 1 + rand() % 100; massive_2000[SIZE_2000 - 1] = 999;

    printf("%d\n",line_search(massive_2000, 999, SIZE_2000));

}