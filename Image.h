#ifndef IMAGE_H
#define IMAGE_H
#include <memory>
#include <iostream>
#include <string>
using namespace std;
class iterator;
namespace MSHIMA001{
   class Image
   {
   private:
   
      int width, height;
      unique_ptr<unsigned char[]> data;
      friend class iterator;
   
   public:
   
      Image(); // default constructor - define in .cpp
      Image(int w, int h, string fileName);
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
   Image& operator!();
      bool  load(std::string fileName);
      void save(std::string fileName );
   
      Image::iterator begin(void); // etc
      Image::iterator end(void);
   
      Image& operator+(const Image& N );
      Image& operator-(const Image& N );
      Image& operator/(const Image& N );
      Image& operator*(int f );
      ofstream& operator<<(const Image& N );
      ofstream& operator>>(const Image& N );
   
   
   
   
   
    
   
   
   
      class iterator;
         
     
     }
     
#endif