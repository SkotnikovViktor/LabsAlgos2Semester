#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void gnom_sort(int *massive, int len_massive) {
    int index = 0;
    
    while (index < len_massive) {
        if (index == 0 || massive[index] >= massive[index - 1]) {
            index++;
        } else {
            int temp = massive[index];
            massive[index] = massive[index - 1];
            massive[index - 1] = temp;
            index--;
        }
    }

    for (int i = 0; i < len_massive; i++){
        printf(" %d ", massive[i]);
    }
}


int main(void){
    int massive[5] = {7,1,5,3,7};
    int len_massive = sizeof(massive) / sizeof(massive[0]);
    gnom_sort(massive, len_massive);
}
