CC=g++
CCFLAGS=-std=c++11

huffencode:   HuffmanNode.o HuffmanTree.o helper.o Driver.o
	$(CC) $(CCFLAGS) Driver.o HuffmanNode.o HuffmanTree.o helper.o -o huffencode
   
test: Tests.o 
	$(CC) Tests.o helper.o HuffmanNode.o HuffmanTree.o -o test

HuffmanNode.o : HuffmanNode.cpp HuffmanNode.h
	$(CC) $(CCFLAGS) -o HuffmanNode.o -c HuffmanNode.cpp
   
HuffmanTree.o : HuffmanTree.cpp HuffmanTree.h
	$(CC) $(CCFLAGS) -o HuffmanTree.o -c HuffmanTree.cpp
   
helper.o: helper.cpp helper.h
	$(CC) $(CCFLAGS) -o helper.o -c helper.cpp   
     
Driver.o : Driver.cpp
	$(CC) $(CCFLAGS) -o Driver.o -c Driver.cpp

Tests.o: Tests.cpps
	$(CC) $(CCFLAGS) -o Tests.o -c Tests.cpp 

clean:
	rm -rf *.o