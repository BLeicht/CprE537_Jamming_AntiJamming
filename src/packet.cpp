#include <iostream>
#include <cstring>
#include <cstdint>

#include "packet.hpp"
#include "md5.hpp"

std::string HashPacket(struct packet * packet) {
	std::string toVerify = std::to_string(packet->nodeID) + std::to_string(packet->packetNum);
	for (int8_t i : packet->randomData) {
		toVerify += std::to_string(i);
	}
	
	toVerify = md5(toVerify);	
	return toVerify;
}
