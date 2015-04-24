#ifndef HUFFNMANODE_H
#define HUFFNMANODE_H
#include <memory>
class Image
{
 private:
   int width, height;
   std::unique_ptr<unsigned char[]> data;
   
 public:
 
   Image(); // default constructor - define in .cpp
   Image(int width int height string filename);
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
  unsigned char**  readImages(std::string baseName);
  
   iterator begin(void); // etc
   iterator end(void);
   
    Image& operator+(const Image& N );
    Image& operator-(const Image& N );
    Image& operator/(const Image& N );
    Image& operator*(const Image& N );
    ofstream& operator<<(const Image& N );
    ofstream& operator>>(const Image& N );





    

   
   
   class iterator
   {
   private:
      unsigned char *ptr;
      // grant private access to Image class functions
      friend class Image;
    // construct only via Image class (begin/end)
 
       iterator(u_char *p) : ptr(p) {}

    public:
       //copy construct is public
         iterator( const iterator & rhs) : ptr(rhs.ptr) {}
         // define overloaded ops: *, ++, --, =
         iterator & operator=(const iterator & rhs)
          {...}
 // other methods for iterator
      };
 
     };
     
#endif