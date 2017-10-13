#ifndef SLIST_H_
#define SLIST_H_

// =======================================================
// HW#: HW3P1 slist
// Your name: Harjinder Gill
// Complier:  g++ and CodeBlock
// File type: headher file
//=======================================================


#include "llist.h"
//----- Globally setting up the alias and struct  ----------------

typedef int el_t ;  // elements will be be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space

class slist:public llist
{
     private:
        el_t Key;
    public:
        // this is constructor where we initializing the
        slist();
        //  This fuction search() is searching for specific key in the list if
        //  key was found then return its position (temp) else return 0(not found)
        int search(el_t Key);
        // This function replace was replacing the noe at position I with
        // the element
        void replace(el_t Elem, int I);

};


#endif // SLIST_H
