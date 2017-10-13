//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Harjinder Gill
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: Use a queue to print a pattern of ABC strings.
//Algorithm: **
int main()
{
  queue ABCstrings; //string queue
  string current; //current string
  while (!ABCstrings.isFull())
    {
      try
	{
	  if(ABCstrings.isEmpty()) //if to start the queue if it is empty
	    {
	      ABCstrings.add("A");
	      ABCstrings.add("B");
	      ABCstrings.add("C");
	      ABCstrings.displayAll();
	    }
	  else //else to take care of if the queue is not empty. This will continue until while loop finishes.
	    {
	      ABCstrings.remove(current);
	      ABCstrings.add(current + "A");
	      ABCstrings.add(current + "B");
	      ABCstrings.add(current + "C");
	      ABCstrings.displayAll();
	    }
	}
      catch (queue::Overflow)
	{
	  {cerr << "Error: Queue has reached maximum capacity" << endl; }
	}
      catch (queue::Underflow)
	{
	  {cerr << "Error: Queue is empty" << endl;}
	}
    }
}

