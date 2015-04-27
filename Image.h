#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <string>
#include "Matrix.h"
using namespace std;


namespace MSHIMA001{
class Image{
   private:
   
      int width, height;
      unique_ptr<unsigned char[]> data;
      
   
   public:
   
      Image(int w, int h); // default constructor - define in .cpp
      Image( string fileName);
      ~Image(); // destructor - define in .cpp file
   
   //copy constructor
      Image(const Image& N);
   
   //move constructor
      Image(Image&& N); 
   
   //assignment operator
   
      Image& operator=(const Image& N );
   //move assignment operator.
   
      Image& operator=(Image&& N);
   
   //method to read input files
   Image operator!();
      bool  load(std::string fileName);
      void save(std::string fileName );
      
      class Iterator{
      private:
         unsigned char *ptr;
         
      // grant private access to Image class functions
         friend class Image;
      // construct only via Image class (begin/end)
      
         Iterator(unsigned char *p);
      
      public:
       //copy construct is public
         Iterator(const Iterator& N);
    
         // define overloaded ops: *, ++, --, =
         //destructor
         ~Iterator();
         //move constructor
         Iterator(Iterator&& N); 
      
         //assignment operator
      
         Iterator& operator=(const Iterator& N );
         //move assignment operator.
      
         Iterator& operator=(Iterator&& N);
         
         
         
         //++ operator
         const Iterator& operator ++();
         const Iterator& operator --();
          unsigned char& operator *();
         bool operator !=( const Iterator& N);
         Iterator&  operator+=(int n);
        //Iterator&  operator=(int&& N );
         
          
      
          
      // other methods for Iterator
      };
      

   
      Image::Iterator begin(void) const; // etc
      Image::Iterator end(void) const;
   
      Image operator+(const Image& N );
      Image operator-(const Image& N );
      Image operator/(const Image& N );
      Image operator*(int f );
      Image operator%(MSHIMA001::Matrix g );
      /*ofstream& operator<<(const Image& N );
      ofstream& operator>>(const Image& N );*/
   
   
   
   
   
    
   
   
   
         
     
     };
     
     }
#endif