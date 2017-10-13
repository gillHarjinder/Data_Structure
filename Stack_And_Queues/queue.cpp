//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Harjinder Gill
//Complier:  g++ and code block
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"

// constructor
queue::queue()
{
  count = 0;
  front = rear = 0;
}

//destructor
queue::~queue()
{
  //nothing to do
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0){
    return true;
  }else{
    return false;
  }

}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if (count == MAX_SIZE)
    return true;
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if (isFull()){
    throw Overflow();
  }
  else{
      //for loop will iterate through and move the elemnts up the queue
      for (int i = front; i >= rear; i--) {
        el[i + 1] = el[i];
	     }
      el[rear] = newElem;
      if(!isEmpty())
	       front++;
      count++;
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if (isEmpty())
    throw Underflow();
  else
    {
      count--;
      removedElem = el[front];
      front--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if (isEmpty())
    throw Underflow();
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  if (isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      cout << "[";
      for(int i = front; i >= rear; i--) //for loop will iterate through and print the elements
	{
	  cout << el[i] << " ";
	}
      cout << "]" << endl;
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
  if (count == 1)
    return;
  else
    {
      el_t temporary;  //local element temporary will be used to store the removed element to be added.
      remove(temporary);
      add(temporary);
    }
}




