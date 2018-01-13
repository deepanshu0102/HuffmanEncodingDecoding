# HuffmanEncodingDecoding
Huffman encoder and decoder using binary heaps.

To run complie all the files and then run encoder.cpp to encode input data and run decoder.cpp to decode encoded data.

FUNCTION PROTOTYPES

void encode(string);
-This takes a command line argument as filename of input text file to be compressed. This will generate two files - 1) Decoded data file and 2) Code table, which is the key for encoding/decoding. Filenames-  encoded.bin, code_table.txt



void decode(string, string);
-This takes two string arguments as filename of encoded.bin file and code_table.txt file. Outputs the decoded data.
