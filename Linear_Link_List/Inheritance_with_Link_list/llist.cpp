// ====================================================
//HW#: HW3P1 llist
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h"




//PURPOSE: This is constructor which setting the Front and
//          and rear to Null and Count to Zero.
llist::llist(){
    Front = NULL;
    Rear = NULL;
    Count = 0;
}

//Destructor
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."


//PURPOSE: This is a destructor witch called at the end of the program
//          therefore, inside this destructor i calling the function
//          deleteFront() which going to clear memory after the
//          execution of program.

llist::~llist(){
    cout << "\n\n********Calling the destructor**********\n\n" << endl;
    // this while loop is deleting every Node left in the list till
    // its gets empty.
    while(!isEmpty()){
        deleteFront(Front->Elem);
    }
}




//PURPOSE: This boolean function isEmpty() return true if list has
//          no node and return false if there is any node in the List
//Return: True Or False
bool llist::isEmpty(){
    // Here if statement check for three condition to verify weather
    // List is Empty and return true:
    // 1. Count is equal to ZERO
    // 2 & 3. Front and Rear is equal to NULL
    // ELSE it return False
    if((Count == 0) || (Front == NULL) && (Rear == NULL)){
        return true;
    }else {
        return false;
    }
}




//PURPOSE: This Function DisplayAll() Prints the List on Screen
//          with their element value
void llist::displayAll(){
  // if the list is empty, display [ empty ].
  if(isEmpty()){
    cout << " \t[ empty ] " << endl;
    // displays each element of the list horizontally
    // starting from Front in [ ].
  }else{
          // Create the Pointer 'p' which point
          // to the Front element in the List
        Node *p = Front;
        cout << "\t[ " ;
        // While P is not go to the last element
        // then keep printing Value of each Node in the List
        while(p != NULL){
            cout << p->Elem << " ";
        p = p->Next;      // incrementing pointer P
        }
        cout << " ]" << endl;
    }
}




//PURPOSE: This function addRear() add the Node at the end of the list
//PARAMETER: pass the element (NewNum) to added in the Node
void llist::addRear(el_t NewNum) {
    // If this is going to be the very first node,
    // Then it would added in the Front of the List
    if(isEmpty()){
        Node *x = new Node;         // Create new Node 'x'
        Front = x;                  //  point Front to x(new Node)
        Rear = Front;               //  Point rear to Front
        Rear->Elem = NewNum;        // Put element value in very First Node
        Count++;                    // Increment Count Because Node is Added to the List
    }else{
        // Else Condition
        Node *x = new Node;         // Create new Node 'x'
        x->Elem = NewNum;           // put value value passes into the New Node 'x'
        Rear->Next = x;             // so node added at rear then next node to rear is 'x'
        Rear = Rear->Next;          // rear move to last Node which is 'x' at movement
        Rear->Next = NULL;          // rear next would be NULL
        Count++;                    // Increment Count Because Node is Added to the List
    }
}




//PURPOSE: This function addFront() add the Node at the beginning of the list
//PARAMETER: pass the element (NewNum) to added in the Node
void llist::addFront(el_t NewNum){
   // If this is going to be the very first node then call the function addRear()
   if(isEmpty()){
        addRear(NewNum);
   }else{
       // Else Condition
        Node *x = new Node;         // Create new Node 'x'
        x->Next = Front;            // Next to the created node would be all the List
        Front = x;                  // Now move the Pointer Front back on the Top of List
        Front->Elem = NewNum;       // put value value passes into the New Node 'x'
        Count++;                    // Increment Count Because Node is Added to the List
   }
}




//PURPOSE: This Function deleteFront() is deleting the First Node of the List
//PARAMETER: This Parameter OldNum is giving back the value of the Node
//          which is Being deleted
void llist::deleteFront(el_t& OldNum){
    // If the List is empty, throw Underflow
    if(isEmpty()){
        throw Underflow();
    }
    // If List has Only One Node left then give back the Value
    //  of that node by OldNum and delete the Node
    else if(Count == 1){
            OldNum = Front->Elem;       // pass the Oldnum of that first Node
            Node *x = Front;            // cerate pointer 'x' and point to First Node
            delete x;                   // delete the Node with 'x'
            Front = NULL;               // now there is node so Point Front = Null
            Rear = NULL;                // now there is node so Point Rear = Null
            Count--;                    // Decrement Count Because Node is deleted from the list
    }else{
        // Else if there is more than One Node in The List
        OldNum = Front->Elem;           // pass the Oldnum of that first Node
        Node *Second = Front->Next;     // cerate pointer 'Second' and point to Second Node
        delete Front;                   // delete the first Node
        Front = Second;                 // Point Front pointer to the next Node in The List
        Count--;                        // Decrement Count Because Node is deleted from the list
    }


}




