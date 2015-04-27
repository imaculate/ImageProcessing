#include "Image.h"
#include "Matrix.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



using namespace std;
using namespace MSHIMA001;


MSHIMA001::Image::Image(int w, int h):width(w), height(h){
   
   unsigned char b[w*h];
   
   data.reset(b);
}


      
      

MSHIMA001::Image::Image( string fileName){
   load(fileName);
   
      
      
}


MSHIMA001::Image::~Image(){ // destructor

      
      
      
   data = nullptr;
   height = width = 0;
      
      
   

   
   
}
   
   //copy constructor
MSHIMA001::Image::Image(const Image& N):width(N.width), height(N.height){
   cout<<"In copy constructor"<<endl;
   cout<<"allocating memory"<<endl;
 
   unsigned char buffer[N.width*N.height];
   cout<<"allocating memory"<<endl;
   
        
   for(int j =0; j< height*width; j++){
      
            
     
      buffer[j] =  N.data[j];
            
            
            
         
   }
          
   cout<<" done allocating memory"<<endl;
   
   data.reset(buffer);

}
   
   //move constructor
MSHIMA001::Image::Image(Image&& N): width(N.width), height(N.height){




   data.reset(N.data.get());
   
     
      
   N.height = N.width = 0;
   N.data = nullptr;
   
}
   
   //assignment operator
   
MSHIMA001::Image& MSHIMA001::Image::operator=(const Image& N ){
   if(this == &N)
      return *this;
      
 
   
   if(data != nullptr){
     
      data = nullptr;
      
   }
   
        
   width = N.width;
   height  = N.height;
   unsigned char buffer[width*height];
         
   for(int j =0; j< height*width; j++){
            
          
      buffer[j] =  N.data.get()[j];
            
            
            
         
   }
          
     

   
   data.reset(buffer);


   
   return *this;
      
}
   //move assignment operator.
MSHIMA001::Image& MSHIMA001::Image::operator=(Image&& N){
   if(this == &N)
      return *this;
      
   
   if(data != nullptr){
     
      data = nullptr;
   }

      
   width = N.width;
   height  = N.height;
    data.reset(N.data.get());
   
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
        
         if(line.at(0)!='#'){
         
            
            if(line.compare("P5")!=0){
               cout<<line<<endl;
               istringstream iss(line);
            
               iss >> h;
               iss >> w;
            
               width = w;
               height =  h;
            }
            
         }
         getline(file ,line);
         
         cout<<line<<endl;
      }
      
      cout<<"height "<<height<<"width "<< width<<endl;
      int64_t l = h*w;
      cout<<l<<endl;
        
      data.reset(new unsigned char[width*height]);
  //    unsigned char buffer[l];
   
     skipws(file);
         
      cout<<"Done with header info"<<endl;
      file.read((char*)&data[0], w*h);
        if (file)
      std::cout << "all characters read successfully."<<file.gcount()<<endl;
    else
      std::cout << "error: only " << file.gcount() << " could be read"<<endl;
         
         
       
         
    //   data.reset(buffer);
      
     
        
          
      file.close();
        
      return true;
        
      
   }
   else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return false;	
   }

               
   
      
              
  
   

      

}
void MSHIMA001::Image::save(std::string fileName ){
   cout<<"saving"<<endl;
   ofstream head(fileName, ios::out|ios::binary);
   if(head){
      head<<"P5"<<endl;
      head<<"# this is result image saved!"<<endl;
      head<< height<< " "<< width<< endl;
      head<<"255"<<endl;
    
      
       
      unsigned char byte;// = data.get();
      for(auto i=this->begin();i!=end();++i){
         //cout<<int(*i)<<" ";
         byte  = *i;
         head.write((char*)&byte,1);
      }
      
      
    
      head.close();
   }
   else{
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
  
   cout<<"copy constructiong"<<endl;
   if(N.height != height || N.width != width ){
      cerr<< "Can't add these arrs, dimensions don't match"<<endl;
      return *this;
   }
    Image temp(*this);//copy constructor
   
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
   
   ++beg;
   ++inStart;
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
      ++beg;
      ++inStart;
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
       
         
   
       
   ++beg;
   ++inStart;
   
   } 

   return temp;
}
MSHIMA001::Image MSHIMA001::Image::operator!(){
   Image temp(*this);
  
   cout<<"Inverting"<<endl;
   Image::Iterator beg = temp.begin(), end = temp.end();
  

   while ( beg != end) { 
   
            // cout<<*beg<<endl;
      
      *beg = 255 - *beg;
   
     
       ++beg;
   
   
   } 

   return temp;

 
   
}
//threshold
MSHIMA001::Image MSHIMA001::Image::operator*(int f ){

   Image temp(*this);
   Image::Iterator beg = temp.begin(), end = temp.end();
   while ( beg != end) { 
         
      bool check = (*beg>f);
      if(check){
         
         *beg = 255 ;
      }
      else{
            
         *beg = 0 ;
      
      }
      
      ++beg;
   
   } 

   return temp;
  
}

MSHIMA001::Image MSHIMA001::Image::operator%(MSHIMA001::Matrix g ){

   /*Image temp(*this);
   int it = (g.N)/2;
   Image::Iterator beg = temp.begin(), end = temp.end();
   while ( beg != end) {
      //dosomething. 
         double acc = 0; //accumulator.
         acc+= *beg * g.vec[N/2];
         //int index = beg - 
         
         for(int i = 1; i< it; i++){
            
            
            /*bool check = (beg>f);
      if(check){
         
         *beg = 255 ;
      }
      else{
            
         *beg = 0 ;
      
      }

            
         } 
         
            
      ++beg;
   
   } 

   return temp;*/
  
}
/*ofstream& operator<<(const Image& N ){
}
ofstream& operator>>(const Image& N ){
}*/
   
