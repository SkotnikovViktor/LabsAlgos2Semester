#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2000 2000


int binary_search(int *massive, int left, int right, int find_element){

    int medium = left + (right - left);

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
    int massive_2000[SIZE_2000];
    

    massive_2000[SIZE_2000 - 1] = 999;

    int j = 0;
    for (int i = 0; i < SIZE_2000 - 1; i++){
        massive_2000[i] = j++;
    }

    printf("%d", binary_search(massive_2000,0,SIZE_2000-1,999));


}