// Driver function for Graph
// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #7
// Description: Graph implementation
// file: main.cpp

#include "graphFunctions.h"

int main(int argc, char* argv[]) {		//main funciton with argument count , and argument paramenters 
	
	string commands, edges;
	string *commandList;
	string *edgeList;

	// instance of the edges class

	Arg cmd(argv[1]);
   commands = cmd.contents();

   Arg edg(argv[2]);
   edges = edg.contents();

   commandList = parser(commands);
   edgeList = parser(edges);

   college matches;
   // for(i=0; commandList[i] != "\0"; i++)
   // 	cout<<commandList[i]<<endl<<"-------------------------"<<endl;

   // trimming white spaces
	//   	string s = commandList[0];
	// s.erase(s.find_last_not_of("\n")+1);
	// cout<<s<<"-"<<s.length()<<"||"<<commandList[0]<<"-"<<commandList[0].length();

   for(int i=0; commandList[i] != "\0"; i++){
   		
   	string cm, cmmd;
   	cmmd = commandList[i];					        // trimming \n from the strings
   	for(int j=0; j<cmmd.length()-1; j++)		// trimming \n from the strings
   		cm += cmmd[j];						        // trimming \n from the strings

   	cout<<endl<<"next command: "<< cm<<endl;
   		
   	if(cm == "quit"){								// Exit command
   		return 0;
   	}
   	else if(cm == "end_graph"){						// Delete dynamic varriables
	  		cout<<"Deleting current Graph contents.."<<endl;
         matches.destrctor();
   	}
   	else if(cm == "print_graph"){					// print the graph
	  		cout<<"Graph (Adjacency List) contents:"<<endl;
	  		// Call Print graph function
         matches.display();
  		}
  		else if(cm == "depth_first_search"){			// DFS 
   		cout<<endl<<"The array pi content:"<<endl;
   		// call DFS function 		
         matches.depthFirstSearch();  // prints parents
         cout<<endl<<"The array discovery time content:"<<endl;
         matches.depthFirstSearchDT();  // prints discovery time
         cout<<endl<<"The array finish time content:"<<endl;
         matches.depthFirstSearchFT();  // prints finish time
  		}
      else {	
   		cout << "Reading edges.txt \n" ;
			// call read graph function	 
			int start, end, fileLength;
			string* comand = parse(cm);
			for(int k=0; edgeList[k] != "\0"; k++)
				fileLength = k;
			cout<<"Total edges lines in the file: "<<fileLength<<endl;

			stringstream str(comand[1]);
			str >> start;
			stringstream en(comand[2]);
			en >> end;
			end = (fileLength < end)? fileLength : end;
			cout<<"Edges lines taken in this operation: from "<<start<<" to "<<end<<endl;

         matches.graphInsertNode(end-start);
         
         
			for (int k = start; k <=  end; k++){
            int x=0;
            matches.graphInsertEdge(edgeList[k],x);
            x++;
         }

   	}
   		
   }


return 0;
}

//END