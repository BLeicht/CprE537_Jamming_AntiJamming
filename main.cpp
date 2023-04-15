#include <iostream>

#include "hlib/hashlibpp.h"

int main() {
	hashwrapper *myWrapper = new md5wrapper();

	try {
		myWrapper -> test();
	} 
	catch(hlException &e) {
		//lit
	}

	try {
		std::cout << myWrapper->getHashFromString("Hello world") << std::endl;
	        std::cout << myWrapper->getHashFromFile("/etc/motd") << std::endl;	
	} 
	catch(hlException &e) {
		//lit
	}	


	delete myWrapper;
	myWrapper = NULL;
}
