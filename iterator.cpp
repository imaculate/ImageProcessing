#include "Image.h"



//copy constructor
MSHIMA001::Image::Iterator::Iterator(const Iterator& N){
   ptr = N.ptr;
         
}
         MSHIMA001::Image::Iterator::Iterator(unsigned char *p):ptr(p){
         }
        
         MSHIMA001::Image::Iterator::~Iterator(){
            ptr = nullptr;
         }
         //move constructor.
         MSHIMA001::Image::Iterator::Iterator(Iterator&& N){
            ptr = N.ptr;
            N = nullptr;
            
         }
          /*MSHIMA001::Image::Iterator&  MSHIMA001::Image::Iterator::operator=(int&& N ){
            *ptr = (unsigned char)N;
            return *this;
          }*/
      
         //assignment operator
      
         MSHIMA001::Image::Iterator&  MSHIMA001::Image::Iterator::operator=(const Iterator& N ){
               if(this!=&N){
                  ptr  = N.ptr;
               }
               return *this;
         }
         //move assignment operator.
         
         
      
         MSHIMA001::Image::Iterator&  MSHIMA001::Image::Iterator::operator=(Iterator&& N){
             if(this!=&N){
                  ptr  = N.ptr;
               }
               N = nullptr;
               return *this;
         }
         
         MSHIMA001::Image::Iterator&  MSHIMA001::Image::Iterator::operator+=(int n){
            ptr = ptr + n;
            return *this;
         }
         
         
         
         
         
         //++ operator
         const  MSHIMA001::Image::Iterator& MSHIMA001::Image::Iterator::operator++(){
            ++ptr;
            return *this;
         }
         //--Iterator
const MSHIMA001::Image::Iterator& MSHIMA001::Image::Iterator::operator--(){
            ptr--;
            return *this;
}
unsigned char& MSHIMA001::Image::Iterator::operator*(){
 return *ptr;}
 
 bool  MSHIMA001::Image::Iterator::operator!=( const Iterator& N){
   return (ptr != N.ptr);
 }