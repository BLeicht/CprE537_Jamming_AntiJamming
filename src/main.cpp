#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdint>

#include "packet.hpp"

int main(int argc, char *argv[]) {
	struct packet * packet = new struct packet;
	
	packet->nodeID = 1;
	packet->packetNum = 1;
	memset(packet->randomData, 2, sizeof(packet->randomData));
	packet->md5Hash = HashPacket(packet);



	// the \"+\" unary operator is necessary to print out properly!
	// could also cast as unsigned, int, etc.
	std::cout << "nodeID: " << +packet->nodeID << "\n";
	std::cout << "packetNum: " << +packet->packetNum << "\n";

	std::cout << "randomData: " << packet->randomData << "\n";
	std::cout << "md5Hash: " << packet->md5Hash << "\n";


	return 0;
}
