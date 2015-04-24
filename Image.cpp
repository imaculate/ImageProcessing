class Image
{
 private:
   int width, height;
   std::unique_ptr<unsigned char[]> data;
   
   
 public:
 
   bool MSHIMA001::VolImage::readImages(std::string baseName){
   int  number;
   string headerName = baseName + ".data";
   ifstream header(headerName.c_str() , ios::binary);
   string line;
   
   if (header.is_open()) {
      getline (header,line);
      istringstream iss(line);
     	
      iss >> width;
      iss >> height;
      iss >> number;
      
      //cout<<"height "<<height<<"width "<< width<<endl;
      header.close();
   }
   else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return false;	
   }
   unsigned char** buffer;
   for(int i = 0; i< number; i++){
      //CONVERT i TO A STRING.
      stringstream ss;
      ss << i;
      string str = ss.str();
      string fileName = baseName + str +".raw";
      
      ifstream pic(fileName.c_str(),  ios::binary);
      
      
      
     
     
      if (pic.is_open()) {
         
         
         buffer = new unsigned char*[height];
         
         unsigned char* row;
         for(int j =0; j< height; j++){
            row = new unsigned char[width];
            pic.read((char*)row, width);
            buffer[j]= row;
            
         
         }
        
          
         slices.push_back(buffer);
        
       
         pic.close();
      
      }
               
   
      
              
   }
   return true;
   

      
}

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
 // define begin()/end() to get iterator to start and
 // "one-past" end.
      iterator begin(void) { return iterator(data.get())} // etc
};