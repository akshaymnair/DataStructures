// Graph functions definitions
// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #7
// Description: Graph implementation
// file: grapFunctions.h

#include "graphHead.h"

// function to parse the input file and get the commands
string* parser(string line){
	int i;
	string delimiter = "\n"; // used to parse input string
	size_t pos = 0;
	string token;
	string* cToken = new string[100];
	
	//code for parsiong the string
	i=0;
	while ((pos = line.find(delimiter)) != string::npos) { // parsing input command, and fining the keywords
	token = line.substr(0, pos);
	cToken[i++]= token;
	line.erase(0, pos + delimiter.length()); 
	}
	cToken[i++]= line; // store parsed string to an array
	
return cToken;
}

// function to parse the input command and get the parameters
string* parse(string line){
	int i;
	string delimiter = ","; // used to parse input string
	size_t pos = 0;
	string token;
	string* cToken = new string[100];
	
	//code for parsiong the string
	i=0;
	while ((pos = line.find(delimiter)) != string::npos) { // parsing input command, and fining the keywords
	token = line.substr(0, pos);
	cToken[i++]= token;
	line.erase(0, pos + delimiter.length()); 
	}
	cToken[i++]= line; // store parsed string to an array
	
return cToken;
}


void college::graphInsertNode(int tot_edge_lines){ // set default values function
    numColleges = tot_edge_lines;
    graph = new edge*[numColleges];
    for (int i = 0; i < numColleges; i++){
                  graph[i] = new edge;
                  graph[i]->name = "empty";
                  graph[i]->score = "empty";
                  graph[i]->defeted = "empty";
                  graph[i]->dscore = "empty";
                  graph[i]->defeted_link = NULL;
                  graph[i]->defeted_by = NULL;
    }
}

college::~college() {										 // destructor to delete the graph
    delete[] graph;
    cout<<"Deleted Graph.. Exiting Program!! \n"<<endl;
}

void college::graphInsertEdge(string edg,int i){				// addes new edge
	string *contents;
	contents = parse(edg);
	//for(int i=0; contents[i] != "\0"; i++)
		//cout<<contents[i]<<endl;
	
	if (graph[i]->name == "empty"){
                    graph[i]->name = contents[0];
                    graph[i]->score = contents[1];
                    graph[i]->defeted = contents[2]; 
                    graph[i]->dscore = contents[3];

    }
    
    else{
        edge* ptr = graph[i];
        edge* temp = new edge;
            temp->name = contents[0];
            temp->score = contents[1];
            temp->defeted = contents[2]; 
            temp->dscore = contents[3];
            temp->defeted_link = NULL;

        while(ptr->defeted_link!=NULL)
            ptr=ptr->defeted_link;
        ptr->defeted_link=temp;
    }
    
}
void college::display(){ // display all the elements in the hash table

    for(int i=0; graph[i]->name != "empty"; i++){
	    edge *ptr = graph[i]; // pointer to traverse through the linked list
	    if(ptr->name != "empty"){
	    	cout<<endl;
		    while(ptr != NULL){
		        cout<<ptr->name<<" beat: "<< ptr->defeted;
		        cout<<" "<< ptr->score<< "-" << ptr->dscore << endl;            
		        ptr=ptr->defeted_link;
		    }
	    }
    }
}

void college::depthFirstSearch(){			// Depth First Search 
	string parent;
	
	for(int i=0; graph[i]->name != "empty"; i++){
	    edge *ptr = graph[i]; // pointer to traverse through the linked list
	    if(ptr->defeted_by == NULL)
			parent = "none";

	    if(ptr->name != "empty"){
	    	cout<<endl;
		    while(ptr != NULL){
		        cout<<"pi ["<<ptr->name<<"] = "<< parent<< endl;
		        cout<<"pi ["<<ptr->defeted<<"] = "<< ptr->name << endl;            
		        ptr=ptr->defeted_link;
		    }
	    }
    }

}
void college::destrctor(){		// deleting current graph
	for (int i = 0; i < numColleges; i++)
                  if (graph[i] != NULL) {
                        edge *ptr = graph[i];
                        while (ptr != NULL) {
                             edge *temp = ptr;
                             ptr = ptr->defeted_link;
                             delete temp; // delete pointer
                        }
                  }

            // deletes graph
}

void college::depthFirstSearchDT(){			// Depth First Search  discover time
	string copy[50];
	int k=1;

	for(int i=0; graph[i]->name != "empty"; i++){
	    edge *ptr = graph[i]; // pointer to traverse through the linked list
	   
		bool exists = std::find(copy, copy+50, ptr->name) != copy+50;
		if(!exists)
		 	copy[i] = ptr->name;
		k += i;
		

	    if(ptr->name != "empty"){
	    	cout<<endl;
		    while(ptr != NULL){
		        cout<<"DiscoverTIme ["<<ptr->name<<"] = "<< k<< endl;
		     	k++;
		        cout<<"DiscoverTIme ["<<ptr->defeted<<"] = "<< k << endl;            
		        ptr=ptr->defeted_link;
		    }
	    }
    }

}
void college::depthFirstSearchFT(){			// Depth First Search finish time
	int j = numColleges*2;
	string copy[50];

	for(int i=0; graph[i]->name != "empty"; i++){
	    edge *ptr = graph[i]; // pointer to traverse through the linked list
	    
		bool exists = std::find(copy, copy+50, ptr->name) != copy+50;
		if(!exists)
		 	copy[i] = ptr->name;

	    if(ptr->name != "empty"){
	    	cout<<endl;
		    while(ptr != NULL){
		        cout<<"FInishTime ["<<ptr->name<<"] = "<< j << endl;
		        cout<<"FInishTime ["<<ptr->defeted<<"] = "<< --j << endl;            
		        ptr=ptr->defeted_link;
		    }
	    }
    }

}