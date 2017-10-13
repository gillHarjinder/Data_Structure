#ifndef LLIST_H_
#define LLIST_H_

// =======================================================
// HW#: HW3P1 llist
// Your name: Harjinder Gill
// Complier:  g++ and CodeBlock
// File type: headher file
//=======================================================

//----- Globally setting up the alias and struct  ----------------




typedef int el_t ;  // elements will be be int

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:

  // Exception handling classes
  class Underflow{};    // thrown when the specified node is underflow
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes

  //    this method check whether list is empty or not
  //    So if the list has node then it sent false
  //    else it  has nor have any node the it send true
  bool isEmpty();

  //    This function use to display all the node in
  //    the list along with their information inside
  void displayAll();

  //    This function add a node to the beginning of the list
  void addFront(el_t Elem);

  //    This function add node after the last node in the list
  //    at that time
  void addRear(el_t Elem);

  //    This function delete the node from the list
  //    which we passed as an argument by reference
  void deleteFront(el_t& Elem);

  //    This function delete the node
  //    which is at rear position in the list
  void deleteRear(el_t& Elem);

  //    This function find the element at int position and
  //    delete from the list
  void deleteIth(int, el_t& Elem);

  //    This function add the element at the position int
  //    in the list
  void addbeforeIth(int, el_t Elem);

};
#endif
