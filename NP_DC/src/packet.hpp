#include <cstring>
#include <cstdint>

#ifndef PACKET_H
#define PACKET_H

struct packet {
	std::uint8_t nodeID;
	std::uint8_t packetNum;
	std::int8_t randomData[512];
	std::string md5Hash;

	void PrintContents() {
		// the \"+\" unary operator is necessary to print out properly!
		// could also cast as unsigned, int, etc.
		std::cout << "nodeID: " << +nodeID << "\n";
		std::cout << "packetNum: " << +packetNum << "\n";
		std::cout << "randomData: " << randomData << "\n";
		std::cout << "md5Hash: " << md5Hash << "\n";
	}
};

std::string HashPacket(struct packet * packet);
#endif
