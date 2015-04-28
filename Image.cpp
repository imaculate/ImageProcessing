#include "Image.h"
#include "Matrix.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>



using namespace std;
namespace MSHIMA001{


Image::Image(int w, int h, unsigned char* buffer):width(w), height(h){
   
  
   
   data.reset(buffer);
 
   
}


      
      

Image::Image( string fileName){
   load(fileName);
   
      
      
}


Image::~Image(){ // destructor

      
      
      
   data = nullptr;
   height = width = 0;
      
      
   

   
   
}
   
   //copy constructor
Image::Image(const Image& N):width(N.width), height(N.height){
   cout<<"In copy constructor"<<endl;
   cout<<"allocating memory"<<endl;
 
   unsigned char* buffer  = new unsigned char[N.width*N.height];
  
   
        
   for(int j =0; j< height*width; j++){
      
            
     
      buffer[j] =  N.data[j];
            
            
            
         
   }
          
   cout<<" done allocating memory"<<endl;
   
   data.reset(buffer);

}
   
   //move constructor
Image::Image(Image&& N): width(N.width), height(N.height){
cout<<"In move "<<endl;



   
   unsigned char* buffer  = new unsigned char[N.width*N.height];
   for(int j =0; j< height*width; j++){
      
            
     
      buffer[j] =  N.data[j];
            
            
            
         
   }
          
  
   
   data.reset(buffer);

      
   N.height = N.width = 0;
   N.data = nullptr;
   
}
   
   //assignment operator
   
Image& Image::operator=(const Image& N ){
   if(this == &N)
      return *this;
      
 
   
   if(data != nullptr){
     
      data = nullptr;
      
   }
   
        
   width = N.width;
   height  = N.height;
   unsigned char* buffer = new unsigned char[width*height];
         
   for(int j =0; j< height*width; j++){
            
          
      buffer[j] =  N.data[j];
            
            
            
         
   }
          
     

   
   data.reset(buffer);


   
   return *this;
      
}
   //move assignment operator.
Image& Image::operator=(Image&& N){
cout<<"in move op"<<endl;
   if(this == &N)
      return *this;
      
   
   if(data != nullptr){
     
      data = nullptr;
   }

      
   width = N.width;
   height  = N.height;
    unsigned char* buffer = new unsigned char[width*height];
         
   for(int j =0; j< height*width; j++){
            
          
      buffer[j] =  N.data[j];
            
            
            
         
   }
          
     

   
   data.reset(buffer);
   
   N.data = nullptr;
   N.height = N.width = 0;
   
   return *this;
}
   
   //method to read input files
bool  Image::load(std::string fileName){

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
void Image::save(std::string fileName ){
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
   
Image::Iterator Image::begin(void) const{ // etc
   return  Iterator(&(data.get()[0]));

       
   
}
Image::Iterator Image::end(void) const{
   return Iterator(&(data.get()[width*height]));
}
   
Image Image::operator+(const Image& N ){;
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
Image Image::operator-(const Image& N ){
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
Image Image::operator/(const Image& N ){
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
Image Image::operator!(){
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
Image Image::operator*(int f ){

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

Image Image::operator%(Matrix g ){

   /*Image temp(*this);
   int it = (g.N)/2;
   Image::Iterator beg = temp.begin(), end = temp.end();
   while ( beg != end) {
      //dosomething. 
         double acc = 0; //accumulator.
         acc+= *beg * g.vec[N/2];
         //int index = beg - 
         
         for(int i = 1; i< it; i++){
            
            
            bool check = (beg>f);
         if(check){
         
            acc += (*beg + index )g.vec[index]
         }else{
            
            *beg = 0 ;
      
         }

            
         } 
         
            
      ++beg;
   
   } 

   return temp;*/
  
}
ostream& operator<<(ostream& head, const Image& N ){


   if(head){
      head<<"P5"<<endl;
      head<<"# this is result image saved!"<<endl;
      head<< N.height<< " "<< N.width<< endl;
      head<<"255"<<endl;
    
      
       
      unsigned char byte;// = data.get();
      for(auto i=N.begin();i!=N.end();++i){
         //cout<<int(*i)<<" ";
         byte  = *i;
         head.write((char*)&byte,1);
      }
      
      
    
     
      return head;
   }
   else{
      cout<<"Unable to open file"<<endl;
   }



   
   
   
}
istream& operator>>( istream& file,  Image& N ){
    string line;
    int h,w;
   
   if (file) {
      getline (file,line);
      
   
      cout<<"reading header info"<<endl;
      while(line.compare("255")!=0){
        
         if(line.at(0)!='#'){
         
            
            if(line.compare("P5")!=0){
               cout<<line<<endl;
               istringstream iss(line);
            
               iss >> h;
               iss >> w;
            
               N.width = w;
               N.height =  h;
            }
            
         }
         getline(file ,line);
         
         cout<<line<<endl;
      }
      
      cout<<"height "<<N.height<<"width "<< N.width<<endl;
      int64_t l = h*w;
      cout<<l<<endl;
        
      N.data.reset(new unsigned char[N.width*N.height]);
  //    unsigned char buffer[l];
   
     skipws(file);
         
      cout<<"Done with header info"<<endl;
      file.read((char*)(&(N.data[0])), w*h);
        if (file)
      std::cout << "all characters read successfully."<<file.gcount()<<endl;
    else
      std::cout << "error: only " << file.gcount() << " could be read"<<endl;
         
         
       
         
    //   data.reset(buffer);
      
     
        
          
    
        
      return file;
        
      
   }
   else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return file;	
   }

               
   
      
              
  
   

   
}

bool MSHIMA001::Image::operator==(const Image& N) {
   if(sizeof(N.data.get())!= sizeof(data.get()))
      return false;
      
   for(int i = 0; i< sizeof(data.get()); i++){
      if(data[i]!= N.data[i])
         return false;
      
   }
   return true;
}
   
}