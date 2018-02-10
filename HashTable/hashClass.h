// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #4
// Description: Hash Table with collision resolved by Chaining
// file: hashClass.h

#include <iostream>
#include <string>

using namespace std;

class hashClass{    // class to hold hashtable and variables
private:
    int table_size;     // size of the hash table

    struct item{            // linked list node with all the details of the athlete, each linked list node is a structure object
        string discipline;
        string gender;
        string team;
        string event;
        string venue;
        string medal;
        string athlete;
        string country;
        item* next;     // next pointer for linked list
        
        void list_insert(string value); // insert in list 
        void list_search(string key); // search on list
        void list_delete(string key); // delete from list
    };

    item **hashTable; //initialize hash table pointer

public:
    hashClass(int hash_size); // constructor
    int h(string key,int hash_size); // returns hash value of a key
    void hash_insert(string athlete_details[],int index); // add items to hash table
    int itemsInList(int index); // returns size of the linked list
    void hash_display(); // display entire hash table
    void hash_search(int index,string tokens[]); // search for a given key
    void hash_delete(int index,string tokens[]); // delete given key value pair

    ~hashClass(); // destructor

};
