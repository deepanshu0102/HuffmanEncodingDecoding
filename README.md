# HuffmanEncodingDecoding
Huffman encoder and decoder using binary heaps.


FUNCTION PROTOTYPES
void encode(string);
-This takes a command line argument as filename of input text file to be compressed. This will generate two files - 1) Decoded data file and 2) Code table, which is the key for encoding/decoding. Filenames-  encoded.bin, code_table.txt
void decode(string, string);
-This takes two string arguments as filename of encoded.bin file and code_table.txt file. Outputs the decoded data.
