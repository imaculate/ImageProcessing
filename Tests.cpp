#include <unordered_map>
#include "Image.h"
#include "Matrix.h"
#include <stdlib.h>

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace MSHIMA001;

/*Move and copy semantics
• Iterator and its operators (including boundary conditions)
• Thresholding, inverting and masking operator overloads
• Addition and subtraction of images. Ensure that the pixels are clamped
appropriately.
• [optionally] the filtering operator. Take special care to test the boundary
conditions*/
TEST_CASE( "testing on the test case u1, u2", "trial.txt") {
   //generate random images.
   unsigned char* buffer1 = new unsigned char[16];
   for(int i = 0; i< 8; i++){
      buffer2[i] = rand()%95  + 160; //this should be in the upperhalf to be 255 after thresholding
   }
   for(int i = 8; i< 16; i++){
      buffer2[i] = rand()%160 ; //this should be in the upperhalf to be 255 after thresholding
   }
    Image m(4,4, buffer1);
    
    m1 = m*160;
    
   m2 = !m1;
   

    REQUIRE(freq['o'] == 1);
   
   unsigned char* buffer2 = new unsigned char*[16];
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 256;
   }
   Image u1(4,4, buffer2);
   
   Image o1 = u1 + m1;
    
    
     unsigned char* buffer3 = new unsigned char*[16];
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 256;
   }
   Image u2(4,4, buffer3);
   
   Image o2 = u2 + m2;
   
    
        
   
}


