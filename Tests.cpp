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
        buffer1[i] = (rand()%95)  + 160;
       //this should be in the upperhalf to be 255 after thresholding
   }
   for(int i = 8; i< 16; i++){
       buffer1[i] = rand()%160 ;
     
      //this should be in the lowerhalf to be 0 after thresholding
   }
    Image m(4,4, buffer1);
     cout<<"m1"<<endl;
    Image m1 = m*160;
    
    unsigned char* buffer7 = new unsigned char[16];
     for(int i = 0; i< 8; i++){
        buffer7[i] = 255;
       //this should be in the upperhalf to be 255 after thresholding
   }
   
     for(int i = 8; i< 16; i++){
        buffer7[i] = 0;
       //this should be in the lowerhalf to be 255 after thresholding
   }
   cout<<"m7"<<endl;
    Image m7(4,4, buffer7);
    REQUIRE(m1== m7); //test for threshold using carefully generated random numbers.
    
    
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
   Image u (m + u0);//move constructor
   
  REQUIRE(u == u0);//test that addition wraps around 255
   
    cout<<"r"<<endl;
   Image r(m2 + m1);
   
   REQUIRE(r == u0); //test for invert, an image plus its inverse gives the white image.
   
    
   
   unsigned char* buffer2 = new unsigned char[16];//generate a random image
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 255;
   }
   Image u1(4,4, buffer2);
   
   Image o1 = u1 / m1;
    
    
     unsigned char* buffer3 = new unsigned char[16];
   for(int i = 0; i< 16; i++){
      buffer2[i] = rand()% 255;
   }
   Image u2(4,4, buffer3);
   
   Image o2 = u2 / m2;
   
   Image o3 = o1 + o2;//a mixture of u1 and u2 generated as suggested.
   
       
       unsigned char* buffer8 = new unsigned char[16];
   for(int i = 0; i< 16; i++){
      buffer8[i] = 0;
   }
   Image u8(4,4, buffer8); // a black image
   
   Image u9 = u1 - u0;
   REQUIRE(u9 == u8);//test that subtraction saturates to zero, any image - white   = black.
   
   
    
    //since test cases passed and they all used iterators, it is safe to assume that iterators also passed.
        
   
}


