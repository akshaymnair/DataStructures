// Assignment #1
// Name: Akshay
// ASU ID: 1212981859
// ASU Email Address: akshayms@asu.edu
// Description: To be completed

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Country represents some country information
struct Country
{
	string name;
	int gold;
	int silver;
	int bronze;
	struct Country * next;
};

//class LinkedList will contains a linked list of countries
class LinkedList
{
private:
	struct Country * head; //always points to the current head of the list
	struct Country * tail; //always points to the current tail of the list
	struct Country * temp; //arbitrary variable
	struct Country * current; //arbitrary variable
	struct Country * back; //points to the previous node of the current node

public:
	LinkedList();
	~LinkedList();
	bool addCountry(string countryName, int gold, int silver, int bronze);
	bool removeCountry(string countryName);
	bool changeMedalCount(string countryName, string medal, int count);
	void printList();
	void additem(); //to add items in sorted order
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

//Destructor
//Garbage collection, it deletes all class objects and elements
LinkedList::~LinkedList()
{
	//To be completed
	int i=0;
	current=head;
	while(current!=NULL){
		temp=current;
		current=current->next;
		delete temp;//takes every element from the list and deletes it
		i++; //shows the number of elements in the list
	}
	cout<<"Number of deleted Countries are : "<<i<<endl;
	//delete head;
	//delete tail;
	//delete temp;
	//delete current;
	//delete back;
}

//adds elements in an ascending order to the list
bool LinkedList::addCountry(string newName, int gold, int silver, int bronze)
{

	//To be completed
	temp=new Country; // dynamic variable to store new elements the user entered

	temp->name=newName;
	temp->gold=gold;
	temp->silver=silver;
	temp->bronze=bronze;
	temp->next=NULL;

	if (head==NULL){ // execute if the list is empty
		head=temp;
		tail=head;
	}
	else additem(); // execute if list is not empty

	return true; // always true as we add dynamic values

}

//Removes a linkedList object according to condition
bool LinkedList::removeCountry(string someName)
{
	//To be completed
	current=head;
	back=current; // a variable trailing 1 position behind current

	while(current!=NULL && someName.compare(current->name)!=0 ){ //breaks if there is no element or if element is found
		back=current;
		current=current->next;
	}
	if (current==NULL)
		return false; // no element found in list
	else{
		temp=current;
		current=current->next; //bypassing element that has to be deleted
		back->next=current;
		delete temp; // founded element is deleted
		return true;
	}
}

//Changing Medal Count according to condition
bool LinkedList::changeMedalCount(string countryName, string medalType, int count)
{
	//To be completed
	current= head;
	while(current!=NULL && countryName.compare(current->name)!=0){ // breaks if there is no element or element found
		current=current->next;
	}
	if(current==NULL)return false; // when element not found
	else{// when element found, replace old wit new count
		if(medalType.compare("gold")==0)current->gold=count;
		else if (medalType.compare("silver")==0)current->silver=count;
		else current->bronze=count;

		return true; //when update completes
	}
}

//Prints the whole list
void LinkedList::printList()
{
	//To be completed
	current = head;
	if (current == NULL)
		cout<<"The list is Empty! \n";
	else{
		while(current!=NULL){ // from the head of the list to the end, prints the data
			cout<<"Country Name : "<<current->name<<", Gold : "<<current->gold<<", Silver : "<<current->silver<<", Bronze : "<<current->bronze<<endl;
			current = current->next;
		}
	}
}
//Adds new element to an existing list, compare with existing elements and adds elements in ascending order
void LinkedList::additem(){

	if(temp->name.compare(tail->name)>0){ //if new element name has to go to the end of the list
		tail->next=temp;
		tail=temp;
	}
	else if(head->name.compare(temp->name)>0){ //if new element name has to go the the beginning of the list
		temp->next=head;
		head=temp;
	}
	else{ //if new element goes in between in the list
		current=head;
		while(current!=NULL){
			if(current->name.compare(temp->name)<0){
				back=current;
				current=current->next;
			}
			else{
				back->next=temp;
				temp->next=current;
				break;
			}
		}
	}
}
