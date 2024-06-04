#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort_array_to_max_number(vector<int>& array) {
    for(int i = 1; i < array.size(); i++) {
        for(int j = 0; j < array.size() - i; j++) {
            if(array[j] < array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main() {
    vector<int> array= {3, 1, 65, 10};    

    sort_array_to_max_number(array);

    // Print the sorted array
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
