//
//  main.cpp
//  p4
//
//  Created by Danny Gletner on 4/29/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "minHeap.h"
#include "heapNode.h"
#include "HuffmanTree.h"

using namespace std;

/*Main function. Reads in a file of characters and outputs the Huffman codes.*/
int main(int argc, const char * argv[]) {
    
    fstream inFile;
    string filename = argv[1];
    char letter;
    const int SIZE = 256;
    int frequencies[SIZE];
    
    for(unsigned i=0; i<SIZE; i++){
        frequencies[i] = 0;
    }
    
    MinHeap minHeap(SIZE);
    
    inFile.open(filename.c_str());
    if(!inFile)
        cout << "Error opening file..." << endl;
    else{
        while(inFile.get(letter) && !inFile.eof()){
            frequencies[letter]++;
        }
    }
    inFile.close();
    
    for(unsigned i=0; i<SIZE; i++){
        if(frequencies[i] > 0){
            HeapNode* newNode = new HeapNode(i, frequencies[i]);
            minHeap.insert(newNode); 
        }
    }
    HuffmanTree tree;
    HeapNode* root = tree.huffman(minHeap);
    tree.setRoot(root);
    tree.printBits(root);
    cout << "This file could be compressed into " << tree.getTotalBytes() << " bytes." << endl;
}
