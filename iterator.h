#ifndef ITERATOR_H
#define ITERATOR_H
#include "Image.h"
#include <string>
using namespace std;
class MSHIMA001::Image::iterator
      {
      private:
         unsigned char *ptr;
         
      // grant private access to Image class functions
         friend class Image;
      // construct only via Image class (begin/end)
      
         iterator(u_char *p);
      
      public:
       //copy construct is public
         iterator( const iterator & rhs);
         // define overloaded ops: *, ++, --, =
         iterator & operator=(const iterator & rhs);
         ~iterator();
         iterator(iterator&& N); 
      
         //assignment operator
      
         iterator& operator=(const iterator& N );
         //move assignment operator.
      
         iterator& operator=(iterator&& N);
         
         //move constructor
         iterator(iterator&& N); 
         
         //++ operator
         const iterator& operator ++();
         const iterator& operator --();
         const iterator& operator *();
         
          
      
          
      // other methods for iterator
      };
      
#endif