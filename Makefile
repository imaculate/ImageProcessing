CC=g++
CCFLAGS=-std=c++11

imageops:  Image.o  iterator.o Driver.o  
	$(CC) $(CCFLAGS) Driver.o Image.o   -o imageops
   

Image.o : Image.cpp Image.h iterator.o
	$(CC) $(CCFLAGS) -o Image.o -c Image.cpp

iterator.o : iterator.cpp iterator.h 
	$(CC) $(CCFLAGS) -o iterator.o -c iterator.cpp

Driver.o : Driver.cpp
	$(CC) $(CCFLAGS) -o Driver.o -c Driver.cpp

test: Tests.o 
	$(CC) Tests.o Image.o -o test


Tests.o: Tests.cpp
	$(CC) $(CCFLAGS) -o Tests.o -c Tests.cpp 

clean:
	rm -rf *.o