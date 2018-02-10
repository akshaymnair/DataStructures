// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #6
// Description: LCS
// file: functions.cpp

#include "functions.h"


void start(){			// read input sequences from the user

	string str1, str2;
	int len1, len2;
	bool proceed=false;

	cout << "\n enter DNA Sequence (A, G, C, T) or (1, 0) #1: ";
	getline(cin, str1);
	
	cout << "\n enter DNA Sequence (A, G, C, T) or (1, 0) #2: ";
	getline(cin, str2);
	
	if(!errorCheck(str1,str2))
		computeLCS(str1,str2);
	else
		return;

}

bool errorCheck(string str1, string str2){		// validate the sequences, check if both are either (0,1) or (A,C,G,T)
	cout<"\n Validating Sequences: \n";
	char type1 = 'x';
	char type2 = 'x';
	bool err=false;
	cout << "\n Validating Sequence #1 ERRORS IN '()' : ";
	for(int i=0; i<str1.size();i++){								// find the type of sequence #1 either alphabetic or neumeric
		if(type1 == 'x'){
		if(str1[i] == 'A' ||str1[i] == 'C' ||str1[i] == 'G' ||str1[i] =='T')
			type1 = 'a';

		else if(str1[i] == '0' ||str1[i] == '1')
			type1 = 'n';
		else
			type1 = 'x';
		}
		else
			break;
	}

	for(int i=0; i<str1.size();i++){								// check each value in string to find errors
		if(type1 == 'a'){
		if(str1[i] == 'A' ||str1[i] == 'C' ||str1[i] == 'G' ||str1[i] =='T')
			cout<<str1[i];
		else{
			cout<<"("<<str1[i]<<")";
			err = true;
		}
		}
		else if(type1 == 'n'){
			if(str1[i] == '1' ||str1[i] == '0')
			cout<<str1[i];
		else{
			cout<<"("<<str1[i]<<")";
			err = true;
		}
		}

	}

	cout << "\n Validating Sequence #2 ERRORS IN '()' : ";
	for(int i=0; i<str2.size();i++){											// find the type of sequence #1 either alphabetic or neumeric
		if(type2 == 'x'){
		if(str2[i] == 'A' ||str2[i] == 'C' ||str2[i] == 'G' ||str2[i] =='T')
			type2 = 'a';

		else if(str2[i] == '0' ||str2[i] == '1')
			type2 = 'n';
		else
			type2 = 'x';
		}
		else
			break;
	}

	for(int i=0; i<str2.size();i++){											// check each value in string to find errors
		if(type2 == 'a'){
		if(str2[i] == 'A' ||str2[i] == 'C' ||str2[i] == 'G' ||str2[i] =='T')
			cout<<str2[i];
		else{
			cout<<"("<<str2[i]<<")";
			err = true;
		}
		}
		else if(type2 == 'n'){
			if(str2[i] == '1' ||str2[i] == '0')
			cout<<str2[i];
		else{
			cout<<"("<<str2[i]<<")";
			err = true;
		}
		}

	}

	if(type1 != type2 || type1 == 'x' || type2 == 'x'){			// validation of input sequense 
		cout<< "\n\n Both the Sequences should be either (0,1) or (A, C, G, T). Here it doesn't MATCH !!";
		err = true;
	}

	if(err)
		cout<< "\n\n Error(s) in Sequence(s) \n Try different Sequences !!";
	else
		cout <<"\n\n No Error in Sequences, Calculating LCS!!";

	return err;
}


void computeLCS(string str1, string str2){		// Computing the LCS length and LCS Sequence

	cout<< "\n\n  Computing Longest Common Sequence !";
	cout << "\n -------------------------------------";
	int len2, len1,i,j,lenLCS;

	len1 = str1.size();
	len2 = str2.size();

	int lcs[len1+1][len2+1]; 		// matrix created to store the computation table C 

	for (i=0; i<= len1; i++){
		for (j=0; j<= len2; j++){
			if( i == 0 || j ==0)
				lcs[i][j] = 0;
			else if ( str1[i-1] == str2 [j-1])
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j] = maxof(lcs[i-1][j], lcs[i][j-1]);
		}
	}

	lenLCS = lcs[len1][len2];													// the lower right corner element in the matrix
	cout<<"\n\n The length of Longest Common Sequence is: " << lenLCS<<endl;

	char sequence[lenLCS+1];		// to store the LCS values
	sequence[lenLCS] = '\0';		// end of the sequence

	i = len1;	// to traverse from bottom to up
	j = len2; 	// to traverse from bottom to up

	while(i>0 && j>0){			// same algorithm given in class

		if(str1[i-1] == str2[j-1]){
			sequence[lenLCS-1] = str1[i-1];
			i--;
			j--;
			lenLCS--;
		}
		else if(lcs[i-1][j] > lcs[i][j-1])
			i--;
		else
			j--;

	}

	cout<<" The Longest Common Sequence of given Sequences is: " << sequence <<endl;

	cout<<"\n The Dynamic Subsequence Length computation Table C : \n"<<endl;		// print length computation table
	cout<< "    ";
	for (j=0; j<= len2; j++){
			cout<< " "<<str2[j]<< " " ;
	}
	for (i=0; i<= len1; i++){			// same algorithm given in class
		cout<< endl;
		if(i==0)
			cout<<" ";
		else 
			cout<< str1[i-1];

		for (j=0; j<= len2; j++){

			cout<< " "<<lcs[i][j]<< " " ;
		}
	}

	cout<<"\n\n The Dynamic Subsequence Arrow Table B: \\: Diagonal, -: left, |:up"<<endl;		//Print Arrow Table \: Diagonal, -: left, |:up

	cout<< "    ";
	for (j=0; j<= len2; j++){
			cout<< " "<<str2[j]<< " " ;
	}
	for (i=0; i<= len1; i++){
		cout<< endl;
		if(i==0)
			cout<<" ";
		else 
			cout<< str1[i-1];

		for (j=0; j<= len2; j++){					// same algorithm given in class
			if(str1[i-1] == str2[j-1]){
				//cout<< "("<<lcs[i][j]<< ")" ;
				cout<< " \\ " ;
				//if(lcs[i][j] == lcs[len1][len2])
				//	break;
			}
			else if(lcs[i-1][j] >= lcs[i][j-1]){
				//cout<< "|"<<lcs[i][j]<< "|" ;
				cout<< " | " ;
				
			}
			else{
				//cout<< "-"<<lcs[i][j]<< "-" ;
				cout<< " - " ;
			}
		}
	}

}

int maxof(int a, int b){		// helper function: return largest of 2 numbers
	return (a>b)? a:b;
}


