#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASSIVE_SIZE 5




int main(void){
    srand(time(NULL));
    int massive[MASSIVE_SIZE];

    // Вывод массива до сортировки
    for (int i = 0; i < MASSIVE_SIZE; i++){
        massive[i] = 1 + rand() % 1000;
        printf(" %d ", massive[i]);
    }
    
    printf("\n");

    // Сортировка пузырём с адаптацией
    int flag = 0;
    for (int i = 0; i < MASSIVE_SIZE; i++){
        for (int j = 0; j <= MASSIVE_SIZE - i - 1; j++){
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


    printf("\n");

    
    // Вывод массива после сортировки
    for (int i = 0; i < MASSIVE_SIZE; i++){
        printf(" %d ", massive[i]);
    }

}