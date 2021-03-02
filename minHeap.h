//
//  PriorityQueue.cpp
//  p4
//
//  Created by Danny Gletner on 4/29/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//
#ifndef minHeap_h
#define minHeap_h
#include <stdio.h>
#include "heapNode.h"
#include <string>
using namespace std;

/*A class for a minHeap structure.*/
class MinHeap{
public:
    MinHeap(unsigned cap);
    void insert(HeapNode* newNode);
    HeapNode* deleteMin();
    void displayHeap();
    unsigned size();
    HeapNode** getHeap();
private:
    unsigned currentSize;
    HeapNode** heap;
    void percolateDown(int hole);
    
};

MinHeap::MinHeap(unsigned cap){
    heap = new HeapNode*[cap];
    currentSize = 0;
    heap[0] = NULL;
}

/* Inserts a node into the heap, then moves it to the correct spot to maintain heap order.
 * newNode is the node to be inserted.
 */
void MinHeap::insert(HeapNode* newNode){
    int hole = currentSize++;
    HeapNode* copy = newNode;
    
    heap[0] = copy;
    for(; newNode->getFreq() < heap[hole/2]->getFreq(); hole/=2){
        heap[hole] = heap[hole/2];
    }
    heap[hole] = copy;
}

/*Removes the minimum value from the heap, which is the first item because it is a minHeap.*/
HeapNode* MinHeap::deleteMin(){
    HeapNode* min = NULL;
    if(currentSize == 0)
        cout << "Nothing to remove..." << endl;
    else{
        currentSize--;
        min = heap[1];
        heap[1] = heap[currentSize];
        percolateDown(1);
    }
    return min;
}

/*A method to re-place a node with the lowest priority back into the heap
 * to fill space created after a removal.
 * hole is the location in the heap where the hole will percolate down from
 */
void MinHeap::percolateDown(int hole){
    int child;
    HeapNode* tmp = heap[hole];
    
    for(; hole*2 <= currentSize; hole = child){
        child = hole*2;
        if(child!= currentSize && heap[child+1]->getFreq() < heap[child]->getFreq())
            child++;
        if(heap[child]->getFreq() < tmp->getFreq())
            heap[hole] = heap[child];
        else break;
    }
    heap[hole] = tmp;
    
}

unsigned MinHeap::size(){
    return currentSize;
}

HeapNode** MinHeap::getHeap(){
    return heap;
}

/*Displays the contents of the heap.*/
void MinHeap::displayHeap(){
    for(unsigned i=1; i<currentSize; i++){
        cout << i << ": " << heap[i]->getCh() << ", " << heap[i]->getFreq() << endl;
    }
}
#endif
