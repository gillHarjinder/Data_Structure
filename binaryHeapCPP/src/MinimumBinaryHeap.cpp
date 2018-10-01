#include "MinimumBinaryHeap.h"
#include <iostream>
#include <array>


MinimumBinaryHeap::MinimumBinaryHeap(int max_heap){
    max_size = max_heap;
    current_size = 0;
    b_heapArray = new int[max_heap];

}


/*
    Insert method used to insert element in array
    using minimum binary heap
*/
int MinimumBinaryHeap::insertElement(int key){
    if(max_size == current_size){
        std::cout << "Overflow: Array is filled, no place for Insertion" << std::endl;
    }else{
        b_heapArray[current_size] = key;
        current_size++;
        std::cout << "\ninserted and array size: " << sizeof(b_heapArray) << std::endl;
    }
}


/**
    Display method
*/

void MinimumBinaryHeap::display(){

    std::cout << "Max size of Binary Heap is " << max_size << std::endl;
    std::cout << "\n\nCurrent Size of heap is " << current_size << std::endl;

}

/*
    Display Binary Heap sort in array
*/

void MinimumBinaryHeap::dispay_Array(){
    int i = 0;
    while(i != current_size){
        std::cout << " element at index '" << i << "' is: " << b_heapArray[i] << std::endl;
        i++;
    }

}
