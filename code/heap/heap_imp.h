#include "heap.h"

#include <iostream>
#include <vector>

template <class T>
MaxHeap<T>::MaxHeap(int max_heap_size) {
    max_size_ = max_heap_size;
    heap_.reserve(max_heap_size);
}

template <class T>
int MaxHeap<T>::Size() const {
    return heap_.size();
}

template <class T>
T MaxHeap<T>::Max() {
    if (heap_.size() == 0) 
        throw std::out_of_range("zero size");
    return heap_[0];
}

template <class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x) {
    if (heap_.size() == max_size_) {
        throw std::bad_alloc::bad_alloc("size full");
    }
    heap_.push_back(x);
    int i = heap_.size() - 1;
    while (i != 0 && x > heap_[(i - 1) / 2]) {
        heap_[i] = heap_[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap_[i] = x;
    return *this;
}

template <class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x) {
    if (heap_.size() == 0) {
        throw std::out_of_range("zero size 2");
    }
    int max = heap_[0];
    int last = heap_[heap_.size() - 1];
    heap_.pop_back();
    int i = 0;
    int ci = i * 2 + 1;
    while (i <= heap_.size()) {
        if (ci < heap_.size() && heap_[ci] < heap_[ci + 1]) {
            ci++;
        }
        if (last >= heap_[ci]) break;
        heap_[i] = heap_[ci];
        i = ci;
        ci = i * 2 + 1;
    }
    heap_[i] = last;
    return *this;
}

template <class T>
void MaxHeap<T>::Initialize(T a[], int size, int array_size) {
    heap_.clear();
    max_size_ = array_size;
    for (int i = 0; i < size; ++i) {
        Insert(a[i]);
        // Output();
    }
}

template <class T>
void MaxHeap<T>::Output() const {
    std::cout << "The " << heap_.size() << " elements are" << std::endl;
    for (int i = 0; i < heap_.size(); i++) std::cout << heap_[i] << ' ';
    std::cout << std::endl;
}

// int main() {
//     MaxHeap<int> my_heap(10);
//     int a[] = {19, 20, 40, 56, 3, 9, 50};
//     my_heap.Initialize(a, 7, 10);
//     my_heap.Output();
// }