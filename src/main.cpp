#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdint>

#include "packet.hpp"

int main() {
	struct packet * packet = new struct packet;
	
	packet->nodeID = 1;
	packet->packetNum = 1;
	memset(packet->randomData, 2, sizeof(packet->randomData));
	packet->md5Hash = HashPacket(packet);

	packet->PrintContents();
	

	return 0;
}
