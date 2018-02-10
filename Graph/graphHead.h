// Graph header
// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #7
// Description: Graph implementation
// file: graphHead.h

#include <iostream>
#include <fstream>	// to open file
#include <string>	// string opereations
#include <sstream>	// to convert string to int
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

using namespace std;

string* parser(string line);	// function to parse the input file and get the commands from diffrent lines, separeted by '\n'
string* parse(string line);		// function to parse commands and get parameters separated by ','

class Arg {						//class with function to parse the files passed in as arguments to the program
string text;
public:
Arg() {}
Arg (const string& fname) {		// constructor function that reads the file and save it in a string varriable
    ifstream ifst(fname.c_str());
    string line;
    while (getline(ifst, line)){
    	text += line + '\n';
    }
}

string contents() {
	return text;
}
};


class college{				// to store the edges list
private:
    struct edge{
        string name;
        string score;
        string defeted;
        string dscore;
        edge* defeted_link;
        edge* defeted_by;
    };
    edge **graph; //initialize hash table pointer

public:
	int numColleges;	

    void graphInsertNode(int tot_edge_lines); // constructor   
    void graphInsertEdge(string edg,int i); // add items to list, addes new edge
    void display(); // print list
    void destrctor();	// delete current graph
    void depthFirstSearch();	// performs depth first search and print parents
    void depthFirstSearchDT();	// prints discovery time in dfs
    void depthFirstSearchFT(); 	// prints finish time in dfs

    ~college(); // destructor
};