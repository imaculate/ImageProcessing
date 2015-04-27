#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Image.h"
#include "Matrix.h"



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
          cout<<"imageops -f l1 g"<<endl;
         return 1;
	}else if(argc == 3){
      
      if(string(argv[1]).compare("-i")==0){
         string str = string(argv[2]) ;
         Image i(str);
         Image b=!i;
         
         b.save( "invert-result.pgm");
         return 0;
      }else{
         cout<<"Enter correct format of commands"<<endl;
         cout<<"imageops -a l1 l2"<<endl;
         cout<<"imageops -s l1 l2"<<endl;
         cout<<"imageops -i l1"<<endl;
         cout<<"imageops -l l1 l2"<<endl;
         cout<<"imageops -t l1 f"<<endl;
          cout<<"imageops -f l1 g"<<endl;
         return 1;
      }
      
   }else {
       if(string(argv[1]).compare("-a")==0){
         string stra= string(argv[2]);
         string strb = string(argv[3]);
         cout<<"Creating first image"<<endl;
         Image a(stra);
         
         cout<<"Creating second image"<<endl;
         cout<<strb<<endl;
         Image b(strb);
         Image sum = a + b;
         cout<<"Done"<<endl;
         sum.save("add-result.pgm");
         return 0;
      }else if(string(argv[1]).compare("-s")==0){
         string stra= string(argv[2]);
         string strb = string(argv[3]);
         Image a(stra);
         Image b(strb);
         Image diff = a - b;
         
         diff.save("sub-result.pgm");
         return 0;
      }else if(string(argv[1]).compare("-l")==0){
         string stra= string(argv[2]);
         string strb = string(argv[3]);
         Image a(stra);
         Image b(strb);
         Image mask = a / b;
         
         mask.save("mask-result.pgm");
         return 0;
      } else if(string(argv[1]).compare("-t")==0){
         string stra= string(argv[2]);
         //threshold
         int f ;
         std::stringstream str(argv[3]); 
          
         str >> f;
         Image a(stra);
         
         Image t = a*f;
         
         t.save("theshold-result.pgm");
         return 0;
      }else if(string(argv[1]).compare("-f")==0){
         string stra= string(argv[2]);
         Image a(stra);
         //threshold
         int N;
         MSHIMA001::Matrix g;
          
         string strb=  string(argv[3]); 
         ifstream file(strb, ios::in);
         if(file.is_open()){
               
               file>>N;
               g.N = N;
               int n;
               for(int i = 0; i< N*N; i++){
                  file>>i;
                  g.vec.push_back(i);
                  
               }
               
         }else{
            cout<<"File does not exist"<<endl;
         }
          
         
         
         
         Image f = a%g;
         
         f.save("filter-result.pgm");
         return 0;
      }

      else{
         cout<<"Enter correct format of commands"<<endl;
         cout<<"imageops -a l1 l2"<<endl;
         cout<<"imageops -s l1 l2"<<endl;
         cout<<"imageops -i l1"<<endl;
         cout<<"imageops -l l1 l2"<<endl;
         cout<<"imageops -t l1 f"<<endl;
          cout<<"imageops -f l1 g"<<endl;
         return 1;
      }
      
   }
   
  
  
   
     
}  
  