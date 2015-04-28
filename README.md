Author: Imaculate Mosha

Date: 28th April 2015
Name: An Image Processing tool.  


Description: 
This assignment is written to in responce to answer assignme nt 4 question to use class structures to manipulate pgm images.
Operators such as +, ! , -, have been overloaded in the Image class to perform operations such as addition, threshold, mask , invert among others. Also iterator class has been defined as a friend
to Image to access its private variables. The result of each operation will be written to a result file.

Instructions: Extract the tar file. Navigate to the destination folder from the command line. 
Enter make to compile

Run( imageops <option> <parameters> )
eg( imageops -a  Lenna_stanard.pgm Lenna_hat_mask.pgm)

For unit testing :
compile with (make test)
run test.
 
	 

List of files: 

Image.h -header file for Image, iterator
Matrix.h - for filtering.
Image.cpp  for image manipulation.
iterator.cpp - for image iterators.
Tests.cpp - for unit testing.
Driver.cpp


Output format.

<operation-result.pgm>
eg, <add-result.pgm>