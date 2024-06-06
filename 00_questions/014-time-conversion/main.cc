/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example
    12:00:00AM  ==> 00:00:00
    02:00:00AM  ==> 02:00:00
    12:00:00PM  ==> 12:00:00
    02:12:34PM  ==> 14:12:34
    11:12:45AM  ==> 11:12:45
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Time {
    string hour;
    string minute;
    string second;
    bool am;
};

vector<string> splitString(string& s, char delimiter){
    vector<string> tokens;
    istringstream iss(s);
    string token;
    while(getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string timeConversion(string s) {
    vector<string> vec = splitString(s, ':');
    Time time;
    time.hour = vec[0];
    time.minute = vec[1];
    time.second = vec[2].substr(0, 2);
    time.am = (vec[2].substr(2, 2) == "AM");

    Time militaryTime;
    if(time.hour == "12" && time.am == true) {
        militaryTime.hour = "00";
    } else if(time.am == true) {
        militaryTime.hour = time.hour;
    } else if(time.hour == "12" && time.am ==  false) {
        militaryTime.hour = time.hour;
    } else if(time.am ==  false) {
        militaryTime.hour = to_string(stoi(time.hour) + 12);
    }
    militaryTime.minute = time.minute;
    militaryTime.second = time.second;

    return militaryTime.hour + ":" + militaryTime.minute + ":" + militaryTime.second;
}

int main()
{
    string time1 = "12:00:00AM";
    string result1 = timeConversion(time1);
    cout << time1 << "  ==> " << result1 << endl;

    string time2 = "02:00:00AM";
    string result2 = timeConversion(time2);
    cout << time2 << "  ==> " << result2 << endl;

    string time3 = "12:00:00PM";
    string result3 = timeConversion(time3);
    cout << time3 << "  ==> " << result3 << endl;

    string time4 = "02:12:34PM";
    string result4 = timeConversion(time4);
    cout << time4 << "  ==> " << result4 << endl;

    string time5 = "11:12:45AM";
    string result5 = timeConversion(time5);
    cout << time5 << "  ==> " << result5 << endl;    

    return 0;
}
