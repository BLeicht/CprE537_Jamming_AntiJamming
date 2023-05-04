#include <cstring>
#include <cstdint>

#ifndef PACKET_H
#define PACKET_H

struct packet {
	std::uint8_t nodeID;
	std::uint8_t packetNum;
	std::int8_t randomData[512];
	std::string md5Hash;
};

std::string HashPacket(struct packet * packet);

#endif
