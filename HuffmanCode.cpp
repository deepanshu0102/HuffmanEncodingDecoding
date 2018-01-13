/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HuffmanCode.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include <bitset>

using namespace std;
int len;


HuffmanCode::HuffmanCode(string src){
	//data = src;
    data="";
    //ifstream file(src);
    ifstream fin("sample_input_large.txt");
    string name;
    len=1;
    while(fin>>name)
    {
        len++;
       string x =name ;
       //cout<<x;
       buildTable(x);
        //str=str+""+name;
    }
	encodedData = "";
	//worst case scenario, all unique characters
	//must accomodate
	heap = new BinaryHeap(len);
//        for(map<int,int>::iterator it = frequencyTable.begin(); 
//		it != frequencyTable.end(); ++it){
//			cout << it->first << "\t" << it->second << endl;
//	}

        
  
	//buildTable();
	buildHeap();
}

HuffmanCode::~HuffmanCode(){
	if(heap != NULL) delete heap;
}

void HuffmanCode::buildTable(string dataseg){
//    cout<<dataseg<<" ";
  
//	for(size_t i = 0; i < data.length(); i++){
//		char c = data.at(i);
    
		if (frequencyTable.find(dataseg) == frequencyTable.end())
                {
			frequencyTable.insert(pair<string, int>(dataseg, 1));
		}
		else{
			frequencyTable[dataseg]++;
		}
//	}
}

void HuffmanCode::buildHeap(){
	//fill heap
	for(map<string,int>::iterator it = frequencyTable.begin(); 
		it != frequencyTable.end(); ++it){
			heap->insert(new HuffmanNode(it->first, it->second));
	}
	//pop off two at a time until you get one left
	while(!heap->isEmpty()){
		if(heap->getHeapSize() == 1) break;
		HuffmanNode* left = heap->removeMin();
		HuffmanNode* right = heap->removeMin();
		heap->insert(new HuffmanNode(left, right));
	}
	//final one is the root of your encoding tree
	string code = "";
	getHuffmanEncoding(heap->getRoot(), code);
	encode();
}

void HuffmanCode::getHuffmanEncoding(HuffmanNode* root, string code){
	if(root->getLeft() == NULL){
		root->setHuffmanCode(code);
		huffmanTable.insert(pair<string, string>(root->getLetter(), code));
		return;
	}
	else{
		getHuffmanEncoding(root->getLeft(), code+"0");
		getHuffmanEncoding(root->getRight(), code+"1");
	}
}

void HuffmanCode::displayTable(){
	cout << "Frequency Table:" << endl;
        fstream ft;
        ft.open ("FrequencyTable.txt", ios::out);
	for(map<string,int>::iterator it = frequencyTable.begin(); 
		it != frequencyTable.end(); ++it){
//			cout << it->first << "\t" << it->second << endl;
            ft<<it->first<<"->"<<it->second<<"\n";
	}
}

void HuffmanCode::displayHuffmanTable(){
	cout << "Huffman Table:" << endl;
        fstream ft;
        ft.open ("code_table.txt", ios::out);
	for(map<string,string>::iterator it = huffmanTable.begin(); 
		it != huffmanTable.end(); ++it){
//			cout << it->first << "\t" << it->second << endl;
            ft<<it->first<<"->"<<it->second<<" ";
            
	}
}
//
void HuffmanCode::encode(){
//	for(size_t k = 0; k < len; k++){
//		encodedData.append(huffmanTable[data.at(k)]);
//		encodedData.append(" ");
//	}
    fstream fout;
//    fout.open ("Encod.txt", ios::out);
    ifstream fin("sample_input_large.txt");
    string name;
    string z="";
    while(fin>>name)
    {
       string x =name;
      encodedData.append(huffmanTable[x]);
//       z = huffmanTable[x];
       fout<<huffmanTable[x];
//       z="";
    }
    int i;

    ofstream bin_file("encoded.bin", ios::out| ios::binary);
    
    long size = sizeof(char);
    unsigned long long enc_length = encodedData.size();
    
    for(unsigned long long i=0;i<enc_length;i+=8)
    {
        string block = encodedData.substr(i,8);
        char* ptr;
        long parsed = strtol(block.c_str(),&ptr,2);
        bin_file.write(reinterpret_cast<char*>(&parsed),size);
    }
   
}
//
void HuffmanCode::decodeString(string src){
//	string info = "";
//	size_t lastBlock = 0;
//	for(size_t i = 0; i < src.length(); i++){
//		if (src.at(i) == ' '){
//			string temp = src.substr(lastBlock, i-lastBlock);
//			lastBlock = i+1;
//			for(map<string,string>::iterator it = huffmanTable.begin();
//				it != huffmanTable.end(); ++it){
//					if (it->second == temp){
//						//info += (it->first);
//                                                cout<<it->first<<endl;
//						break;
//					}
//			}
//		}
//
//	}
//	return info;
        getHuffmanDecoding(heap->getRoot(),src,0);
    
}

void HuffmanCode::getHuffmanDecoding(HuffmanNode* tp, string code,int k){

    /* if(root->getLeft() == NULL){
            cout<<root->getLetter();
		root->setHuffmanCode(code);
		huffmanTable.insert(pair<string, string>(root->getLetter(), code));
		return;
	}
	else if(code[i]==0){
		getHuffmanDecoding(root->getLeft(), code+"0");
		getHuffmanDecoding(root->getRight(), code+"1");
        * ///////////ruk ja abhi 
	}*/
//    tp=heap->getRoot();
    string temp = "";
    int i;
    for(i = k ; i <=code.size() ; i++)
    {

//        if(root == NULL ){
//            cout<<"not possible , error in encoded_str";
//            return temp;
//        }
        if(tp->getLeft()==NULL){
            temp=tp->getLetter();
            cout<<temp;
            break;
        }
        if(code[i]=='0')
            tp= tp->getLeft() ;
        else if(code[i]=='1')
            tp= tp->getRight() ;   
        
       
      
            //return temp;    
    }
    k=i;
    temp="";
    if(k!=code.size())
        getHuffmanDecoding(heap->getRoot(),code,k);
    
//    cout<<temp;
}
  

void HuffmanCode::displayHeap(){
	heap->inOrderTraversal();
}
