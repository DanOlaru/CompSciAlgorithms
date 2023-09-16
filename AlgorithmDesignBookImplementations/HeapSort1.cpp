//
//  HeapSort1.cpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/16/23.
//

#include "HeapSort1.hpp"

typedef int Heap[10001];

void sift(Heap heap, int n, int k) {
    int child = 0;
    
    if (k<<1 <= n) { //or 2*k
        child = k<<1;
        
        if ((child < n) && (heap[child+1] > heap[child])) {
            child++;
        }
        
        if (heap[child] <= heap[k]) child = 0;
        
    }
    
    while (child) {
        int temp = heap[child];
        heap[child] = heap[k];
        heap[k] = temp;
        
//        heap[k] = (heap[k]^heap[child])^(heap[child] = heap[k]); //???
        
        k = child;
        child = 0;
        if (k<<1 <= n) {
            child = k<<1;
            if ((child < n) && (heap[child+1] > heap[child])) {
                child++;
            }
            if (heap[child] <= heap[k]) child = 0;
        }
    }
}


void percolate(Heap heap, int n, int k) {
    int elementToMove = heap[k];
    
    while((k > 1) && (heap[k>>1] < elementToMove)) {
        heap[k] = heap[k>>1];
        k >>= 1;
    }
    
    heap[k] = elementToMove;
}
