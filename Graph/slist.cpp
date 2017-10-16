
// ====================================================
//HW#: HW3P1 slist
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>

#include "slist.h"
#include "llist.h"

slist::slist(){
    Key = ' ';
}



//PURPOSE: This fuction search() is searching for specific key in the list if
//          key was found then return its position (temp) else return 0(not found)
//PARAMETER: This Parameter Key contain some element to whom we search in list.
int slist::search(el_t Key){
    Node *x = Front;                    // Creating the pointer x and points to Front
    int temp = 1;                       // initializing the int temp value to 1
    while(x != NULL){                   // this while loop is goint till pointer x is equal to NULL
        if(Key == x->Elem){             // inside the while loop when key is equal to the element
            return temp;                // then return the number of node in the list
        }
            x = x->Next;                // incrementing the x
            temp++;                     // incrementing the temp value
        }
    return 0;                           // if key could not find then return zero

}





//PURPOSE: This function replace was replacing the noe at position I with
//          the element
//PARAMETER: This Parameter OldNum is giving back the value of the Node
//          which is Being deleted
void slist::replace(el_t Elem, int I){
//    If I greater than Count(number of node in List)
  //        or
  //    I is less than 1 then throw OutOfRange.
  if((I > Count)||(I < 1)){
    throw OutOfRange();
  }
   // If There is only one Node in the list means Count is One then
   // change the value of element
  else if(I==1){
    Node *p = Front;
    p->Elem = Elem;
  }
  // if I is a last Node then change the value of Element with Elem passes in the function
  else if(I==Count){
    Node *p = Rear;
    p->Elem = Elem;
  }
  else{
   // ELSE
   // cerate local int variable 'temp' and equal to 1 because
   // as this movement we know that there is already one Node in the list.
   // Therefore temp help to go the node which is passes in as 'I'
    int temp = 1;
    Node *q = Front;                    // create pointer q and point to the front
    while(temp!=I){                     // While loops is going till is temp is not equal to the value passed
        q = q->Next;                    // increment pointer q
        temp++;                         // increment temp till is not equal to I
    }
    q->Elem = Elem;                     // q gets new Element value
  }


}



//PURPOSE: This is a copy constructor whose purpose is make a deep copy
//          of linear link list that we created by classes llist and slist
//PARAMETER: This Parameter Orginal is an object of class slist(pass by referance)

slist::slist(const slist& Original){
    el_t temp = 0;                      // this int 'temp' is for to get the value of deleted element
    if (&Original != this){             // if not the same object then go for copy

        while(! this->isEmpty() ){      // this while loop to make list to whom this pointer is pointing
            this->deleteRear(temp);     // till list is not empty, keep deleting node from rear
        }

        Node *P = Original.Front;;      // local pointer 'p' for the Original linked list's front

        // This while loop adding the element to the new list till
        // pointer p is not equal to the original list's null
        while (P != NULL){
            this->addRear(P->Elem);     // P’s element is added to this->
            P = P->Next;                // p is incremented in original list
        }

    }// end of if

}


//PURPOSE: This is a operator= function which overload and can check for the equal object if is there any
//PARAMETER: This Parameter OtherOne is an object of class slist(pass by referance)

slist slist::operator=(const slist& OtherOne){
    el_t temp = 0;                      // this int 'temp' is for to get the value of deleted element
    if (&OtherOne != this){             // if not the same object then go for copy

        while(! this->isEmpty() ){      // this while loop to make list to whom this pointer is pointing
            this->deleteRear(temp);     // till list is not empty, keep deleting node from rear
        }

        Node *P = OtherOne.Front;;      // local pointer 'p' for the OtherOne linked list's front

        // This while loop adding the element to the new list till
        // pointer p is not equal to the original list's null
        while (P != NULL){
            this->addRear(P->Elem);     // P’s element is added to this->
            P = P->Next;                // p is incremented in original list
        }

    }// end of if

    return *this;
}

// PURPOSE: This overload operator for to check the equal Node among two linear link list
// parameter: List number 2 is passed by referance to compare with another List number 1
bool slist::operator==(const slist& list2) const
{
  // Here this if loop is returning "False" if both list are not equal
  if(this->Count != list2.Count){
        return false;
  }
  Node* P1;                             // creating pointer P1
  Node* P2;                             // creating pointer P2
  P1 = this->Front;                     // Making pointer P1 to equal list 1 front
  P2 = list2.Front;                     // Making pointer P1 to equal list 2 front

  // This while loop goes till pointer p1 on list 1 is equal to NULL
  while (P1!= NULL){
        // During this while loop if any two consecutive
        // element are not equal to each other than return "False"
        if (P1->Elem!=P2->Elem){
            return false;
        }
  // Here both list pinter P1 and P2 are incremented
  P1 = P1->Next;
  P2 = P2->Next;
  }
  //if all elements are same then its return true
  return true;
}