//PURPOSE: This Function deleteRear() is deleting the Last Node of the List
//PARAMETER: This Parameter OldNum is giving back the value of the Node
//          which is Being deleted
void llist::deleteRear(el_t& OldNum){
    // If the List is empty, throw Underflow
    if(isEmpty()){
        throw Underflow();
    // If List has Only One Node left then then call the function deleteFront()
    // because we already take care of this condition in that function
    }else if(Count == 1){
        deleteFront(OldNum);
    }else{
        // Else if there is more than One Node in The List
        OldNum = Rear->Elem;            // pass the Oldnum of that first Node
        Node *p = Front;                // Create pointer P and point to the first Node
        //This While loop take 'p' to the one Node before rear
        while(p->Next->Next != NULL){
            p = p->Next;            // Increment the ponter p to next Node till Condition is met
        }
        delete Rear;                // delete the last node
        Rear = p;                   // Point Rear pointer to same as Pointer p is pointing
        Rear->Next = NULL;          // Rear Next equal to The Null
        Count--;                     // Decrement Count Because Node is deleted from the list

    }
}




//PURPOSE: This function deleteIth() is delete that Node From the List Which Is Passes as 'I'
//PARAMETER: There are two parameters one which node is going to delete.
//           other is what was its element value(pass by referance)
void llist::deleteIth(int I, el_t& OldNum){
  //    If I greater than Count(number of node in List)
  //        or
  //    I is less than 1 then throw OutOfRange.
  if((I > Count)||(I < 1)){
    throw OutOfRange();
  }
  // If There is only one Node in the list means Count is One then Call the
  // Function deleteFront() because we already take care of that
  // situation in that function
  else if(I==1){
    deleteFront(OldNum);
  }
  // If the Count is equal to the 'I' which is passed in as parameter
  // than call Function deleteRear() because we already take care of that
  // situation in that function
  else if(I==Count){
    deleteRear(OldNum);
  }else{
   // ELSE
   // cerate local int variable 'temp' and equal to 1 because
   // as this movement we know that there is already one Node in the list.
   // Therefore temp help to go the node which is passes in as 'I'
    int temp = 1;
    Node *p = Front;                // create pointer P and point as same node as Front
    Node *q = p;                    // create pointer q and point as same node as p
    while(temp!=I){                 // While loop take pointer q to the same node we have to delete
        q = q->Next;                // increment pointer q
        temp++;                     // increment temp till is not equal to I
    }
    while(p->Next != q){            // This While loop take another pointer p to the node behind the Node q
        p = p->Next;                // increment p till its point to the previous node as q pointing
    }
    OldNum = q->Elem;               // Value of that Node is being delete is passes to OldNum
    p->Next = q->Next;              // now next node from p whould be the next node of q
    delete q;                       // q is deleted
    Count--;                         // Decrement Count Because Node is deleted from the list
  }
}




//PURPOSE: This function addbeforeIth() is add that Node just before the node Passes as 'I'
//PARAMETER: There are two parameters one is the position where node is going to added.
//           other is what is going to be the element value of that new node.
void llist::addbeforeIth(int I, el_t newNum){
    //    If I greater than Count + 1 because count start at 0
    //        or
    //    I is less than 1 then throw OutOfRange.
   if((I > Count+1)||(I < 1)){
    throw OutOfRange();
  }
  // If we have to add Node at the first place or top of the Node then Call the
  // Function addFront() because we already take care of that
  // situation in that function
  else if(I==1){
    addFront(newNum);
  }
  // If we have to add Node just before last place in the List then Call the
  // Function addRear() because we already take care of that
  // situation in that function
  else if(I==Count+1){
    addRear(newNum);
  }

  else{
    // ELSE
   // cerate local int variable 'temp' and equal to 1 because
   // as this movement we know that there more than one Node in the list.
   // Therefore temp help to go the node where we have to add new Node at the place 'I'
    int temp = 1;
    Node *p = Front;                // create pointer p and point as same node as Front
    Node *q = p->Next;              // create pointer q and point as next node to Front or p

    // This while loop take the above two pointer to next
    // and previous position where in between we have adds the new Node
    while(temp!=I-1){
        q = q->Next;                // incrementing pointer q
        p = p->Next;                // incrementing pointer p
        temp++;                     // incrementing int temp
    }
    Node *x = new Node;             // creating the new Node and give name 'x'
    p->Next = x;                    // now x is next Node to p
    x->Elem = newNum;               // now new Node has value of newNum
    x->Next = q;                    // now q is the next node to the X
    Count++;                        // Increment Count Because Node is Added to the List

  }
}

