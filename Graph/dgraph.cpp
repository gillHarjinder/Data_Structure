// ====================================================
//HW#: HW6 dgraph
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: cpp file
//=====================================================


#include <fstream>
#include <iostream>
#include <string>
#include "slist.h"
#include "dgraph.h"


// calling constructor
dgraph::dgraph()
{
    countUsed = 0;                              // initializing the countUsed to 0
    for (int i = 0; i < SIZE; ++i) {
        Gtable[i].vertexName = ' ';             // initializing the vertexName to empty char
        Gtable[i].outDegree = 0;                // initializing the outDegree to 0
        Gtable[i].visit = 0;                    // initializing the visit to 0
    }
}





// calling destructor
dgraph::~dgraph(){

}



//PURPOSE: reads the input file table.txt to fill the table
//          Open and close the input file table.txt in here
void dgraph::fillTable(){

    ifstream fin;

    fin.open("table.txt");
    char X;
    if(!fin){
        cout << "There is not input file exist!!!!" << endl;
    }
    while (fin >> X){  // if I can read the name
        Gtable[countUsed].vertexName = X;
        fin >> (Gtable[countUsed].outDegree);
        // Then for the outDegree times do the following: (use a for-loop)
        // this uses a slist function from HW3
        for (int i = 0; i < Gtable[countUsed].outDegree; i++){
            fin >> X;
            (Gtable[countUsed].adjacentOnes).addRear(X);
        }//end of for
        // increment the countUsed
        countUsed++;
    }//end of while


//close fin
    fin.close();


}


//PURPOSE: This function displays the table content in a very readable format
//			But make sure you do not display unused slots

void dgraph::displayGraph(){
    for(int i = 0; i<countUsed; i++){
        cout << Gtable[i].vertexName << ":" << endl;
        if(!Gtable[i].adjacentOnes.isEmpty()){
            Gtable[i].adjacentOnes.displayAll();
        }else{
            cout << "[Empty]" << endl;
        }
    }


}



//PURPOSE: This function returns the out degree of the vertex
//          whose name is given as an argument
//	         Use a loop but search through used slots only.
//            and throwing the badVertax if it does not match

//PARAMETER: pass the character (x) to find out the degree of vertacies

int dgraph::findOutDegree(char x){
    for(int i = 0; i< countUsed; i++){
        if(Gtable[i].vertexName == x){
            return Gtable[i].outDegree;
        }
    }

    throw BadVertex();



}



//PURPOSE: this function returns the linked list of
//          adjacent vertices of
//          the vertex whose name is given as an argument
//	        Use a loop but search through used slots only.
//	        and throwing the badVertax if it does not match

//PARAMETER: pass the character (x) to find out the degree of vertacies
slist dgraph::findAdjacency(char x){
    for(int i = 0; i<countUsed; i++){
        if(Gtable[i].vertexName == x){
            return (Gtable[i].adjacentOnes);
        }
    }
    throw BadVertex();

}








