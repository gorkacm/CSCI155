// RACECAR
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
//setting up variables
double distance, time, speed;
  
// Get the total amount of distance.
cout << "How far can the car travel? ";
cin >> distance;
  
// Get the total time.
cout << "How much time, in hours, did the car travel? ";
cin >> time;
  
// Get the top speed of the car.
cout << "What is the average speed of the car? ";
cin >> speed;

// Calculate overall distance.
distance = speed * time;

// Display the distance.
cout << "The total distance travel: " << distance << endl;
return 0;
}  
  