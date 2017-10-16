
// =========================================================
//HW#: HW4 BST
//Your name: Harjinder Gill
//Complier:  g++ and codeblocks
//File type: BST cpp file
//==========================================================

using namespace std;

#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{
  if (V != NULL)
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       //  visit right sub tree of V
      delete V;                  //  deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
    if(Root != NULL){
        cout << "Elements in the IN order: " << endl;
        INorderTraversal(Root);  // start in-order traversal from the root
    }else{
        cout << "There is NO NODE in The Tree " << endl;
    }
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        // ** traverse left sub-tree of V recursively
        INorderTraversal(V->Left);
        // ** display V's element and do endl;
        cout << V->Elem << endl;
        // ** traverse right sub-tree of V recursively
        INorderTraversal(V->Right);
      }
}

// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
    if(Root != NULL){
        cout << "Elements in the PRE order:" << endl;
        PREorderTraversal(Root);  // start pre-order traversal from the root
    }else{
        cout << "There is NO NODE in The Tree " << endl;
    }
}

// PURPOSE: Does PRE order traversal from V recursively
// PARAM: V is the pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        // ** display V's element and do endl;
        cout << V->Elem << endl;
        // ** traverse left sub-tree of V recursively
        PREorderTraversal(V->Left);
        // ** traverse right sub-tree of V recursively
        PREorderTraversal(V->Right);

      }
}

// PURPOSE: Adds a vertex to the binary search tree for a new element
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively) to demonstrate
// the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{
    // Set up a new vertex first
    Vertex *N;         // N will point to the new vertex to be inserted
    N = new Vertex;    // a new vertex is created
    N->Left  = NULL;   // make sure it does not
    N->Right = NULL;   // point to anything
    N->Elem  = E;      // put element E in it

    cout << "Trying to insert " << E << endl;

    if (Root == NULL){  // Special case: we have a brand new empty tree
        Root = N;      // the new vertex is added as the root
        cout << "\t...adding " << E << " as the root" << endl;
     }else{  // the tree is not empty
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent
        V = Root;        // start with the root as V

        while (V != NULL){  // go down the tree until you cannot go any further
            if (N->Elem == V->Elem){ // the element already exists
                cout << "\t...error: the element already exists" << endl;
                return;
            }else if (N->Elem < V->Elem) { // what I have is smaller than V
                cout << "\t<-- going to the left" << endl;
                // changing Parent to be V to go down
                Parent = V;
                // changing V to be V's Left
                V = V->Left;

            }else{ // what I have is bigger than V
                cout << "\t--> going to the right" << endl;
                // changing Parent to be V to go down
                Parent = V;
                // changing V to be V's Right
                V = V->Right;

            }

        }//end of while

        // reached NULL -- Must add N as the Parent's child
        if (N->Elem < Parent->Elem){
            // ** Parent's Left should point to the same place as N
            Parent->Left = N;
            cout << "\t...adding " << E << " as the left child of "
                << Parent->Elem << endl;
        }else{
            // ** Parent's Right should point to the same place as N
            Parent->Right = N;
            cout << "\t...adding " << E << " as the right child of "
                  << Parent->Elem << endl;
        }
    }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
    cout << "\nTrying to delete " << E << endl;

    Vertex *V;              // the current vertex
    Vertex *Parent = NULL;  // its parent

    if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL)){
        cout << "\t...deleting the lonely root" << endl;
        delete Root;
        Root = NULL;
        return;   // only the Root was there and deleted it

    }// end of deleting the root

    // Otherwise deleting something else

    V = Root;  // start with the root to look for E

    while (V != NULL){
        if ( E == V->Elem){  // found it
            cout << "\t...removing " << V->Elem << endl;

            // here some how if tree has one child and we have to delete root
            // then this if else condition works

            if(V == Root){                                  // if the deleting node is root with one child
                cout << "\t" << E << " => is a root. " << endl;
                remove(V, Parent);                          // calling remove function here to remove V
                return;
            }else{                                          // the deleting node should be the only child in tree
                remove(V,Parent);                           // calling remove function here to remove V
                return;
            }
        }else if (E < V->Elem){
            cout << "\t<-- going to the left" << endl;
            // updating Parent and V here to go down
            Parent = V;
            V = V->Left;
        }else{
            cout << "\t--> going to the right" << endl;
            // updating Parent and V here to go down
            Parent = V;
            V = V->Right;
        }

    }// end of while

  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;

}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
// Case 4: it is the root node and it has zero children - delete the root node.
// Case 5: it is the root node and it has one child - replace it with child.
void BST::remove(Vertex *V, Vertex *P)
{
    // here we handling the case 4 and case 5
	if (P == NULL)                                  // checking If parent is NULL, this must be the root node.
	{
		// V is root, and it has no children (case 4)
		if (V->Left == NULL && V->Right == NULL)
		{
			delete V;
			return;
		}
		// V is root, and it has only a left child (case 5)
		else if (V->Left != NULL && V->Right == NULL)
		{
			Root = V->Left;
			delete V;
			return;
		}
		// V is root, and it has only a right child
		else if (V->Left == NULL && V->Right != NULL)
		{
			Root = V->Right;
			delete V;
			return;
		}
	}
	// Now these are case 1 , case 2, and case 3

    // if V is a leaf (case 1)
    // if V is a left child of P
    // deleting V and also make Parent's left NULL
    if((V->Left == NULL) && (V->Right == NULL) && (P->Left == V)){
        cout << "\t.. removing a leaf" << endl;
        delete V;
        P->Left = NULL;
    }
    // V is a right child of the Parent
    // deleting V and also make Parent's right NULL
    // end of leaf case
    else if((V->Left == NULL) && (V->Right == NULL) && (P->Right == V)){
        cout << "\t.. removing a leaf" << endl;
        delete V;
        P->Right = NULL;
    }
    // if V has just the left child (case 2)
    // Make Parent left or right point to the left child and delete V
	else if((V->Left != NULL) && (V->Right == NULL)){
        cout << "\t..removing a vertex with just the left child" << endl;
        if(P->Left == V){
            P->Left = V->Left;
            delete V;
        }else{
            P->Right = V->Left;
            delete V;
        }
	}// end of V with left child

    // if V has just the right child
    // Make Parent left or right point to the right child and delete V
	else if((V->Left == NULL) && (V->Right != NULL)){
        cout << "\t..removing a vertex with just the right child" << endl;
        if(P->Left == V){
            P->Left = V->Right;
            delete V;
        }else{
            P->Right = V->Right;
            delete V;
        }
    }//end of V with right child
    // V has two children (case 3)
    else if((V->Left != NULL) && (V->Right != NULL))
	{ cout << "\t...removing an internal vertex with children" << endl;
	  cout << "\t.....find the MAX of its left sub-tree" << endl;
	  elem_t Melem;
          Melem = findMax(V); // find MAX element in the left sub-tree of V
          cout << "\t.....replacing " << V->Elem << " with " << Melem << endl;
          // Replacing V's element with Melem here
          V->Elem = Melem;
        }//end of V with two children

 }// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
     Vertex *Parent = V;
     V = V->Left;          // start with the left child of V

     // while the right child of V is still available
    while(V->Right != NULL){
        // update Parent and V to go to the right
        Parent = V;
        V = V->Right;
    }

    // reached NULL Right  -- V now has the MAX element
        elem_t X = V->Elem;
        cout << "\t Max is = " << X << endl;
        remove(V, Parent);    // remove the MAX vertex
        return X;             // return the MAX element

}// end of FindMax

