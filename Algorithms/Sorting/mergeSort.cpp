
//=========================================================
//HW#: HW2P2 Merge Sort
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: main program file
//===========================================================

#include <iostream>
#include <vector>
using namespace std;




//PURPOSE: This function named Combine is working with different
//          loops to perform the Merge Sort with the help of two
//          different list which stored into the two different vectors.
//PARAMETER: passing the three different vectors A, B and R
//          vector A contains a sorted number list
//          vector B contains a sorted number list
//          vector R will stored the sorted elements
//          from the Vector A and B.
void Combine(vector<int>& A, vector<int>& B, vector<int>& R){
    int i = 0; // this for a index for vector A
    int j = 0; // this for a index for vector B
    int k = 0; // this for a index for vector R


    // This while loop run till Vector A and Vector
    // B will increment to the last element of Vector
    while(i < A.size() && j < B.size()){

        // This if condition check whether first element of Vector A
        // is smaller than first element of vector B then push that
        // element to the Vector R Else the element from B will pushed
        // to the Vector R.

        // This process is loop till above while condition is full filled
        if(A[i] < B[j]){
            R.push_back(A[i]);      // pushing the value from Vector A to the Vector R
            i++;       // incrementing the element of vector A
        }else{
            R.push_back(B[j]);    // pushing the value from Vector B to the Vector R
            j++;       // incrementing the element of vector A
        }
    }

    // At the end of above loop if some element left out in Vector A
    // then this loop will pushed the rest element to the Vector R
    if(i<A.size()){
        while(i<A.size()){
            R.push_back(A[i]);
            i++;
        }

    // At the end of above loop else if some element left out in Vector B
    // then this loop will pushed the rest element to the Vector R
    }else if(j<B.size()){
        while(j<B.size()){
            R.push_back(B[j]);
            j++;
        }
    }

}





//PURPOSE: This function named main will ask user for input and
//          then manipulating the function name Combine

int main()
{

    vector<int> L1;     // This is declaration vector for list 1
    vector<int> L2;     // This is declaration vector for list 2
    vector<int> L3;     // This is declaration vector for list 3 which is combined later the sorted list 1 and 2

    int NumOfElem;      // number of element in each list 1 and list 2
    int List1Elem;      // list 1 element entered on by one
    int List2Elem;      // list 2 element entered on by one


    // This will ask user for how manny element does wants in each list
    cout << "Enter the number of element you want in the each list: " << endl;
    cin >> NumOfElem;


    // this c out statement is that from now u entering elements for list 1
    cout << "Enter the numbers in increasing order for List-1: " << endl;
    //this loop pushed the value entered by user into the vector L1
    for(int i = 0; i < NumOfElem; i++){
        cout << "\nEnter Number " << i+1 << " :\t";
        cin >> List1Elem;
        L1.push_back(List1Elem);
    }



     // this c out statement is that from now u entering elements for list 2
    cout << "\nEnter the numbers in increasing order for List-2: " << endl;
    //this loop pushed the value entered by user into the vector L2
    for(int j = 0; j < NumOfElem; j++){
        cout << "\nEnter Number " << j+1 << " :\t";
        cin >> List2Elem;
        L2.push_back(List2Elem);
    }

    // calling the combined function to sort the two list with Merge Sort
    Combine(L1, L2, L3);

    // this line shows that the printout for list 3
    cout << "The combined elements in List 3 are: "<< endl;

    // this loop is printing out the list L3 for one by one
    for(int k = 0; k < L3.size(); k++){
        cout << " " <<L3[k] ;
    }

    return 0;
}

