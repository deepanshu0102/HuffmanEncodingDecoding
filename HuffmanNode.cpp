/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HuffmanNode.cpp
 * Author: DELL
 *
 * Created on April 1, 2017, 1:48 AM
 */

#include "HuffmanNode.h"
using namespace std;

HuffmanNode::HuffmanNode(){
	letter="" ;
	frequency = 0;
	left = right = NULL;
}

HuffmanNode::HuffmanNode(string c, int i){
	letter = c;
	frequency = i;
	left = right = NULL;
}

HuffmanNode::HuffmanNode(HuffmanNode* left, HuffmanNode* right){
	this->left = left;
	this->right = right;
	frequency = left->getFrequency() + right->getFrequency();
	letter = "";
}

HuffmanNode::~HuffmanNode(){
	if(left != NULL) delete left;
	if(right != NULL) delete right;
}

HuffmanNode::HuffmanNode(const HuffmanNode& rhs){
	//cout << "in copy constructor copying: " << rhs.letter << endl;
	
	if(rhs.left != NULL){
		left = new HuffmanNode();
		*left = *(rhs.left);
	}
	if(rhs.right != NULL){
		right = new HuffmanNode();
		*right = *(rhs.right);
	}
	code = rhs.code;
	letter = rhs.letter;
	frequency = rhs.frequency;
}


ostream& operator<<(ostream& os, const HuffmanNode& rhs){
	os <<  "\'" << rhs.letter << " " << rhs.frequency << "\' ";
	return os;
}

HuffmanNode& HuffmanNode::operator=(const HuffmanNode& rhs){
	//cout << "In assigbnment operator overload." << endl;
	if(!(this == &rhs)){
		//copy
		code = rhs.code;
		letter = rhs.letter;
		frequency = rhs.frequency;
		if(!(left == NULL)) delete left;
		if(!(right == NULL)) delete right;

		if(rhs.left != NULL){
			left = new HuffmanNode();
			*left = *(rhs.left);
			if(rhs.right != NULL){
				right = new HuffmanNode();
				*right = *(rhs.right);
			}
		}
		else left = right = NULL;
	}
	return *this;
}
