#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>
#include "Image.h"




using namespace std;
using namespace MSHIMA001;
//method used to extract initial string.


int main(int argc, char**  argv) {
   if(argc <3){
      cout<<"You should have at least 2 parameters, enter the name of of headerfile"<<endl;
      return 0;
   }
  
  
   string readfile  = string(argv[1])+ ".txt";
   unordered_map<char, int> Map ; 
   string input = getFreq(readfile, Map);
   
  
   
  
   //create map for th character to codes.
   HuffmanTree tree;
   tree.buildTree(Map);
     
   unordered_map<char, string> map;
   
  
   
   const HuffmanNode& T = *(tree.root);
   
   tree.getCodes(T, "",map );
   
   //output table to outputfile.hdr;
   string headerfile = string(argv[2]) + ".hdr" ;
	//cout<<"header "<<headerfile<<endl;
   ofstream header(headerfile, ios::out);
   cout<<map.size()<<endl;
   header<<map.size()<<"\n";
   for( auto i = map.begin(); i != map.end(); ++i){
      cout<<(i->first)<<" "<<(i->second)<<endl;
      header<<(i->first)<<" "<<(i->second)<<"\n";
   }
   
   header.close();
   
   string output = compress(input, map);
   int  N = output.size();
   int nbytes = (N/8) + (N%8 ? 1 : 0); 
   cout<<"nbytes "<<nbytes<<endl;

      
        //create bitstream
   
   bitPack(output, argv[1]);
     
}  //create a method to extract file. 
  