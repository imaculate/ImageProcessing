#include "Image.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



using namespace std;
using namespace MSHIMA001;

MSHIMA001::Image::Image(){
   width =height = 0;
   data = nullptr;
}

      
      

MSHIMA001::Image::Image( string fileName){
      load(fileName);
      
      
}


MSHIMA001::Image::~Image(){ // destructor

      for(int m = 0; m< height; m++){
         
         delete[] data.get()[m];
      }
      
      delete[] data.get();
      data = nullptr;
      
      
      
   

   
   
}
   
   //copy constructor
MSHIMA001::Image::Image(const Image& N):width(N.width), height(N.height){
   
 
   unsigned char** buffer =  new unsigned char*[height];
         
         unsigned char* row;
         for(int j =0; j< height; j++){
            row = new unsigned char[width];
            for(int k = 0; k< width; k++){
              row[k] =  N.data.get()[j][k];
            }
            buffer[j]= row;
            
         
         }
          

   
      data = unique_ptr<buffer>;

}
   
   //move constructor
MSHIMA001::Image::Image(Image&& N): width(N.width), height(N.height){




   data = unique_ptr<N.data.get()>;
   
     
      
   N.height = N.width = 0;
   N.data = nullptr;
   
}
   
   //assignment operator
   
MSHIMA001::Image::Image& MSHIMA001::Image::operator=(const Image& N ){
   if(this == &N)
      return *this;
      
 
   
   if(data != null){
      for(int m = 0; m< height; m++){
         
         delete[] data.get()[m];
      }
      
      delete[] data.get();
}
   
        
   width = N.width;
   height  = N.height;
    unsigned char** buffer =  new unsigned char*[height];
         
         unsigned char* row;
         for(int j =0; j< height; j++){
            row = new unsigned char[width];
            for(int k = 0; k< width; k++){
              row[k] =  N.data.get()[j][k];
            }
              
            buffer[j]= row;
            
         
         }
     

   
      data = unique_ptr<buffer>;


   
   return *this;
      
}
   //move assignment operator.
MSHIMA001::Image::Image& MSHIMA001::Image::operator=(Image&& N){
   if(this == &N)
      return *this;
      
   
   if(data != null){
      for(int m = 0; m< height; m++){
         
         delete[] data.get()[m];
      }
      
      delete[] data.get();
}

      
   width = N.width;
   height  = N.height;
   data = unique_ptr<N.data.get()>;
   
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
            
            this.width = w;
            this.height = h;
            
         
         }
      getline(file ,line);
      //cout<<"height "<<height<<"width "<< width<<endl;
     }
      
     unsigned char** buffer =  new unsigned char*[h];
         
         unsigned char* row;
         for(int j =0; j< height; j++){
            row = new unsigned char[w];
            file.read((char*)row, w);
            buffer[j]= row;
            
         
         }
         
         this.data = unique_ptr<buffer>;
        
          
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
      
       for(int j=0; j< height; j++){
         char* byte = (char*)data[j];
         head.write(byte,width);
      }
    
      head.close();
   }else{
      cout<<"Unable to open file"<<header<<endl;
   }


     
   
 }
   
Image::Iterator& MSHIMA001::Image::begin(void){ // etc
   return  Iterator(&(data.get()[0][0]));

      
   
}
Image::Iterator& MSHIMA001::Image::end(void){
   return Iterator(&(data.get()[width-1][height-1]));
}
   
MSHIMA001::Image& MSHIMA001::Image::operator+(const Image& N ){
   Image temp(*this);//copy constructor
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these images, dimensions don't match";
      return *this;
   }
   
   
   Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();

 while ( beg != end) { 
      int check = *beg + *inStart;
         if(check> 255){
            check = 255;
         }
         *beg = (unsigned char)check;

   
  } 

   
   
   return temp;
      
      
   
}
/*MSHIMA001::Image& MSHIMA001::Image::operator-(const Image& N ){
   Image temp(*this);
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these images, dimensions don't match";
      return *this;
   }
   
   /* 
   Image::Iterator beg = temp.begin(), end = temp.end();
   Image::Iterator inStart = N.begin(), inEnd = N.end();

 while ( beg != end) { 
      int check = *beg + *inStart;
         if(check> 255){
            check = 255;
         }
         *beg = check;

   
  } 

   
   
   return temp;

   for(int i = 0; i< height ; i++){
      for(int j =0; j< width; j++){
         int check = temp.data[i][j] -B.data[i][j];
         if(check<0){
            check = 0;
         }
         temp.data[i][j] = check;
         
      }
   }
   
   return temp;
      



}
MSHIMA001::Image& MSHIMA001::Image::operator/(const Image& N ){
    Image temp(*this);
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these images, dimensions don't match";
      return *this;
   }
   
   for(int i = 0; i< height ; i++){
      for(int j =0; j< width; j++){
         bool check = (N.data[i][j]==255);
         if(!check){
            temp.data[i][j] = 0;
         }
       
         
      }
   }
   
   return temp;
}
MSHIMA001::Image& MSHIMA001::Image::operator!(){
   Image temp(this.width, this.height);
   for(int i = 0; i< height ; i++){
      for(int j =0; j< width; j++){
         bool check = (N.data[i][j]==255);
         if(!check){
         
            temp.data[i][j] = 255 - this.data[i][j];
         }
       
         
      }
   }
   
}
//threshold
MSHIMA001::Image& MSHIMA001::Image::operator*(int f ){
   Image temp(this.width, this.height);
   for(int i = 0; i< height ; i++){
      for(int j =0; j< width; j++){
         bool check = (data[i][j]>f);
         if(check){
         
            temp.data[i][j] = 255 ;
         }else{
            
            temp.data[i][j] = 0 ;

         }
       
         
      }
   }


   
}
ofstream& operator<<(const Image& N ){
}
ofstream& operator>>(const Image& N ){
}*/
   
