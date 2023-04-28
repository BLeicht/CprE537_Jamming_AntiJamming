#include <iostream>

#include "md5.h"

int main(int argc, char *argv[]) {
	std::cout << "md5 of \"grape\": " << md5("grape") << std::endl;
	return 0;

}
