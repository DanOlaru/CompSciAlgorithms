#include "heap_sort_dan.hpp"
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
typedef int Heap[10001];


Heap myHeap;
int countVariable = 0;

void write_output() {
    ofstream outputFile;
    
    outputFile.open("./resources/output.txt");
    
    if (outputFile.is_open()) {
        for (int i=0; i < countVariable; i++ ) {
            outputFile << myHeap[i] << " ";
        }
    }
        
    outputFile.close();
}

void sift_custom(Heap heap, int heapSize, int k) {
    int maxChildPosition = 0;
    
    if ((k << 1) < heapSize) {
        maxChildPosition = k << 1;
        
        if (maxChildPosition < (heapSize-1) && (heap[maxChildPosition+1] > heap[maxChildPosition])) {
            maxChildPosition++;
            
        }
        
        if (heap[maxChildPosition] <= heap[k]) maxChildPosition = 0;
    } else {
        maxChildPosition = 0;
    }
    
    
    while (maxChildPosition) {
        heap[k]=(heap[k]^heap[maxChildPosition])^(heap[maxChildPosition]=heap[k]);
        k = maxChildPosition;
        
        if ((k << 1) < heapSize) {
            maxChildPosition = k << 1;
            
            if (maxChildPosition < (heapSize-1) && (heap[maxChildPosition+1] > heap[maxChildPosition])) {
                maxChildPosition++;
            }
            
            if (heap[maxChildPosition] <= heap[k]) maxChildPosition = 0;
        } else {
            maxChildPosition = 0;
        }
    }
    
}

void make_heap(Heap heap, int heapSize) {
    for (int i = heapSize>>1; i>=0;) {
        sift_custom(heap, heapSize, i--);
    }
}

void heap_sort_dan(Heap heap, int heapSize) {
    make_heap(heap, heapSize);
    
    for (int i = heapSize-1; i >= 1;) {
        heap[i] = (heap[i]^heap[0])^(heap[0]=heap[i]);
        
        sift_custom(heap, --i, 0);
    }
}

void read_input() {
    ifstream inputFile;
    string token;
    inputFile.open("./resources/input.txt");
    
    if (inputFile.is_open()) {
        while(inputFile.good()) {
            inputFile >> token;
            myHeap[countVariable++] = stoi(token);
        }
    }
    
    heap_sort_dan(myHeap, countVariable);
    write_output();
}
