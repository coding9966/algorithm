#include <stdio.h> 

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_arry_to_max_number(int array[], int len) {
    for(int i = 1; i < len; ++i) {
        for(int j = 0; j < len - i; ++j) {
            if(array[j] < array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main() {
    int array[] = {1, 3, 2, 65, 102};
    int len = sizeof(array) / sizeof(array[0]);
    sort_arry_to_max_number(array, len);
    for(int i = 0; i < len; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
}