// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #5
// Description: Red Black Tree
// file: RBClass.h

#include <iostream>
#include <string>

using namespace std;

class RBTree{    // class to hold RBTree and variables
private:
    
    struct node{            // tree node with all the details of the athlete
        string discipline;
        string gender;
        string team;
        string event;
        string venue;
        string medal;
        string athlete;
        string country;
        string color;	// color of the node (RED/ BLACK)
        string key;		// combination of attributes of Athlete
        node* left;     // leftt node pointer of the node
        node* right;	// leftt node pointer of the node
		node* parent; 	// parent of the node

    };
    node *root; //initialize tree root pointer

public:
    
    RBTree(); // constructor
	
	void preorderTreeWalk();	//display function
	void inorderTreeWalk();		//display function
	void postorderTreeWalk();	//display function
	void inorder(node *k);		//inorder tree walk
	void postorder(node *k);	//postorder tree walk
	void preorder(node *k);		//preorder treewalk

	void treeSearch(string key);			//search function
	void treeMinimum();			//find the left most node
	void treeMaximum();			// find right most node
	void treeSuccessor(node *p);		// next element of a given element
	void treePredecessor(node *p);		// previous element of a given element
	
	void treeInsert(string command[],string key);			//indert into tree BST insertion
	void rotateRight(node *x);			//rotate a node to right
	void rotateLeft(node *x);			//rotate a node to left
	void insert_fixup(node *t);			// convert BST to Balanced BST -> RB Tree
	void del(node *k, int &i); 		// node delete funtion 
	void find(node *k,string key);	// find node for the given key
	void find(string key);			// send given key to find node

    ~RBTree(); // destructor

};
