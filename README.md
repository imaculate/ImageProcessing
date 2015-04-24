Author: Imaculate Mosha

Date: 6th April 2015
Name: A huffman encoding algorithm. 


Description: 
This assignment is written to in responce to answer assignment 3 question to create a huffman encoding compression algorithm.   
It reads a file and creates a huffman tree used to compress the file. It then produces an output file from the 
huffman table. The compressed file is saved as a bitstream in <out>.bin file.It also provides a method to
extract the encoded string from the binary file.  

Instructions: Extract the tar file. Navigate to the destination folder from the command line. 
Enter make

Run( huffencode <inputfile> <outputfile> )
eg( huffencode test1 test1out)

For unit testing :
compile with (make test)
run test.
 
	 

List of files: 

HuffmanTree.h -header file for HuffmanTree class.
HuffmanTree.cpp -defines HuffmanTree class methods .
HuffmanNode.h - header file for HuffmanNode class.
HuffmanNode.cpp - defines HuffmanNode class methods.
Driver.cpp -driver file for the program
Makefile - used to run the program.
test1.txt test2.txt - used for unit testing


Output format.

<out>.hdr -header containing frequency table
<out>.data - header containing number of bytes in bitstream
<out>.bin - binary file containing bitstream
<out>.txt - ascii file containing encoded string in plain text. 
