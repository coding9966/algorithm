#include <stdio.h>
#include <stdlib.h>


int max (int a, int b) {
    return a > b ? a : b;
}

int findClosestNumber(int* nums, int numsSize) {
    int res = nums[0];
    int dis = abs(nums[0]);
    for(int i = 0; i < numsSize; i++) {
        if(abs(nums[i]) < dis) {
            dis = abs(nums[i]);
            res = nums[i];
        } else if(nums[i] == dis) {
            res = max(nums[i], res);
        }
    }
    return res;
}

int main() {
    //int nums[] = {-4,-2,1,4,8};
    int nums[] = {-10,-12,-54,-12,-544,-10000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int res = findClosestNumber(nums, numsSize);
    printf("the closest number is : %d\n", res);
}