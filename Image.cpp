#include "Image.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



using namespace std;
using namespace MSHIMA001;


MSHIMA001::Image::Image(int w, int h):width(w), height(h){
  
   
      unique_ptr<unsigned char[]> data(new unsigned char[w*h]);
}


      
      

MSHIMA001::Image::Image( string fileName){
      load(fileName);
      
      
}


MSHIMA001::Image::~Image(){ // destructor

      
      
      delete[] data.get();
      data = nullptr;
      
      
      
   

   
   
}
   
   //copy constructor
MSHIMA001::Image::Image(const Image& N):width(N.width), height(N.height){
   
 
   unsigned char* buffer =  new unsigned char[width*height];
         
        
         for(int j =0; j< height; j++){
            
            for(int k = 0; k< width; k++){
              buffer[(j*height)+k] =  N.data.get()[(j*height)+k];
            }
            
            
         
         }
          

   
       unique_ptr<unsigned char[]> data(buffer);

}
   
   //move constructor
MSHIMA001::Image::Image(Image&& N): width(N.width), height(N.height){




   unique_ptr<unsigned char[]> data(N.data.get());
   
     
      
   N.height = N.width = 0;
   N.data = nullptr;
   
}
   
   //assignment operator
   
MSHIMA001::Image& MSHIMA001::Image::operator=(const Image& N ){
   if(this == &N)
      return *this;
      
 
   
   if(data != nullptr){
     
      delete[] data.get();
}
   
        
   width = N.width;
   height  = N.height;
    unsigned char* buffer =  new unsigned char[width*height];
         
         for(int j =0; j< height*width; j++){
            
          
              buffer[j] =  N.data.get()[j];
            
            
            
         
         }
          
     

   
      unique_ptr<unsigned char[]> data(buffer);


   
   return *this;
      
}
   //move assignment operator.
MSHIMA001::Image& MSHIMA001::Image::operator=(Image&& N){
   if(this == &N)
      return *this;
      
   
   if(data != nullptr){
     
      
      delete[] data.get();
}

      
   width = N.width;
   height  = N.height;
   unique_ptr<unsigned char[]> data(N.data.get());
   
   N.data = nullptr;
   N.height = N.width = 0;
   
   return *this;
}
   
   //method to read input files
bool  MSHIMA001::Image::load(std::string fileName){

   int  w, h;
 
   ifstream file(fileName , ios::binary);
   string line;
   
   if (file.is_open()) {
      getline (file,line);
      while(line!= "255"){
         if(line.at(0) == '#'){
            continue;
         }else{
      
            istringstream iss(line);
     	
            iss >> w;
            iss >> h;
            
            width = w;
            height = h;
            
         
         }
      getline(file ,line);
      //cout<<"height "<<height<<"width "<< width<<endl;
     }
      
     unsigned char* buffer =  new unsigned char[h*w];
         
         
            file.read((char*)buffer, w*h);
         
         
          unique_ptr<unsigned char[]> data(buffer);
        
          
       file.close();
        
       return true;
        
      
       }
   else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return false;	
   }

               
   
      
              
  
   

      

 }
 void MSHIMA001::Image::save(std::string fileName ){
  
   ofstream head(fileName, ios::binary);
   if(head.is_open()){
      head<<"P5"<<endl;
      head<< width<< " "<< height<< endl;
      head<<"255"<<endl;
      
       
        unsigned char* byte = data.get();
         head.write((char*)byte,width*height);
      
    
      head.close();
   }else{
      cout<<"Unable to open file"<<endl;
   }


     
   
 }
   
MSHIMA001::Image::Iterator MSHIMA001::Image::begin(void) const{ // etc
   return  Iterator(&(data.get()[0]));

       
   
}
MSHIMA001::Image::Iterator MSHIMA001::Image::end(void) const{
   return Iterator(&(data.get()[width*height]));
}
   
MSHIMA001::Image MSHIMA001::Image::operator+(const Image& N ){
   Image temp(*this);//copy constructor
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these arrs, dimensions don't match";
      return *this;
   }
   
   
   Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();

 while ( beg != end) { 
   
      int check = (*beg + *inStart);
         if(check> 255){
            check = 255;
         }
         

        *beg = check; 

   
  } 

   
   
   return temp;
      
      
   
}
MSHIMA001::Image MSHIMA001::Image::operator-(const Image& N ){
   Image temp(*this);
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these arrs, dimensions don't match";
      return *this;
   }
   
  Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();

 while ( beg != end) { 
   
      int check = (*beg - *inStart);
         if(check < 0){
            check = 0;
         }
         

        *beg = check; 

   
  } 

   
   
   return temp;

}
MSHIMA001::Image MSHIMA001::Image::operator/(const Image& N ){
    Image temp(*this);
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these arrs, dimensions don't match";
      return *this;
   }
   
   
   Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();

 while ( beg != end) { 
   
      bool check = (*inStart==255);
         if(!check){
            *beg = 0;
         }
       
         

       

   
  } 

   return temp;
}
MSHIMA001::Image MSHIMA001::Image::operator!(){
  Image temp(width, height);
  

   Image::Iterator beg = temp.begin(), end = temp.end();
  

 while ( beg != end) { 
   
             
         
   *beg = 255 - *beg;

       

   
  } 

   return temp;

 
   
}
//threshold
MSHIMA001::Image MSHIMA001::Image::operator*(int f ){

Image temp(width, height);
   Image::Iterator beg = temp.begin(), end = temp.end();
 while ( beg != end) { 
         
    bool check = (*beg>f);
         if(check){
         
            *beg = 255 ;
         }else{
            
            *beg = 0 ;

         }
  
  } 

   return temp;
  
}
/*ofstream& operator<<(const Image& N ){
}
ofstream& operator>>(const Image& N ){
}*/
   
