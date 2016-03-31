#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
int main ()
{
   // local variable declaration:
   char grade;
  ofstream outputFile;
  
  cout << "What is the grade : ";
  cin >> grade;
 
   switch(grade)
   {
   case 'A' :
     case 'a' :
      cout << "Excellent!" << endl;
       cout << "Your grade is A" << endl;
      break;
   case 'B' :  
       case 'b' :
       cout << "Well done" << endl;
       cout << "Your grade is B" << endl;
       break;
   case 'C' :
       case 'c' :
      cout << "Well done" << endl;
       cout << "Your grade is C" << endl;
      break;
   case 'D' :  
       case 'd' :
      cout << "You passed" << endl;
       cout << "Your grade is D" << endl;
      break;
   case 'F' :
       case 'f' :
      cout << "Better try again" << endl;
        cout << "Your grade is F" << endl;
      break;
   default :
      cout << "Invalid grade" << endl;
   }
 
   outputFile << grade << endl;
  
  outputFile.close();
cout << "Data written to switch.txt\n";
  
   return 0;
}