/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryHeap.h
 * Author: DELL
 *
 * Created on April 1, 2017, 1:49 AM
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "HuffmanNode.h"

class BinaryHeap{
private:
	HuffmanNode** storage;
	int heapSize;
	int capacity;

	void percUp(int);
	void percDown(int);
	int numChildren(int);
	
	void inOrder(int);
	void postOrder(int);
	void preOrder(int);
public:
	BinaryHeap(int);
	~BinaryHeap();
	void insert(HuffmanNode*);
	HuffmanNode* removeMin();
	HuffmanNode peekMin();

	bool isEmpty();
	int getHeapSize()							{return heapSize;};
	HuffmanNode* getRoot()						{return storage[0];};
	//traversal
	//not really necessary for Huffman, left for debug purposes
	void inOrderTraversal();
	void postOrderTraversal();
	void preOrderTraversal();
	void linearDisplay();
	//debug
	void emptyHeap();
};
#endif


