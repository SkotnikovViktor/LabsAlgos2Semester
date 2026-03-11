#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ShakerSort(int *massive, int len_massive){
    int left = 0;
    int right = len_massive - 1;

    while (left < right){
        int swap = 0;
        int last_swap = left;

        for (int i = left; i < right; i++){
            if (massive[i] > massive[i + 1]){
                int t = massive[i];
                massive[i] = massive[i + 1];
                massive[i + 1] = t;
                swap = 1;
                last_swap = i;

            }
        }

        right = last_swap;
        if (swap == 0){
            break;
        }
        swap = 0;
        


        for (int i = right; i > left; i--){
            if (massive[i - 1] > massive[i]){
                int t = massive[i];
                massive[i] = massive[i - 1];
                massive[i - 1] = t;
                swap = 1;
                last_swap = i - 1;
            }
        }

        left = last_swap;
        if (swap == 0){
            break;
        }

    }

    for (int i = 0; i < len_massive; i++){
        printf(" %d ", massive[i]);
    }

}


int main(void){
    int massive[5] = {5,9,100,8,11};
    int len_massive = sizeof(massive) / sizeof(massive[0]);
    ShakerSort(massive, len_massive);
    


}