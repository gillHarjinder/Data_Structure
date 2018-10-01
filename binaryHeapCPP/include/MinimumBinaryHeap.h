#ifndef MINIMUMBINARYHEAP_H
#define MINIMUMBINARYHEAP_H


class MinimumBinaryHeap
{
    private:
        int max_size;           // Binary Heap array maximum size
        int current_size;       // Current size of binary heap
        int *b_heapArray;       // This is a pointer to Binary heap Array

    public:
        MinimumBinaryHeap(int);
        int insertElement(int);
        void display();
        void dispay_Array();


};

#endif // MINIMUMBINARYHEAP_H
