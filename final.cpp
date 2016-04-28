/**********************************************************
* This program handles movie theater seating and pricing, *
* navigated by a menu. The project idea was found in our  *
* book on pages 454 and 455.                              *
**********************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function prototypes go under this comment. Those commented out
// do not yet have functions in place.

int mainMenu();
void mapSeats();
int seats(double[], int);
void viewSales(int, double, double);

const int rowNum = 15; // Holds the size of the array
double rowValue[rowNum]; //array to hold row pices
int row2, col2; // Used for outputing a sales chart
const char TAKEN = '#';//seats taken
const char EMPTY = '*';//seats free
const int row = 15;//number of rows
const int col = 30;//number of col
char map[row][col];//array to hold seat chart
char selection; // Used in the seats function

int sold; // Keeps track of tickets sold in viewSales function
double price, total; // Price keeps track of the price of tickets, total rings in total sales

int main()
{
  char choice; // Used for the menu function.
  
  
  cout << "Theater Program by Matthew Green, Nick Lombardo, Christie Gorka, and Brandon Hawkins.\n\n";
  cout << "This program handles movie theater seating and \n"; // Greet the user.
  cout << "pricing. Press enter to continue.";
  cin.get();
  cout << "Would you like to:\n\n"; // Give the user choices.
  cout << "A: View and purchase a seat.\n";
  cout << "B: View pricing.\n";
  cout << "C: View total sales.\n";
  cout << "D: Quit the program.\n";
  mainMenu(); // Menu function call
  
  return 0;
}

/**********************************************************************
* This is the main menu function. It is used to navigate the program. *
* Down in the switch, we have placeholder outputs to test if the      *
* choices work. There are also function calls commented out (as of    *
* April 2nd, 2016) as a means of placement for the functions for the  *
* menu.                                                               *
*                                                                     *
* Author: Brandon Hawkins                                             *
**********************************************************************/

int mainMenu()
{  
	char choice;
	cin >> choice;
  if (islower(choice)) // Change casing to uppercase
     choice = toupper(choice);
  
  switch(choice) // The inner workings of the menu with 
  {              // placeholder outputs
    case 'A' :
      mapSeats(); // Function call for displaying the seats.
      seats(rowValue, rowNum);
      break;
    case 'B' :
      seats(rowValue, rowNum); // Function call for displaying the prices.
      break;
    case 'C' :
      viewSales(sold, price, total); // Function call for viewing the sales.
      break;
    case 'D' :
      return 0;
    default : 
      cout << "Invalid input." << endl;
			mainMenu();
  }
}

// This function displays a seating chart in the theater.
// Author: Nick Lombardo
void mapSeats()
{
	const char TAKEN = '#';//seats taken
	const char EMPTY = '*';//seats free
	const int rw=16;
	const int cl=30;

	cout << "Seats " ;
	for(int k = 1 ; k <31;k++) //loop to display nums 0 to 30
	{
		cout << fixed<< setw(1) << " " << k ;
	}

	for(int i=1;i<rw;i++)//making array display what's in it
	{
		cout << endl<< "Row " << i;
		for(int j=1;j<cl;j++)
		{
			cout << fixed<< setw(2) << "" << EMPTY;
		}
	}
	cout << endl;

}

// This function displays prices on a per-seat basis.
// Author: Nick Lombardo
int seats(double rowValue[], int rowNum)
{
	for(int i= 1;i<row;i++)//initiating array 
	{
		for (int j=1;j<col;j++)
		{
			map[i][j]=EMPTY;
		}
	}
	cout << "Please enter a ticket price for each row." << endl;
	
	for(int i = 0 ; i < row; i++)
	{
		cout << "Row # " << i+1 << ": " ;
		cin >> rowValue[i];	
	}
  	do
		{
			cout << "1) Buy a ticket" << endl;
			cout << "2) View ticket sales" << endl;
			cout << "Q) Quit the program" << endl;
			cout << "Please make a selection: ";
			cin >> selection;
			
			if(selection =='1')
			{
				cout << "Please enter a row number and a seat number for the ticket: " ;
				cout << "Row # :" ;
				cin >> row2;
				cout << endl;
				cout << "Seat # :" ;
				cin >> col2;
				cout << endl;
	      // Check if seat is free
        if(map[row2][col2] == TAKEN)
        {
	      cout << "This seat is taken! Try another one. \n";
	      continue; // start the loop again
        }
        else // and if it is - sell the ticket
	        map[row2][col2]=TAKEN;
        // Add the next loop to immediately see the effects:
        for (int i = 1; i < row; i++)
        {
	        for(int j = 1; j < col; j++)
	        {
		        cout << map[i][j];
          }
					cout << endl;
				}
			}
			else if (selection == '2')
				viewSales(sold, price, total);
			else if (selection == 'q' || selection == 'Q')
			{
				cout << "Thanks for using the program" << endl;
				return 0;
			}
			else if(selection != '1' || selection !='q' || selection !='Q')
			{
				cout << "Invalid selection." << endl;
			}
		}while(selection != '1' || selection !='q' || selection !='Q');
}

// This function allows the user to view the total sales.
// Author: Christie Gorka
void viewSales(int sold, double price, double total)
{
	ofstream outputFile;
	// Open an output file
	outputFile.open("theatre.txt");
	 cout<<"Enter Number of Tickets Purchased: ";
  cin >> sold;
   cout<<"Enter Ticket Price per Ticket: ";
  cin >> price; 
  
  // calculate the total
  total = (sold * price);
  
  // Sets decimal formatting
  cout << fixed << setprecision(2);
  
  cout <<"Total Sales: $" << total << endl;
	
	// Write numbers to a file
	outputFile << fixed << setprecision(2);
	outputFile << "Tickets sold: " << sold << endl;
	outputFile << "Total sales: $" << total << endl;
	cout << "The numbers were saved to a file.\n";
	    
    // Close the file
    outputFile.close();
    cout << "Done \n";
}