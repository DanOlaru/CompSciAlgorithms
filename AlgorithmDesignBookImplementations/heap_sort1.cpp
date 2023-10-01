//
//  HeapSort1.cpp
//  AlgorithmDesignBookImplementations
//
//  Created by Dan Olaru on 9/16/23.
//

#include "heap_sort1.hpp"
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef int Heap[10001];
int n, k;
Heap V, H;

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
    int elementToPlace = heap[k];
    
    while((k > 1) && (heap[k>>1] < elementToPlace)) {
        heap[k] = heap[k>>1];
        k >>= 1;
    }
    
    heap[k] = elementToPlace;
}

void remove_element(Heap heap, int n, int k) {
    heap[k] = heap[n--];
    
    if (k>1 && heap[k>>1] < heap[k]) {
        percolate(heap, n, k);
    } else {
        sift(heap, n, k);
    }
}

void insert_element(Heap heap, int n, int element) {
    heap[++n] = element;
    percolate(heap, n, n);
}


void build_heap(Heap heap, int n) {
    for (int i = n/2; i; sift(heap, n, i--));
}

//TODO: test this
int heap_search_recursive(Heap heap, int n, int quarry, int index = 0) {
    int result = -1;
    
    if (heap[index] == quarry) {
        return index;
    } else if (index < (n>>2)) {
        if (heap[index<<1] > quarry) {
            result = heap_search_recursive(heap, n, quarry, index<<1);
        };
        if ((result == -1) && (heap[(index<<1)+1] > quarry)) {
            result =  heap_search_recursive(heap, n, quarry, (index<<1) + 1);
        }
    }
    
    return result;
}

void print_data(Heap heap, int arrayLength) {
    for(int i = 1; i <= arrayLength; i++) {
        cout<< H[i] << " ";
    }
    cout << endl;
}

void heap_sort(Heap heap, int n) {
    build_heap(heap, n);

    for (int i = n; i>=1;) {
        heap[1] = (heap[1] ^ heap[i]) ^ (heap[i] = heap[1]);  //XOR variable swapping
        
        sift(heap, --i, 1);
    }
}


void read_data() {
    ifstream myfile;
    myfile.open("./resources/input.txt");

    string mystring;
    int arrayLength = 0;

    if ( myfile.is_open() ) {
        while(myfile.good()) {
            myfile >> mystring;
            H[++arrayLength] = stoi(mystring);
        }
    }
    
    n = arrayLength-1;
    cout << " read array len " << n  << endl;
    
//    print_data(H, n);
    
    heap_sort(H, n);
    
    print_data(H, n);
}

