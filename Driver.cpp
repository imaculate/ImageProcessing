#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Image.h"
#include "iterator.h"



using namespace std;
using namespace MSHIMA001;
//method used to extract initial string.


int main(int argc, char**  argv) {
  
   
    if(argc<3){
      //error handling.
		   cout<<"Enter correct format of commands"<<endl;
         cout<<"imageops -a l1 l2"<<endl;
         cout<<"imageops -s l1 l2"<<endl;
         cout<<"imageops -i l1"<<endl;
         cout<<"imageops -l l1 l2"<<endl;
         cout<<"imageops -t l1 f"<<endl;
         return 0;
	}else if(argc == 3){
      
      if(string(argv[1]).compare("-i")==0){
         string str = string(argv[1]) ;
         Image i(str);
         Image b=!i;
         
         b.save( "result.pgm");
         return 1;
      }else{
         cout<<"Enter correct format of commands"<<endl;
         cout<<"imageops -a l1 l2"<<endl;
         cout<<"imageops -s l1 l2"<<endl;
         cout<<"imageops -i l1"<<endl;
         cout<<"imageops -l l1 l2"<<endl;
         cout<<"imageops -t l1 f"<<endl;
         return 0;
      }
      
   }else{
       if(string(argv[1]).compare("-a")==0){
         string stra= string(argv[1]);
         string strb = string(argv[2]);
         Image a(stra);
         Image b(strb);
         Image sum = a + b;
         
         b.save("result.pgm");
         return 1;
      }else if(string(argv[1]).compare("-s")==0){
         string stra= string(argv[1]);
         string strb = string(argv[2]);
         Image a(stra);
         Image b(strb);
         Image diff = a - b;
         
         diff.save("result.pgm");
         return 1;
      }else if(string(argv[1]).compare("-l")==0){
         string stra= string(argv[1]);
         string strb = string(argv[2]);
         Image a(stra);
         Image b(strb);
         Image mask = a / b;
         
         mask.save("result.pgm");
         return 1;
      } else if(string(argv[1]).compare("-t")==0){
         string stra= string(argv[1]);
         
         int f ;
         std::stringstream str(argv[2]); 
          
         str >> f;
         Image a(stra);
         
         Image t = a*f;
         
         t.save("result.pgm");
         return 1;
      }
      else{
         cout<<"Enter correct format of commands"<<endl;
         cout<<"imageops -a l1 l2"<<endl;
         cout<<"imageops -s l1 l2"<<endl;
         cout<<"imageops -i l1"<<endl;
         cout<<"imageops -l l1 l2"<<endl;
         cout<<"imageops -t l1 f"<<endl;
         return 0;
      }
      
   }
   
  
  
   
     
}  
  