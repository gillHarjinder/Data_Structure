
//=========================================================
//HW#: HW2P1 binary search
//Your name: Harjinder Gill
//Complier:  g++ and CodeBlock
//File type: main program file
//===========================================================

#include <iostream>

using namespace std;


// this an constant global value initialization for the size of an array
const int numberOfElement = 10;

//PURPOSE: This function named binarySearch function is work recursively
//          to find the number entered by the user
//PARAMETER: pass the array with elements, the element need to find(x),
//          the first letter index(first),
//          and the last element index(last) in the array
int binarySearch(int L[], int x, int first, int last){
   // this start with if first index is bigger than last
   //then there is only one element and
   // its not that element which we looking for
   // so its return negative value
   if(first>last){
         return -(first +1);
   }else{

       // else this gona search for middle value in array
        int middle = (first+last)/2;
        if (x == L[middle]) {  // if entered value is equal to the middle value of an array then its return
            return middle;  // found x at location middle
        }else if (x < L[middle]) {// checking if value is less than the middle value
            // if it is less than middle value then go to first half by replacing the
            // last element with element is before middle element by recursive call
            binarySearch(L, x, first, middle-1);
        }else if(x > L[middle]){// checking if value is more than middle value
            // if it is more than middle value then go to second half by replacing
            // the first element with element is after middle element in recursive call
            binarySearch(L, x, middle+1, last);
        }
   }


}



int main()
{

    // Here resultloc set to 1 because we have to notify the position start from 1 not zero
    int resultloc = 1;
    // This an array of of sorted numbers which we about to search by binary search algorithm.
    int myList[numberOfElement] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    // this is an input initialization value which have to find from the array of sorted element
    int findthis;



    // This command ask user to inter the number which he wants to find
    cout << "Enter the number you want to find: " << endl;
    cin >> findthis;

    // This try method look for the unauthorizes elements throw to catch in catch statement
    try{
        int myfirst = 0;       // here myfirst and mylast are index numbers for array
        int mylast = numberOfElement-1;

        // if the entered number is less than the first element of an array than throw a error
        if(findthis < myList[myfirst]){
            throw findthis;

        // else if the entered number is greater than the last element of an array than throw a error
        }else if(myList[mylast]<findthis){
            throw findthis;

        // and if abouve two cases are not true than send the value to the binarysearch function to find the number
        }else{
           resultloc = binarySearch(myList, findthis, myfirst, mylast);
        }

        // here am adding 1 to the resultloc to satisfy the next condition.
        resultloc = resultloc + 1;

        // if return value is negative 1 by binary search function then its means word is not found
        // and the by adding 1 into -1 less than zero and therefore, it print the line with fail message
        if(resultloc < 0){
            cout << "Find " << findthis << " fails" << endl;
        // but if above condition is not true then, function finds the word with its position and
        // print the message that find a element in certain position
        }else{
            cout << "Find "<<findthis << " in position "  << resultloc <<  endl;
        }
    // this function catch the thrown value in try statement
    }catch(int num){
        cout << "Find " << num << " fails" << endl;
    }
    return 0;
}
