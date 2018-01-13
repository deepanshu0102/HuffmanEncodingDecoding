/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Deepanshu
 *
 * Created on April 1, 2017, 1:43 AM
 */
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "HuffmanCode.h"
using namespace std;

int main(){
   clock_t start_time;
   start_time = clock();
	HuffmanCode* test = new HuffmanCode("sample_input_large.txt");
	test->displayTable();
	test->displayHuffmanTable();
	string code = test->getEncodedString();
//	cout << "Encoded string: " << code << endl;
	//cout << "Decoded string: " << test->decodeString(code) << endl;
//        string decode = 
//        test->decodeString(code);
//        cout<<decode;
	delete test;
	cin.get();
        cout << "Time using binary heap (microsecond):  " << (clock() - start_time)/10 << endl;
	return 0;
}
