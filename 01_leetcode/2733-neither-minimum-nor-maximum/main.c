#include <stdio.h>

int findNonMinOrMax(int* nums, int numsSize){
    if(numsSize < 3) return -1;
    int min_val = nums[0];
    int max_val = nums[0];
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] < min_val) {
            min_val = nums[i];
        }
        if(nums[i > max_val]) {
            max_val = nums[i];
        }
    }
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != min_val && nums[i] != max_val)
            return nums[i];
    }
    return -1;
}

int main() {

    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = findNonMinOrMax(nums, size);
    if(result != -1) {
        printf("Selected nums is : %d\n", result);
    } else {
        printf("No such number found. \n");
    }

    return 0;
}