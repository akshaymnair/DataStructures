// Name of Author: Akshay Muraleedharan Nair Santhy
// ASU ID: 1212981859
// Homework Number: Assignment #5
// Description: Red Black Tree
// file: RBFuncs.h

#include <iostream>
#include "RBClass.h"

RBTree::RBTree(){	// Constructor 

	root = NULL;
}

RBTree::~RBTree(){	// Constructor 
  int i=0;
  del(root,i); // recursive delete function
  cout<<"\n The number of Nodes deleted : "<< i;
  cout<<"\n Existing the Program!!\n";
  cout<<"\n======================================== \n";

  //delete root;
}

void RBTree::del(node *k,int &i)   // recursive function to get all nodes of the tree
{   
    if (k == NULL)
      return;

    i++;
    del(k->left, i);       // Left -> Root -> Right 
    del(k->right, i);
    delete k;
}


void RBTree::treeInsert(string command[],string key){ // insert athlete details into nodes and nodes into trees

     node *x,*y;
     node *t = new node;

     t->discipline = command[1];
     t->gender = command[2];
     t->team = command[3];
     t->event = command[4];
     t->venue = command[5];
     t->medal = command[6];
     t->athlete = command[7];
     t->country = command[8];
     t->key = key;

     t->left = NULL;
     t->right = NULL;
     t->color = "RED";    // all new nodes are RED
     
     x = root;
     y = NULL;
     
     if(x == NULL)
     {
           root = t;
           t->parent = NULL;
           t->color = "BLACK";
     }
     else
     {
         while(x != NULL)     //find the last node that satisfy BST condition
         {
              y = x;
              if(t->key < x->key)   // compare athlete userkey 
                  x = x->left;
              else
                  x = x->right;
         }
         
         t->parent = y;
     
    if(y == NULL)
      root =t;
        else if(y->athlete < t->athlete)
              y->right = t;
    else
              y->left = t;
     }
    cout<<"\n The medal recipient "<<command[7]<<" for "<<command[1]<<" with event "<<command[4]<<" INSERTED! \n";
    //insert_fixup(t);
}

void RBTree::inorderTreeWalk()		// InOrder Tree Traversal
{
	if(root!=NULL) inorder(root);
	else
		cout<<"\n Tree EMPTY! \n";
}


void RBTree::inorder(node *k)		// recursive function to get all nodes of the tree
{
    if (k == NULL)
        return;
 
    inorder(k->left);				// Left -> Root -> Right

    cout << "\n discipline: \t" << k->discipline;
    cout << "\n gender: \t" << k->gender;
    cout << "\n team_or_ind: \t" << k->team;
    cout << "\n event: \t" << k->event;
    cout << "\n venue: \t" << k->venue;
    cout << "\n medal: \t" << k->medal;
    cout << "\n athlete: \t" << k->athlete;
    cout << "\n country: \t" << k->country;
    cout << "\n color: \t" << k->color;
    cout <<"\n\n";
    
    inorder(k->right);
}


void RBTree::postorderTreeWalk()		// PostOrder traversal
{
	if(root!=NULL) postorder(root);
	else
		cout<<"\n Tree EMPTY! \n";
}

void RBTree::postorder(node *k)			// recursive function to get all nodes of the tree
{
    if (k == NULL)
        return;
 
    //postorder(k->left);
    //postorder(k->right);
    if(k->left) postorder(k->left);				//Print Left -> Right -> Root
    if(k->right) postorder(k->right);

    cout << "\n discipline: \t" << k->discipline;
    cout << "\n gender: \t" << k->gender;
    cout << "\n team_or_ind: \t" << k->team;
    cout << "\n event: \t" << k->event;
    cout << "\n venue: \t" << k->venue;
    cout << "\n medal: \t" << k->medal;
    cout << "\n athlete: \t" << k->athlete;
    cout << "\n country: \t" << k->country;
    cout << "\n color: \t" << k->color;
    cout <<"\n\n";
    
}



void RBTree::preorderTreeWalk()		// PostOrder traversal
{
	if(root!=NULL) preorder(root);
	else
		cout<<"\n Tree EMPTY! \n";
}

void RBTree::preorder(node *k)			// recursive function to get all nodes of the tree
{
    if (k == NULL)
        return;

    cout << "\n discipline: \t" << k->discipline;
    cout << "\n gender: \t" << k->gender;
    cout << "\n team_or_ind: \t" << k->team;
    cout << "\n event: \t" << k->event;
    cout << "\n venue: \t" << k->venue;
    cout << "\n medal: \t" << k->medal;
    cout << "\n athlete: \t" << k->athlete;
    cout << "\n country: \t" << k->country;
    cout << "\n color: \t" << k->color;
    cout <<"\n\n";
    
    //preorder(k->left);
    //preorder(k->right);
    if(k->left) preorder(k->left);			// Print Root -> Left -> Right
    if(k->right) preorder(k->right);

}

