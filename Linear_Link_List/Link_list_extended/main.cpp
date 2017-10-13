// =======================================================
// HW#: HW3P3client.cpp
// Your name: Harjinder Gill
// Complier:  g++ and CodeBlock
// File type: headher file
//=======================================================




#include <iostream>

using namespace std;

#include "slist.h"
#include "llist.h"




// PURPOSE: CopyTest function definition. Pass the list to be copied and
//          the variable to be added to the rear.
//PARAMETER: Two parameter passed => object list of slist class(pass by value)
//                                   a int value to store in node(pass by value)
void CopyTest(slist list, int input)
{
    // create the object CallingCopyConst() and calling the copy constructor
    slist CallingCopyConst(list);
    // calling function addrear by object testlist
    CallingCopyConst.addRear(input);
    cout << "\n //////     Display all from CopyTest function     ///////" << endl;
    // Displaying the new copied list
    CallingCopyConst.displayAll();
}

int main()
{
    int result = 0;                                        // A variable to to store the deleted item value
    slist L1;                                              // create the object of L1 for list 1 from class slist
    slist L2;                                              // create the object of L2 for list 2 from class slist

    //1.	Create a 5 element list with  1,2,3,4,5 (L1)
    cout << "\n 1. *******Adding Elements to List -> 1 \n" << endl;
    L1.addRear(1);
    cout << "\n Adding from rear => " << 1 << endl;
    L1.addRear(2);
    cout << "\n Adding from rear => " << 2 << endl;
    L1.addRear(3);
    cout << "\n Adding from rear => " << 3 << endl;
    L1.addRear(4);
    cout << "\n Adding from rear => " << 4 << endl;
    L1.addRear(5);
    cout << "\n Adding from rear => " << 5 << endl;

    //2.	Pass the list to a client function called CopyTest
    //to test your copy constructor.
    //a.	Copytest will receive the list passed by value from main() and
    //b.	Simply
    //1) add a node to its rear with 6 in it (should not affect the original)
    //2) display it (6 elements 1,2,3,4,5,6)
    cout << "\n2. ######## Calling function CopyTest ##########" << endl;
    CopyTest(L1, 6);

    //3.	Display L1 	(this should still be a 5 element list)
    cout << "\n3. ***********Displaying LIST-1**********" << endl;
    L1.displayAll();

    //4.	Do L1 = L1;
    cout << "\n4.	********* L1 = L1 **************" << endl;
    L1 = L1;

    //5.	Display L1    	(this should still be 1 2 3 4 5)
    cout << "\n5.	***********Displaying LIST-1 AGAIN**********" << endl;
    L1.displayAll();

    //6.	Create a 4 element list L2 with 7,8,9,10.
    cout << "\n6.	************Adding Element to LIST -> 2***********" << endl;
    L2.addRear(7);
    cout << "\n Adding from rear => " << 7 << endl;
    L2.addRear(8);
    cout << "\n Adding from rear => " << 8 << endl;
    L2.addRear(9);
    cout << "\n Adding from rear => " << 9 << endl;
    L2.addRear(10);
    cout << "\n Adding from rear => " << 10 << endl;

    //7.	Display L2
    cout << "\n7. ***********Displaying LIST-2 **********" << endl;
    L2.displayAll();

    //8.	Do L2 = L1;  	(L2 becomes 5 elements 1,2,3,4,5)
    cout << "\n8.	********* L2 = L1 **************" << endl;
    L2 = L1;

    //9.	Display L2.
    cout << "\n9. ***********Displaying LIST-2 Again**********" << endl;
    L2.displayAll();

    //10.	Remove a rear node from L1. (This should not affect L2).
    cout << "\n10.**********Remove last Node from LIST -> 1********"<< endl;
    L1.deleteRear(result);
    cout << "\n Element Removed  => " << result << endl;
    //11.	Display L1.   	(L1 is 1,2,3,4)
    cout << "\n11. ***********Displaying LIST-1 **********" << endl;
    L1.displayAll();

    //12.	Display L1 again. (4 elements)
    cout << "\n12. ***********Displaying LIST-1 AGAIN **********" << endl;
    L1.displayAll();

    //13.	Display L2 again. (still 5 elements 1,2,3,4,5)
    cout << "\n13. ***********Displaying LIST-2  AGAIN **********" << endl;
    L2.displayAll();

    return 0;
}










