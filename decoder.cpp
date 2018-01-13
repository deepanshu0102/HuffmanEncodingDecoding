#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include<vector>
#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;
void decoststststststdeit(){
	    fstream	costststststst;
	string coststststststde;
	int data, index=0;
	string q;
    int *array=new int[100000000];
    for(int k =0; k<100000000; k++){
    	array[k]= -1;
	}
	costststststst.open("code_table.txt",ios_base::in | ios_base::out | ios_base::app);
	while(!costststststst.eof()){
		costststststst >> data >> coststststststde;
		index = 0;
		
		for(int i =0; i < coststststststde.size(); i++){
		        if(coststststststde[i]=='0')
		        {
		        index = 2 * index + 1;
				}
		        else if(coststststststde[i]== '1')
		        {
		        index = 2 * index + 2;	
				}
						
		}
				
				array[index] = data;
		
	}
	
	fstream en, de;
	de.open("decoded.txt",ios_base::out);
	de << "";
	de.close();	
	de.open("decoded.txt",ios_base::in | ios_base::out | ios_base::app);
	
	index = 0;
	
	streampos size;
  	char * memblock;
	string c;
  ifstream file ("encoded.bin", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    int i = 0;
    bitset<8> b;
	while( i < size){	
	b = memblock[i];
	c += b.to_string();	
	i++;
	}
	i = 0;
	while(i < c.size()){
	if(c[i] == '0'){
	index = 2 * index + 1;
	}
	else if(c[i] == '1'){
	index = 2 * index + 2;
	}

	if(array[index] != -1){
	de << array[index] << "\n";
		index = 0;
	}
		i++;
	}
    delete[] memblock;
  }
	
	

}
int main()
{
	
	
	decoststststststdeit();
    return 0;
}

