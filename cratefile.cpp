// This program writes user input to a file
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
  
  //Constants for cost and amount charged 
  const double COST_PER_CUBIC_FOOT = 0.23;
  const double CHARGE_PER_CUBIC_FOOT = 0.5;
  ofstream outputFile;
  
  //Variables
  double length, // Crate's Length
  width, // Crate's Width
  height, // Crate's Height
  volume, // Volume of Crate
  cost, // Cost to Build Crate
  charge, // Customer Charge for Crate
  profit; // Profit Made on Crate
  
  // Set the desired output formatting for numbers.
  cout << setprecision(2) << fixed << showpoint;
  
  // Prompt the user for the crate's length, widith, and height
  cout << "Enter the dimensions of the crate (in feet):\n";
  cout << "Length: ";
  cin >> length;
  cout << "Width: ";
  cin >> width;
  cout << "Height: ";
  cin >> height;
  
  // Open a file named crate.txt
  outputFile.open("crate.txt"); 
  
  // Calculate the crate's volume, the cost to produce it,
  // the charge to the customer, and the profit.
  volume = length * width * height;
  cost = volume * COST_PER_CUBIC_FOOT;
  charge = volume * CHARGE_PER_CUBIC_FOOT;
  profit = charge - cost;
    
  // Display the calculated data.
  cout << "The volume of the crate is ";
  cout << volume << " cubic feet.\n";
  cout << "Cost to build: $" << cost << endl;
  cout << "Charge to customer: $" << charge << endl;
  cout << "Profit: $" << profit << endl;
  
  // Write the sales to the file.W
  outputFile << profit << endl;

// Close the file.
outputFile.close();
cout << "Data written to crate.txt\n";
return 0;
}