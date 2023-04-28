#include <iosteam>
using namespace std;

class Packet {
	public:
		int uniqueID; // 8 bytes ?
		
		// originally 32 bytes. now 2 bytes. 
		short int packetNum;
		
		char randData[512]; // 512 bytes ?
		


		int verifHash; // 16 bytes ?
}
