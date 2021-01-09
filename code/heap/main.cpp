#include <iostream>

#include "heap.h"

int main() {
    MaxHeap<int> my_heap(10);
    int a[] = {19, 20, 40, 56, 3, 9, 50};
    my_heap.Initialize(a, 7, 10);
    my_heap.Output();
}