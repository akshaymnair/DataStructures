// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #4
// Description: Hash Table with collision resolved by Chaining
// file: main.cpp

/* Hash analysis -- every entry is having a unique string as a key, so I convert each character in those string into their ASCII values
and calculated their sum and took mod by size of the table. for the given data set (44 elements), the load factor should be 44/13 = 3.38
So on average, 4 collisions in each node is optimum. My initial hash function, on a maximum, created 7 collisions and a minimum of 2.
So I multiplied prime number 3 to each charecter ASCII value and added with the product of ASCII value and prime number 5 to it. Then I
multiplied 'a' with it, Which reduced my collision to Maximum 5 and minimun 3.   
hash function h(k) = {[(ASCII(each character in key)*3)+(ASCII(each character in key)*5]*a} % table size
where a = 0.6180339887
*/

#include <iostream>
#include <string>
#include "hashFunctions.h"
using namespace std;

int main()
{
int hashTable_size=0,command_size=0; // user input of size of the hash table and number of commands
string athlete_details; // all details of the athlete
string key,token,cToken[5]; // search command has only 5 words
string command,cKey;
int index,i;
string command_line; // command to be executed
string delimiter = ","; // used to parse input string
size_t pos = 0;
string athlete[8]; // there is 8 features for each team/ athlete in each line

cout << "Enter Hash table size :\n";
cin >> hashTable_size;
cin.ignore(20, '\n'); //flush the buffer
//hash_search,discipline,gender,event,athlete
hashClass hashObj(hashTable_size); // hash class object
// loop untill user input 'InsertionEnd'
do{ // read all input lines and parse them and add them into hash tables
    cout << "Enter athlete information in this format (discipline,gender,team_or_ind,event,venue,medal,athlete,country):\n";
    cout<<"or type InsertionEnd to stop: \n"<<endl;
    getline(cin, athlete_details);
    if(athlete_details!="InsertionEnd"){
    //cout<<"hash_search: discipline,gender,event,athlete\n " << endl;
    //code for parsing the input string
    i=0;
    while ((pos = athlete_details.find(delimiter)) != string::npos) {
    token = athlete_details.substr(0, pos);
    athlete[i++]= token;
    athlete_details.erase(0, pos + delimiter.length());
    }
    athlete[i++]= athlete_details;  // stores parsed words into array
    key = athlete[0]+athlete[1]+athlete[3]+athlete[6];
    //cout<< "Key is: " << key << endl;

    index= hashObj.h(key,hashTable_size); // index in hash table where the key would go
    //cout<<"this key goes in hash table index : " << index<<endl;
    //cout<<"Hash table Size "<< hashTable_size<<endl;
    hashObj.hash_insert(athlete,index); //insert elemnt to the start of the linked list
    }
    else
        break;
}while(athlete_details!="InsertionEnd");

cout << "Enter number of Commands to execute: "<<endl; //reads number of commands to execute
cin >> command_size;
cin.ignore(20, '\n'); //flush the buffer
// loop untill the number of commands >0
while(command_size>0){
    cout<<endl;
    cout<<"Enter the command: " <<endl; // reads commands from the user
    getline(cin, command_line);
    //code for parsiong the string
    i=0;
    while ((pos = command_line.find(delimiter)) != string::npos) { // parsing input command, and fining the keywords
    token = command_line.substr(0, pos);
    cToken[i++]= token;
    command_line.erase(0, pos + delimiter.length()); 
    }
    cToken[i++]= command_line; // store parsed string to an array
    command = cToken[0];
    cKey = cToken[1]+cToken[2]+cToken[3]+cToken[4];
    index= hashObj.h(cKey,hashTable_size); // index in hash table where the key would be in
    //cout<<"Command is: " <<command<< endl;
    //cout<<"Command key is : "<<cKey<<endl;

if(command=="hash_display"){ // check user commands and achoose operation
    hashObj.hash_display();
    cout<<"-------------------------------------------------------------------------\n";
}
else if(command=="hash_delete"){    // delete function
    //cout<<"inside delete \n";
    hashObj.hash_delete(index,cToken);

}
else if(command=="hash_search"){// search function
    //cout<<"finding index of this key "<< cKey<<endl;
    hashObj.hash_search(index,cToken);
    //cout<<"inside search \n";
}
else
    cout << "Unknown Command \n"; // when user inputs something other than 'hash_search, hash_delete, hash_display'

    command_size--;
}

    return 0;
}


