#include <iostream>
#include <vector>

int findNonMaxOrMin(std::vector<int> nums) {
    int numsSize = nums.size();
    if(numsSize  < 3) {
        return -1; 
    }

    int min_val = nums[0];
    int max_val = nums[1];

    for(auto i : nums) {
        if(i < min_val) {
            min_val = i;
        }
        if(i > min_val) {
            max_val = i;
        }
    }

    for(auto i : nums) {
        if(i != min_val && i != max_val) {
            return i;
        }
    }

    return -1;

}

int findNonMaxOrMin1(std::vector<int> nums) {
    int numsSize = nums.size();
    if (numsSize < 3) return -1;
    int min_val = nums[0];
    int max_val = nums[1];

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != min_val && nums[i] != max_val) {
            return nums[i];
        }
    }
    return -1;
}


int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int result = findNonMaxOrMin(nums); 
    if(result != -1) {
        std::cout << "the number is " << result << std::endl;
    } else {
        std::cout << "Not found such number!" << std::endl;
    }
    
}

