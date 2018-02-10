// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #4
// Description: Hash Table with collision resolved by Chaining
// file: hashFunctions.h

#include <iostream>
#include <string>
#include "hashClass.h"
using namespace std;

hashClass::hashClass(int hash_size){ // constructor function
    table_size = hash_size;             // assigin table size value taken from user
    hashTable = new item*[table_size];  // dynamically initialize hash table
    for (int i = 0; i < table_size; i++){   // initialize all values in list objects to "empty" for meaningfullness
                  hashTable[i] = new item;  // dynamically create new item
                  hashTable[i]->athlete = "empty";
                  hashTable[i]->country ="empty";
                  hashTable[i]->discipline ="empty";
                  hashTable[i]->event ="empty";
                  hashTable[i]->gender ="empty";
                  hashTable[i]->medal ="empty";
                  hashTable[i]->team ="empty";
                  hashTable[i]->venue="empty";
                  hashTable[i]->next=NULL;
    }
}

hashClass::~hashClass() { // destructor to delete all dynamic variables
    for (int i = 0; i < table_size; i++)
                  if (hashTable[i] != NULL) {
                        item *ptr = hashTable[i];
                        while (ptr != NULL) {
                             item *temp = ptr;
                             ptr = ptr->next;
                             delete temp; // delete dynamic variables
                        }
                  }

           delete[] hashTable; // deletes hash table
      }

int hashClass::h(string key,int hash_size){ //hashing function returns integer hash value for a given key
    int i;
    float a = 0.6180339887;
    long index=0;
    for(i=0;i<(int)key.length();i++)
        index+=((3*(int)key[i])+(5*(int)key[i]))*a; // finds the ASCII values of each characters in each line, multiply with prime number 3 and 5
    //cout<< "key sum is: "<< index<<endl;
    index = index % hash_size; // hashing by division : take mod of index of characters by the hash table size
    return index;
}

int hashClass::itemsInList(int index){ // return the size of the linked list in each hash table node
    int count=0;
    if (hashTable[index]->athlete == "empty")
        return count;
    else{
        count++;
        item* ptr = hashTable[index];
        while(ptr->next!=NULL){
            count++;
            ptr=ptr->next;
        }
    } return count;
}

//discipline0,gender1,team_or_ind2,event3,venue4,medal5,athlete6,country7
// insert given athlete details from the parsed string into the struct elements 
void hashClass::hash_insert(string athlete_details[],int index){
    if (hashTable[index]->athlete == "empty"){ // if node of the hash table is empty, new node is added
                    hashTable[index]->athlete = athlete_details[6];
                    hashTable[index]->country =athlete_details[7];
                    hashTable[index]->discipline =athlete_details[0];
                    hashTable[index]->event =athlete_details[3];
                    hashTable[index]->gender =athlete_details[1];
                    hashTable[index]->medal =athlete_details[5];
                    hashTable[index]->team =athlete_details[2];
                    hashTable[index]->venue=athlete_details[4];
    }
    else{ // if node of hash table is not empty, new element is added to the start of the linked list
        item* ptr = hashTable[index];
        item* temp = new item;
            temp->athlete = athlete_details[6];
            temp->country =athlete_details[7];
            temp->discipline =athlete_details[0];
            temp->event =athlete_details[3];
            temp->gender =athlete_details[1];
            temp->medal =athlete_details[5];
            temp->team =athlete_details[2];
            temp->venue=athlete_details[4];
          //  temp->next=NULL;
        hashTable[index] = temp; 
        temp->next = ptr;
        //while(ptr->next!=NULL)
        //    ptr=ptr->next;
        //ptr->next=temp;

    }
}

void hashClass::hash_display(){ // display all the elements in the hash table
    int list_size,i;
    for(i=0;i<table_size;i++){
        list_size=itemsInList(i);
        cout<<"-------------------------------------------------------------------------\n"; // line to separate each node of the hash table
        cout<<"\n\n"<<"index: " << i<<"\t"<< "linked list size: "<<list_size<<"\n\n";
        if (hashTable[i]->athlete == "empty")
            cout<< "The list is empty!"<<endl;
        else{
        item *ptr=hashTable[i]; // pointer to traverse through the linked list
        if(ptr->athlete.compare("empty")){
        while(ptr!=NULL){
            cout<<"discipline: \t"<<ptr->discipline<<endl;
            cout<<"gender: \t"<<ptr->gender<<endl;
            cout<<"team_or_ind: \t"<<ptr->team<<endl;
            cout<<"event:  \t"<<ptr->event<<endl;
            cout<<"venue:  \t"<<ptr->venue<<endl;
            cout<<"medal:  \t"<<ptr->medal<<endl;
            cout<<"athlete: \t"<<ptr->athlete<<endl;
            cout<<"country: \t"<<ptr->country<<endl;
            cout<<"\n\n";
            ptr=ptr->next;
            }
        }
        }

    }
}

