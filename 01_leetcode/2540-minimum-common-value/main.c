#include <stdio.h>
#include <stdlib.h>

//use two pointer in each array.
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int l1 = 0, l2 = 0, r1 = nums1Size - 1, r2 = nums2Size - 1;

    while (l1 <= r1 && l2 <= r2) {
        if (nums1[l1] == nums2[l2]) {
            return nums1[l1];
        }

        if (nums1[l1] < nums2[l2]) {
            l1++;
        } else {
            l2++;
        }

        if (nums1[r1] < nums2[r2]) {
            r2--;
        } else if (nums1[r1] == nums2[r2]) {
            // do nothing
        } else {
            r1--;
        }
    }

    return -1;
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {3, 4, 5, 6, 7};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int common = getCommon(nums1, nums1Size, nums2, nums2Size);
    if (common != -1) {
        printf("Common element: %d\n", common);
    } else {
        printf("No common element found\n");
    }
    return 0;
}
