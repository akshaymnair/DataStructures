// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #6
// Description: LCS
// file: main.cpp

#include "function.h"

int main(){				// Driver function

int cho;
string str1, str2;

do{						// allows checking LSC continuosly until User exits th executioin

cout << "\n\n\t LONGEST COMMON SEQUENCE!";
cout << "\n-------------------------------------------";

cout << "\n 1. Compute LCS ";
cout << "\n 0. EXIT \n";
cin >> cho;
cin.ignore(20, '\n'); 

if(cho == 1) start();
else if( cho !=0)
cout << "\n WRONG CHOICE! ";


}while(cho != 0);
return 0;

}