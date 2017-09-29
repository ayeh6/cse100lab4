#include <sstream>
#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc,char **argv) {

  // Create an empty Binary Search Tree
  BST Tree;

  // Using a fixed size buffer for reading content is not always safe, 
  // but ok here because we know how our input has to be:
  char line[100];

  // Main loop
  while ( std::cin.getline(line,100) ) {
    string str(line);
    if ( str.size()==0 ) continue; 
    if ( str[0]=='e' ) return 0;

		// Use cerr if you want to always print to the console, because cout
		// will be redirected to the output file when calling the Grade05 script:
	  // cerr<<line<<endl;

    if ( str.substr(0,2)=="in" ) {
			Tree.Print(BST::InOrderTrav);
			cout << "++++++++++++++++++++" << endl;
		}
	  else {
			if ( str.substr(0,3)=="pre" ) {
				Tree.Print ( BST::PreOrderTrav );
				cout << "++++++++++++++++++++" << endl;
			}
	    else {
				if (str.substr(0,4) == "post") {
					Tree.Print(BST::PostOrderTrav);
					cout << "++++++++++++++++++++" << endl;
				}
		    else {
					int key;
				  stringstream convert_stm(str.substr(2, str.size()-1));
				  if ( !(convert_stm>>key) ) key = -1;

				  if (str.substr(0,1) == "i") Tree.Insert(key);
				  else if (str.substr(0,1) == "d") Tree.Delete(key);
			  }
			}
		}
  }
    
  return 0;
}

