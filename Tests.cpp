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
      buffer1[i] = rand()%95  + 160; //this should be in the upperhalf to be 255 after thresholding
   }
   for(int i = 8; i< 16; i++){
      buffer1[i] = rand()%160 ; //this should be in the upperhalf to be 255 after thresholding
   }
    Image m(4,4, buffer1);
     cout<<"m1"<<endl;
    Image m1 = m*160;
    
    
     cout<<"m2"<<endl;
   Image m2 = !m1;// asssignment operator
   
    cout<<"m3"<<endl;
   Image m3 = !m2;

    REQUIRE( m3 == m1 );//test for invert, double invert returns the original one.
    
    
     unsigned char* buffer0 = new unsigned char[16];
   for(int i = 0; i< 16; i++){
      buffer0[i] = 255;
   }
   Image u0(4,4, buffer0); // a white image
   
   cout<<"u"<<endl;
   Image u = ( m + u0);//move constructor
   
   REQUIRE(u == u0);//test that addition wraps around
   
    cout<<"r"<<endl;
   Image r((m2 + m1)*200);
   
   REQUIRE(r == u0); //test for threshold, an image plus its inverse gives the white image.
   
    
   
   unsigned char* buffer2 = new unsigned char[16];
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 256;
   }
   Image u1(4,4, buffer2);
   
   Image o1 = u1 + m1;
    
    
     unsigned char* buffer3 = new unsigned char[16];
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 256;
   }
   Image u2(4,4, buffer3);
   
   Image o2 = u2 + m2;
   
    
        
   
}


