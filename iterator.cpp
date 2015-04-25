#include "iterator.h"
#include "Image.h"
MSHIMA001::Image::iterator( const iterator & rhs){
   ptr = rhs.ptr;
         
}
         MSHIMA001::Image::iterator(u_char *p):ptr(p){
         }
         // define overloaded ops: *, ++, --, =
         iterator& MSHIMA001::Image::iterator operator=(const iterator & rhs){
            ptr = rhs.ptr;
         
            return *this;
         }
         MSHIMA001::Image::~iterator(){
            ptr = nullptr;
         }
         //move constructor.
         MSHIMA001::Image::iterator(iterator&& N){
            ptr = N.ptr;
            N = nullptr;
            
         }
      
         //assignment operator
      
         iterator& MSHIMA001::Image::iterator operator=(const iterator& N ){
               if(this!=&N){
                  ptr  = N.ptr;
               }
               return *this;
         }
         //move assignment operator.
      
         iterator& MSHIMA001::Image::iterator operator=(iterator&& N){
             if(this!=&N){
                  ptr  = N.ptr;
               }
               N = nullptr;
               return *this;
         }
         
         
         
         //++ operator
         const iterator& MSHIMA001::Image::iterator operator ++(){
            ptr++;
            return *this;
         }
         //--iterator
         const MSHIMA001::Image::iterator& operator --(){
            ptr--;
            return *this;
         }
         const MSHIMA001::Image::iterator& operator *(){
            return ptr;
         }
         
          
      
          
      
