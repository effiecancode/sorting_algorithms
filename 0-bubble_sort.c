#include "sort.h"


void bubble_sort(int *array, size_t size) {
    
    size_t i;
    
    for (i = 0; i < size - 1; ++i) {
        int swapped = 0;
        size_t j;

        for (j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }    
}      

void print_array(int *array, size_t size){
    size_t i;

    for (i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }

}
