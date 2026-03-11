#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>




void odd_even(int *massive, int len_massive) {
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

    for (int i = 0; i < len_massive; i++){
        printf(" %d ", massive[i]);
    }
    
}


int main(void){
    int massive[5] = {5,9,100,8,11};
    int len_massive = sizeof(massive) / sizeof(massive[0]);
    odd_even(massive, len_massive);
    


}