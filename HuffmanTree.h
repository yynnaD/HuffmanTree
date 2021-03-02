//
//  HuffmanTree.cpp
//  p4
//
//  Created by Danny Gletner on 5/3/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//
#ifndef HuffmanTree_h
#define HuffmanTree_h
#include <stdio.h>
#include "minHeap.h"

/*A class for a Huffman Binary Tree
 * root is the root of the tree
 * height is the height of the tree
 * codes is a pointer to an array to hold the codes
 * totBits is the total bits used for all the codes*/
class HuffmanTree{
public:
    HuffmanTree();
    HuffmanTree(HeapNode* root);
    HeapNode* huffman(MinHeap heap);
    void setRoot(HeapNode* node);
    void printBits(HeapNode* root);
    int getTotalBytes();
private:
    HeapNode* root;
    unsigned height;
    int* codes;
    int totBits;
    void printBits(HeapNode* root, unsigned& index);
};

HuffmanTree::HuffmanTree(){
    root = NULL;
    height = 0;
    totBits = 0;
}

HuffmanTree::HuffmanTree(HeapNode* root){
    this->root = root;
    height = 0;
    totBits = 0;
}

/*Takes the lowest 2 values from the heap and combines them under a new Node
 * the new node is then inserted back into the heap.
 * heap is the heap to remove values from.
 */
HeapNode* HuffmanTree::huffman(MinHeap heap){
    int n = heap.size();
    MinHeap tmpHeap = heap;
    for(unsigned i=0; i < n-1; i++){
        HeapNode* combo = new HeapNode();
        combo->setLeft(tmpHeap.deleteMin());
        combo->setRight(tmpHeap.deleteMin());
        combo->setFreq(combo->getLeft()->getFreq() + combo->getRight()->getFreq());
        tmpHeap.insert(combo);
        height++;
    }
    return tmpHeap.getHeap()[1];
}

/*Driver function for printing the correct huffman codes from the HuffmanTree*/
void HuffmanTree::printBits(HeapNode* root){
    codes = new int[height];
    unsigned index = 0;
    printBits(root, index);
}

/*Recursively iterates through the HuffmanTree and prints out each
 * character's corresponding huffman code.
 * root is the root of the tree
 * index is the current index in the tree*/
void HuffmanTree::printBits(HeapNode* root, unsigned& index){
    int bits = 0;
    if(root->getLeft() != NULL){
        codes[index] = 0;
        unsigned ithIndex = index + 1;
        printBits(root->getLeft(), ithIndex);
    }
    if(root->getRight() != NULL){
        codes[index] = 1;
        unsigned ithIndex = index + 1;
        printBits(root->getRight(), ithIndex);
    }
    if(!root->getLeft() && !root->getRight()){
        cout << root->getCh() << " ";
        for (unsigned i = 0; i < index; i++){
            cout << codes[i];
            bits = to_string(codes[i]).length();// the huff code
        }
        cout << " " << root->getFreq() << endl; //prints frequency
        bits *= root->getFreq();
        totBits += bits;
        
    }
}

int HuffmanTree::getTotalBytes(){
    return totBits/8;
}
void HuffmanTree::setRoot(HeapNode* node){
    root = node;
}
#endif
