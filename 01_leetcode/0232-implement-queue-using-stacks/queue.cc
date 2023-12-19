#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{

   queue<string> weekdays;

   weekdays.push("Saturday");
   weekdays.push("Friday");
   weekdays.push("Thursday");
   weekdays.push("Wednesday");
   weekdays.push("Tuesday");
   weekdays.push("Monday");
   weekdays.push("Sunday");

   cout<<"Size of the stack: "<<weekdays.size()<<endl;

   while(!weekdays.empty()) {
      cout<<weekdays.front()<<endl;
      weekdays.pop();
   }

   return 0;
}
