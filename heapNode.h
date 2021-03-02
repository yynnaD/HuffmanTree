//
//  heapNode.cpp
//  p4
//
//  Created by Danny Gletner on 5/2/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//
#ifndef heapNode_h
#define heapNode_h
#include <stdio.h>

/*Node to be used in the creation of the Huffman tree.
 * ch is the character value of the node
 * left is the left child
 * right is the right child
 * freq is the frequency of this character*/
class HeapNode{
public:
    HeapNode();
    HeapNode(unsigned value, unsigned freq);
    unsigned getFreq();
    char getCh();
    HeapNode* getLeft();
    HeapNode* getRight();
    void setLeft(HeapNode* node);
    void setRight(HeapNode* node);
    void setFreq(unsigned freq);
private:
    char ch;
    HeapNode* left;
    HeapNode* right;
    unsigned freq;
};
HeapNode::HeapNode(){
    ch = NULL;
    left = NULL;
    right = NULL;
    freq = 0;
}
HeapNode::HeapNode(unsigned value, unsigned freq){
    ch = char(value);
    this->freq = freq;
    left = NULL;
    right = NULL;
}

void HeapNode::setLeft(HeapNode* node){
    this->left = node;
}

void HeapNode::setRight(HeapNode* node){
    this->right = node;
}

HeapNode* HeapNode::getLeft(){
    return left;
}

HeapNode* HeapNode::getRight(){
    return right;
}
unsigned HeapNode::getFreq(){
    return freq;
}

void HeapNode::setFreq(unsigned freq){
    this->freq = freq;
}

char HeapNode::getCh(){
    return ch;
}
#endif
