/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HuffmanCode.h
 * Author: DELL
 *
 * Created on April 1, 2017, 1:53 AM
 */

#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include <string>
#include <map>
#include"BinaryHeap.h"
using std::string;
using std::map;

class HuffmanCode{
public:
	string data;
        //int datalength;
	string encodedData;
	BinaryHeap* heap;
	map<string, int> frequencyTable;
	map<string, string> huffmanTable;
	void buildTable(string);
	void buildHeap();
	void getHuffmanEncoding(HuffmanNode*, string);
	void encode();

	HuffmanCode(string);
	~HuffmanCode();
	string getSourceString()						{return data;};
	string getEncodedString()						{return encodedData;};
	void displayTable();
	void displayHeap();
	void displayHuffmanTable();
	void decodeString(string);
        void getHuffmanDecoding(HuffmanNode*, string,int);

	//debug
	void emptyHeap()								{heap->emptyHeap();};
};

#endif /* HUFFMANCODE_H */

