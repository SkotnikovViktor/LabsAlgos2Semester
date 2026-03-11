#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define BASE 100

int bubble_sort(int *massive, int len_massive){
    int flag = 0;
    for (int i = 0; i < len_massive; i++){
        for (int j = 0; j <= len_massive - i - 1; j++){
            if (massive[j] >= massive[j + 1]){
                int t = massive[j];
                massive[j] = massive[j + 1];
                massive[j + 1] = t;
                flag = 1;
            }
        }

        if (flag == 0){
            printf("No need sorting%d\n",flag);
            break;
        }

    }

}






int shaker_sort(int *massive, int len_massive){
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


}




void odd_even_sort(int *massive, int len_massive) {
    if (len_massive <= 1) return;
    
    bool sorted = false;
    int last_swap = len_massive - 1; 
    
    while (!sorted) {
        sorted = true;
        

        for (int i = 0; i < last_swap; i += 2) {
            if (massive[i] > massive[i + 1]) {
                int temp = massive[i];
                massive[i] = massive[i + 1];
                massive[i + 1] = temp;
                sorted = false;
            }
        }
        
   
        for (int i = 1; i < last_swap; i += 2) {
            if (massive[i] > massive[i + 1]) {
                int temp = massive[i];
                massive[i] = massive[i + 1];
                massive[i + 1] = temp;
                sorted = false;
            }
        }
        
        while (last_swap > 0 && massive[last_swap - 1] <= massive[last_swap]) {
            last_swap--;
        }
    }


    
}



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


}


double checker(int *massive, int len_massive, int key){
    struct timespec start, end;
    double elapsed;

    if (key == 1){
        clock_gettime(CLOCK_MONOTONIC, &start);
        bubble_sort(massive, len_massive);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Bubble sort - %.9f\n", elapsed);

    }

    else if (key == 2){
        clock_gettime(CLOCK_MONOTONIC, &start);
        shaker_sort(massive, len_massive);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Shaker sort - %.9f\n", elapsed);
    }

    else if (key == 3){
        clock_gettime(CLOCK_MONOTONIC, &start);
        odd_even_sort(massive, len_massive);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("OddEven sort - %.9f\n", elapsed);
    }

    else if (key == 4){
        clock_gettime(CLOCK_MONOTONIC, &start);
        gnom_sort(massive, len_massive);
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) + 
              (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("Gnom sort - %.9f\n", elapsed);
    }

    return 0;


}



int main(void){
    srand(time(NULL));
    // 1 - bubble
    // 2 - shaker
    // 3 - odd_even
    // 4 - gnom

    int massive[6] = {0};
    for (int i = 0; i < 100; i++){
        massive[i] = 1 + rand() % 100;
    }
    int len_massive = sizeof(massive) / sizeof(massive[0]);
    for (int i = 1; i <= 4; i++){
        checker(massive, len_massive, i);
    }


}