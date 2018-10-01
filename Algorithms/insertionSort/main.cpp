#include <iostream>
#include <vector>


void inertionSort(std::vector<int> ListOfElement){

    bool condition = false;

    int prevIndex, nextValue, i;

    for(i = 1; i < ListOfElement.size(); i++){

        nextValue = ListOfElement[i];
        prevIndex = i-1;
        while(ListOfElement[prevIndex] > nextValue && prevIndex >= 0){
            ListOfElement[prevIndex+1] = ListOfElement[prevIndex];
            prevIndex = prevIndex - 1;
        }
        ListOfElement[prevIndex+1] = nextValue;
    }


    std::cout << "List of SORTED by Insertion Sort values are: \n " << std::endl;
    for(int i = 0; i < ListOfElement.size(); i++){
        std::cout << ListOfElement[i] << std::endl;
    }

}

int main()
{
    int input;  // How many element has to enter


    std::cout << "How many element you want to enter: " << std::endl;
    std::cin >> input;

    std::vector<int> ListOfElement;


    while(input != 0){
        int value;  // value of each element
        std::cout << "\nEnter the elements: ";
        std::cin >> value;
        ListOfElement.push_back(value);
        input--;
    }


    std::cout << "List of values are: \n " << std::endl;
    for(int i = 0; i < ListOfElement.size(); i++){
        std::cout << ListOfElement[i] << std::endl;
    }


    inertionSort(ListOfElement);
    return 0;
}


