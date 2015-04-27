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
   cout<<"In copy constructor"<<endl;
    cout<<"allocating memory"<<endl;
 
   unsigned char* buffer =  new unsigned char[N.width*N.height];
         cout<<"allocating memory"<<endl;
        
         for(int j =0; j< height*width; j++){
            
            
              cout<< N.data.get()[j]<<endl;
              buffer[j] =  N.data.get()[j];
            
            
            
         
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
 
   ifstream file(fileName , ios::in |ios::binary);
   string line;
   
   if (file.is_open()) {
      getline (file,line);
      

      cout<<"reading header info"<<endl;
      while(line.compare("255")!=0){
         //cout<<line<<endl;
         if(!line.at(0) == '#'){
            cout<<line<<endl;

          
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
         
         cout<<"Done with header info"<<endl;
            file.read((char*)buffer, w*h);
         
         
          unique_ptr<unsigned char[]> data(buffer);
        
          
       file.close();
        
       return true;
        
      
       }else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return false;	
   }

               
   
      
              
  
   

      

 }
 void MSHIMA001::Image::save(std::string fileName ){
  cout<<"saving"<<endl;
   ofstream head(fileName, ios::out|ios::binary);
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
   
MSHIMA001::Image MSHIMA001::Image::operator+(const Image& N ){;
   cout<<"Adding"<<endl;
   Image temp(*this);//copy constructor
   cout<<"copy constructiong"<<endl;
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these arrs, dimensions don't match";
      return *this;
   }
   
     cout<<"iterators creating"<<endl;
   Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();
   cout<<"iterators created"<<endl;

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
   
