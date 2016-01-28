// This progam calculates the user's pay. 
#include <iostream>
using namespace std;

int main() { 
//setting up variables
double hours, rate, ftax, stax, pay; 

// Get the number of hours worked. 
cout << "How many hours did you work? "; 
cin >> hours; 

// Get the hourly pay rate. 
cout << "How much do you get paid per hour? "; 
cin >> rate; 
  
// Get the percent of federal taxes. 
cout << "What percent of federal taxes do you pay? "; 
cin >> ftax;
  
// Get the percent of federal taxes. 
cout << "What percent of state taxes do you pay? "; 
cin >> stax;

// Calculate the pay. 
pay = (hours * rate) * ((100-ftax)/100) * ((100-stax)/100);

// Display the pay. 
cout << "You have earned $" << pay << endl; 
return 0; 
}