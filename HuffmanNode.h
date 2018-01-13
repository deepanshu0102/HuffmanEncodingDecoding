/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HuffmanNode.h
 * Author: DELL
 *
 * Created on April 1, 2017, 1:48 AM
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <iostream>
#include <string>
using std::string;
using std::ostream;

class HuffmanNode{
private:
	int frequency;
	string letter;
	string code;
	HuffmanNode* left, *right;
public:
	HuffmanNode();
	HuffmanNode(string, int);
	HuffmanNode(HuffmanNode*, HuffmanNode*);
	HuffmanNode(const HuffmanNode&);
	~HuffmanNode();
	int getFrequency()							{return frequency;};
	string getLetter()							{return letter;};
	string getCode()							{return code;};
	HuffmanNode* getLeft()						{return left;};
	HuffmanNode* getRight()						{return right;};

	void setHuffmanCode(string s)				{code = s;};
	friend ostream& operator<<(ostream&, const HuffmanNode&);

	HuffmanNode& operator=(const HuffmanNode&);
};


#endif /* HUFFMANNODE_H */