void hashClass::hash_search(int index,string tokens[]){ // function to check if a given athlete is in the table or not
    int found = 0;
    item *ptr = hashTable[index];
    item *temp;
    //hash_search,discipline,gender,event,athlete
    //cout<<tokens[1]+tokens[2]+tokens[3]+tokens[4]<<" searching this key at "<<index<<endl;
    if(ptr->athlete != "empty"){ // checks if the given node of the table is empty or not
    while(ptr!=NULL){ // since the key is a combination of 4 features, all should be compared
    if(!ptr->athlete.compare(tokens[4])){
    if(!ptr->event.compare(tokens[3])){
    if(!ptr->gender.compare(tokens[2])){
    if(!ptr->discipline.compare(tokens[1])){
        found = 1; // executed when a ket is present
        temp = ptr;
    }}}}
    
    ptr = ptr->next;
   }
   if(found==1) // print the result of the search
    cout<<"\n"<<"The medal recipient "<< temp->athlete <<" has the medal of "<<temp->medal<<endl;
    else
    cout<<"\n"<<tokens[4]<<" for "<<tokens[1]<<" with event "<<tokens[3]<<" not found" <<endl;
    }
   else
   cout<<"\n"<<tokens[4]<<" for "<<tokens[1]<<" with event "<<tokens[3]<<" not found" <<endl;
    
}

void hashClass::hash_delete(int index,string tokens[]){ // function to delete a given athlete from the table
    int found = 0;
    item *ptr = hashTable[index];
    item *temp;
    item *prev = hashTable[index];
    if(ptr->athlete != "empty"){ // checks if the given node of the table is empty or not
    while(ptr!=NULL){ // compare all the 4 given features with content
    if(!ptr->athlete.compare(tokens[4])){
    if(!ptr->event.compare(tokens[3])){
    if(!ptr->gender.compare(tokens[2])){
    if(!ptr->discipline.compare(tokens[1])){
        found = 1;  // executes when a given key is found
        temp = ptr;
        cout<<"\n"<<"The medal recipient "<< temp->athlete <<" for "<<tokens[1]<<" with event "<<tokens[3]<<" deleted" <<endl;
        if(ptr->next==NULL){
            if(prev==ptr){  //single list element in node, which is the item to be deleted
                ptr->athlete = "empty";
                ptr->country ="empty";
                ptr->discipline ="empty";
                ptr->event ="empty";
                ptr->gender ="empty";
                ptr->medal ="empty";
                ptr->team ="empty";
                ptr->venue="empty";
                ptr->next=NULL;
            }
            else{ // multiple list elements in the node, item to be deleted is the last one
                prev->next=NULL;
                temp = ptr;
                ptr = prev;
                delete temp;
            }
        }
        else{
            if(prev==ptr) // multiple list elements in the hash node, first one is to be deleted
            {
               temp = ptr;
               hashTable[index] = ptr->next;
               ptr = prev;
               delete temp; 

            }
            else{ // multiple list elements in the hash node, item to be deleted is in between
            temp = ptr;
            ptr=ptr->next;
            prev->next = ptr;
            ptr = prev;
            delete temp;
        }
        }
        break;  // break from loop when given element is deleted
    }}}}
    prev = ptr;
    ptr = ptr->next;
   }
    
    if(found!=1) // item to be deleted is not found
    cout<<"\n"<<tokens[4]<<" for "<<tokens[1]<<" with event "<<tokens[3]<<" not found" <<endl;
    
    }
   else // hash node is empty, print no element found directly 
   cout<<"\n"<<tokens[4]<<" for "<<tokens[1]<<" with event "<<tokens[3]<<" not found" <<endl;
}
    