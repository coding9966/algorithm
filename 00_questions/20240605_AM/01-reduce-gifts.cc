/*
New Year's Day is around the corner and AM company is having a sale. They have a list of items they are
considering but they may need to remove some of them. Determine the minimum number of items to remove from
an array of prices so that the sum of prices of any k items does not exceed a threshold.
Note: If the number of items in the list is less than k, then there is no need to remove any more items.
Example
prices = [3, 2, 1, 4, 6, 5]
k=3
threshold = 14
*/

#include <bits/stdc++.h>
using namespace std;

int reduceGifts(vector<int> prices, int k, int threshold) {
    
    int res = 0;
    int sum = 0;
    int n = prices.size();

    if(n < k) return res;   //No need to remove any items
    if(k <= 0 || threshold <= 0) return res;    //Invalid input

    sort(prices.begin(), prices.end());
    for(auto price : prices) {
        sum += price;
    }

    if(sum <= threshold) return res; // if the total sum no more than threshold, no need to remove an items

    for(int i = n - 1; i >= 0; i--) {
        int windowSum = 0;
        for(int j = 0; j < k; j++) {
            windowSum += prices[i - j];
        }
        if(windowSum <= threshold) {
            return res;
        } else {
            res++;
        }
    }

    return res;
}

int main() {

    vector<int> prices1 = {1, 1, 1, 1, 1};
    int k1 = 6, threshold1 = 8;  //output should be 0
    cout << reduceGifts(prices1, k1,threshold1) << endl;

    vector<int> prices2 = {1, 1, 1, 1, 1};
    int k2 = 3, threshold2 = 8;  //output should be 0
    cout << reduceGifts(prices2, k2,threshold2) << endl;

    vector<int> prices3 = {5, 3, 4, 1, 2};
    int k3 = 3, threshold3 = 10;  //number 5 should be removed, output should be 1
    cout << reduceGifts(prices3, k3,threshold3) << endl;

    vector<int> prices4 = {5, 3, 4, 1, 2};
    int k4 = 3, threshold4 = 8;  //number 4 and 5 should be removed, output should be 2
    cout << reduceGifts(prices4, k4,threshold4) << endl;

    return 0;
}