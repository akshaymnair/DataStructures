// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #6
// Description: LCS
// file: functions.h

#include <iostream>
#include <string>
using namespace std;


void start();		// start the execution with reading sequences
bool errorCheck(string str1, string str2);		// validate the strings, check ig both are either (0,1) or (A,C,G,T)
void computeLCS(string str1, string str2);		// compute the LCS length and Sequence and print them
int maxof(int a, int b);					// helper function to find largest of 2 integers

