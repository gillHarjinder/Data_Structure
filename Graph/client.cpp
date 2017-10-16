// ====================================================
//HW#: HW6
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: HW6client.cpp file
//=====================================================


#include <iostream>
#include "dgraph.h"


using namespace std;

int main()
{
    dgraph MyGraph;                 // creating a object for class d graph
    char enteredChar = ' ';         // intitialising the character to which user have to enter

    MyGraph.fillTable();            // calling the function in class dgraph for reading the txt file
    MyGraph.displayGraph();         // calling function diplayall to diplay what we read from file

    char exitloop1 = '!';           // it is for first loop to exit
    while(enteredChar != exitloop1){
        try{                        // try to catch bad values
            cout << " \nEnter the Vertex name to find out it Out degree [or type '!' for exit ] -> " << endl;
            cin >> enteredChar;     // here user enetr the char value
            if(enteredChar == exitloop1){
                cout << "\n\n\t\tExiting the First LOOP .........." <<endl;
                break;              // if user enter '!' then exit the first loop
            }
            // printing the out degree for the name user enter
            cout << " \nValue Of Out degree is Found -> " << MyGraph.findOutDegree(enteredChar) << endl;

        }// end try
        // for catch the bad value user enter program does not find
        catch(dgraph::BadVertex){
            cout << "\n\t\tThe Entered Value is Wrong, and not Found!!!!!" << endl;
        }
    }
    // creating the object for slist class to use for list
    slist MyList;
    char exitloop2 = '@';           // it is for second loop to exit

    while(enteredChar != exitloop2){            // while user not enter '@' then its keep looping
        try{
            cout << " \n\nEnter the Vertex name to find adjacent vertices [or type '@' for exit ] -> " << endl;
            cin >> enteredChar;
            if(enteredChar == exitloop2){
                cout << "\n\n\t\tExiting the Program .........." <<endl;
                break;
            }
            // here if list empty then print empty else just print its adjacency
            MyList = MyGraph.findAdjacency(enteredChar);
            if(MyList.isEmpty()){
                cout << " \n[ Empty result] " << endl;
            }else{
                MyList.displayAll();
            }

        }// end of try
        // this another catch for bad value in function findAdjancency()
        catch(dgraph::BadVertex){
            cout << "\n\t\tThe Entered Value is Wrong, and not Found!!!!!" << endl;
        }


    }







    return 0;
}