void RBTree::rotateLeft(node *x)  //rotate left
{
     if(x->right == NULL)
           return ;
     else
     {
          node *y = x->right;    //set y
          x->right = y->left; // turn y’s left subtree into x’s right subtree
          
          if(y->left != NULL)  
            y->left->parent=x;
           
          y->parent = x->parent;  // link x’s parent to y
          
          if(x->parent == NULL)
            root=y;

          else if(x == x->parent->left)
            x->parent->left = y;
               
          else
            x->parent->right = y;
           
           y->left = x;   // put x on y’s left
           x->parent = y;
     }
}

void RBTree::rotateRight(node *x) // Rotate Right
{
     if(x->left==NULL)
          return ;
     else
     {
         node *y = x->left;
         x->left = y->right;

        if(y->right != NULL)
          y->right->parent = x;
        
        y->parent = x->parent;
        
        if(x->parent == NULL)
          root=y; 
        
        else if(x == x->parent->left)
          x->parent->left = y;
        
        else
          x->parent->right = y;
         
         y->right = x;
         x->parent = y;
     }
}

void RBTree::insert_fixup(node *z){     // BST balancing - Arranging RED and BLACK colors

     node *y;
     if(root==z)
        return;
     
     while(z->parent!=NULL && z->parent->color=="RED")
     {
           node *g = z->parent->parent; //z.p.p
           if(z->parent == g->left)
           {
                        
                              y = g->right;
                              if(y->color == "RED")
                              {
                                   z->parent->color = "BLACK";
                                   y->color = "BLACK";
                                   g->color = "RED";
                                   z = g;
                              }
                        
                        else if(z == z->parent->right)
                            {
                                 z = z->parent;
                                 rotateLeft(z);
                            }
                            z->parent->color = "BLACK";
                            g->color = "RED";
                            rotateRight(g);
                        
            
           }
           else
           {
                        
                             y = g->left;
                             if(y->color == "RED")
                             {
                                  z->parent->color = "BLACK";
                                  y->color = "BLACK";
                                  g->color = "RED";
                                  z = g;
                             }
                        
                        else if(z->parent->left == z)
                            {
                                   z = z->parent;
                                   rotateRight(z);
                            }
                            z->parent->color = "BLACK";
                            g->color = "RED";
                            rotateLeft(g);
                        
            
           }
           
     }
     root->color = "BLACK";
}

void RBTree::treeSuccessor(node *p)     // Next element in inorder walk
{    node *y;
     if(root == NULL){
      cout<<"\n TREE EMPTY! \n";
      return;
     }
     else{

      y = NULL;

     if(p->left != NULL)
     {
         y = p->left;
         while(y->right != NULL)
              y = y->right;
     }
     else
     {
         cout<<"\n The Medel recipient "<<p->athlete<<" for "<<p->discipline<<" with event "<<p->event<<" does NOT have Successor!! \n ";
     }
    }
    if(y != NULL){
    cout<<"\n The Successor of Medel recipient "<<p->athlete<<" for "<<p->discipline<<" with event "<<p->event<<" is: ";
    cout << "\n discipline: \t" << y->discipline;
    cout << "\n gender: \t" << y->gender;
    cout << "\n team_or_ind: \t" << y->team;
    cout << "\n event: \t" << y->event;
    cout << "\n venue: \t" << y->venue;
    cout << "\n medal: \t" << y->medal;
    cout << "\n athlete: \t" << y->athlete;
    cout << "\n country: \t" << y->country;
    cout << "\n color: \t" << y->color;
    cout <<"\n\n";
  }
  //else
  //  cout<<"\n The given medel recipient does NOT have Successor!! \n ";
    
}

void RBTree::find(string key){
  if(root != NULL)
    find(root, key);
  else
    cout<<"\n TREE EMPTY! \n";

}

void RBTree::find(node *p,string key)   // recursive function to get all nodes of the tree
{   
    if (p == NULL)
      return;
    
    int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key == key){

            found = 1;
            treeSuccessor(p);

            }
            else
            {
                 if(p->key < key)
                      p = p->right;
                 else
                      p = p->left;
            }
     }
     if(found==0)
          cout<<"\n The given medel recipient does "<< key<<" NOT have Successor!! \n ";
   
}

void RBTree::treeSearch(string key){    // Tree search

  node* p = root;
  int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key == key){

            found = 1;
            cout<<"\n The medel recipient "<<p->athlete<<" is FOUND!! \n ";

            }
            else
            {
                 if(p->key < key)
                      p = p->right;
                 else
                      p = p->left;
            }
     }
     if(found==0)
      cout<<"\n The given medel recipient "<<key<<" is FOUND!! \n ";

}

void RBTree::treeMaximum(){   // Maximum

  cout<<"\n The Last Athlete is:  \n ";

}

void RBTree::treeMinimum(){   //minimum

  cout<<"\n The First Athlete is : \n ";

}