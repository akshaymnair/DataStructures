// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #5
// Description: Red Black Tree
// file: main.cpp

#include <iostream>
#include <string>
#include "RBFuncs.h"


int main()
{
    string user_command,user_copy; /// user choice
    RBTree obj; // object of Red Black tree
    int i;
	string command; // command to be executed
	string delimiter = ","; // used to parse input string
	size_t pos = 0;
	string athlete[8]; // there is 8 features for each team/ athlete in each line
	string cToken[9]; // longest user comand has 9 words
	string token,key;
    string cKey[10];
    int k=0,flag=0;

    do
    {
                cout<<"\n\t RED BLACK TREE " ;
                cout<<"\n -------------------------------------" ;
                
                cout<<"\n Find your operation and required command from the list below  \n";
                cout<<"\n 1. Insert in the tree:\t <tree_insert,discipline,gender,ind_team,event,venue,medal,athlete,country> ";
                cout<<"\n 2. Tree Search: \t <tree_search,discipline,gender,event,athlete>";

                cout<<"\n 3. Inorder Traversal: \t <tree_inorder>";
                cout<<"\n 4. Preorder Traversal:\t <tree_preorder> ";
                cout<<"\n 5. Postorder Traversal: <tree_postorder>" ;

                cout<<"\n 6. Tree minimum: \t <tree_maximum>" ;
                cout<<"\n 7. Tree Maximum: \t <tree_minimum>" ;
                cout<<"\n 8. Tree Successor: \t <tree_successor,discipline,gender,event,athlete>" ;
                cout<<"\n 9. Tree Predecessor: \t <tree_predecessor,discipline,gender,event,athlete>" ;

                cout<<"\n 0. QUIT: \t\t <quit> \n" ;
                

                cout<<"\nEnter Your Command Choice: ";
                getline(cin, user_command);
                user_copy = user_command;

                //code for parsiong the string
			    i=0;
			    while ((pos = user_command.find(delimiter)) != string::npos) { // parsing input command, and fining the keywords
			    token = user_command.substr(0, pos);
			    cToken[i++]= token;
			    user_command.erase(0, pos + delimiter.length()); 
			    }
			    cToken[i++]= user_command; // store parsed string to an array
			    command = cToken[0];
			    //cout<< "\n Command to execute is : "<<command;
			    //cout<<"\n Command parameters are : \n"<<cToken[1]<<cToken[2]<<cToken[3]<<cToken[4]<<cToken[5]<<cToken[6]<<cToken[7]<<cToken[8];

                if(command == "tree_insert"){
                    key = cToken[1]+cToken[4]+cToken[2]+cToken[7];
                    flag =0;
                    for(int j=0;j<k;j++)
                        if(key==cKey[j])
                            flag=1;
                    cout<<"\n Next Command: "<<user_copy;
                    if(flag!=1){
                        cKey[k] = key;
                        k++;
                        obj.treeInsert(cToken,key);
                    }
                    else
                        cout<<"\n The medal recipient "<<cToken[7]<<" for "<<cToken[1]<<" with event "<<cToken[4]<<" NOT inserted! \n";
                    
                }
                else if(command == "tree_inorder"){
                    cout<<"\n INORDER Traversal";
                    cout<<"\n -------------------------------------" ;
                    obj.inorderTreeWalk();
                }
                else if(command == "tree_preorder"){
					cout<<"\n PREORDER Traversal";
                    cout<<"\n -------------------------------------" ;
                    obj.preorderTreeWalk();
                }
				else if(command == "tree_postorder"){
					cout<<"\n POSTORDER Traversal";
                    cout<<"\n -------------------------------------" ;
                    obj.postorderTreeWalk();
                }
                else if(command == "tree_search"){
                    obj.treeSearch(key);                  // parse input key and search Tree

                }
                else if(command == "tree_maximum"){
                    obj.treeMaximum();                  // to find right most element in tree

                }
                else if(command == "tree_minimum"){
                    obj.treeMinimum();                  ////  to find left most element in tree

                }
                else if(command == "tree_successor"){
                    obj.find(key);                      // // parse input key and search Tree to find successor

                }
                else if(command == "tree_predecessor"){
                    obj.find(key);                      // parse input key and search Tree to finf predecessor

                }
                else if(command == "quit")
                	break;
                else
                	cout<<"\n---------WRONG CHOICE!!-----------\n";
                

    }while(user_command!="quit");
    return 1;
}