// O(n) solution for finding maximum sum of
// a subarray of size k with O(k) space

#include <bits/stdc++.h>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// k must be smaller than n
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	// Create Queue
	queue<int> q;

	int m = INT_MIN;
	int su = 0;

	// Compute sum of first k elements and also
	// store then inside queue
	for (int i = 0; i < k; i++) {
		q.push(arr[i]);
		su += arr[i];
	}

	for (int i = k; i < n; i++) {
		su -= q.front();
		q.pop();
		q.push(arr[i]);
		su += arr[i];
		m = max(m, su);
	}

	return m;
}

// Driver code
int main()
{
	int arr[] = {100, 200, 300, 400 };
	int k = 2;
    //int arr[] = {400, 300, 200, 100};
    //int k = 2;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k);
	return 0;
}

// This code is contributed by Susobhan Akhuli
