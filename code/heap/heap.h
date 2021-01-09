#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdexcept>
#include <vector>

template<class T>
class MaxHeap {
public:
    MaxHeap(int max_heap_size = 10);
    int Size() const ;
    T Max() ;
    MaxHeap<T>& Insert(const T& x);
    MaxHeap<T>& DeleteMax(T& x);
    void Initialize(T a[], int size, int array_size);
    void Output() const;
private:
    int max_size_;
    std::vector<T> heap_;
};
#include "heap_imp.h"
#endif //_HEAP_H_