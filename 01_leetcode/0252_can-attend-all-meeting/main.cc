#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    // Sort the meetings based on start times
    
    sort( intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];} );

    // Check for overlap
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; // Overlap found
        }
    }

    return true; // No overlap found
}

int main() {
    vector<vector<int>> meetings1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> meetings2 = {{7,10},{2,4}};

    // Test Example 1
    bool result1 = canAttendMeetings(meetings1);
    cout << "Example 1: " << (result1 ? "true" : "false") << endl;

    // Test Example 2
    bool result2 = canAttendMeetings(meetings2);
    cout << "Example 2: " << (result2 ? "true" : "false") << endl;

    return 0;
}
