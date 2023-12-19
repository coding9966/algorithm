#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{

   stack<string> weekdays;
   weekdays.push("Saturday");
   weekdays.push("Friday");
   weekdays.push("Thursday");
   weekdays.push("Wednesday");
   weekdays.push("Tuesday");
   weekdays.push("Monday");
   weekdays.push("Sunday");

   cout<<"Size of the stack: "<<weekdays.size()<<endl;

   while(!weekdays.empty()) {
      cout<<weekdays.top()<<endl;
      weekdays.pop();
   }

   return 0;
}
