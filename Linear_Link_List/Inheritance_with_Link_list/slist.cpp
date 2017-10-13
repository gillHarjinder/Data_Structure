
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
    Key = 0;
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

