//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: Harjinder Gill
//Complier:  g++ and code_Block
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: **
int main()
{ slist L;  // the list
  int foundPos; // to hold the found position
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    L.addFront(4);
    cout << "\nAdding in the front => " << 4 << endl;
    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << endl; counter++;
    L.addRear(6);
    cout << "\nAdding in the Rear => " << 6 << endl;
    L.addRear(7);
    cout << "\nAdding in the Rear => " << 7 << endl;
    L.addRear(8);
    cout << "\nAdding in the Rear => " << 8 << endl;
    //  3)displayAll    - 4 6 7 8
    cout << counter << endl; counter++;
    cout << "\n########### Displaying the List ###########" << endl;
    L.displayAll();
    //  4)search for 6, report the result  - found in pos 2
    cout << counter << endl; counter++;
    L.search(6);
    if(L.search(6)==0){
        cout << "\n" << 6 << " is not in the List" << endl;
    }else{
        cout << "\nThe element '" << 6 << "' is found at position -> " << L.search(6) << endl;
    }

    //  5)replace the 6 with 0 using the search result
    cout << counter << endl; counter++;
    cout << "\n Replacing => " << 6 << " with => " << 0 <<  endl;
    L.replace(0,L.search(6));
    //  6)search for 8 and report the result . found in pos 4
    cout << counter << endl; counter++;
    L.search(8);
    if(L.search(8)==0){
        cout << "\n" << 8 << " is not in the List" << endl;
    }else{
        cout << "\nThe element '" << 8 << "' is found at position -> " << L.search(8) << endl;
    }
    //  7)replace the 8 with 2 using the search result
    cout << counter << endl; counter++;
    cout << " \nReplacing => " << 8 << " with => " << 2 <<  endl;
    L.replace(2,L.search(8));
    //  8)displayAll                       - 4 0 7 2
    cout << counter << endl; counter++;
    cout << "\n########### Displaying the List ###########" << endl;
    L.displayAll();
    //  9)search for 5 and report the result   - not found
    cout << counter << endl; counter++;
    L.search(5);
    if(L.search(5)==0){
        cout <<"\n" << 5 << " is not in the List" << endl;
    }else{
        cout << "\nThe element '" << 5 << "' is found at position -> " << L.search(5) << endl;
    }
    // 10) replace postion 7 with 10
    cout << counter << endl; counter++;
    cout << "\n Trying to Replacing => " << 10 << " at position " << 7 <<  endl;
    L.replace(10,7);
    }//end of try
    catch(llist::OutOfRange){
        cerr << "\nERROR: Bad position was given" << endl;
    }

}//end of program
