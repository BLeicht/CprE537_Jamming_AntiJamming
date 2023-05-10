#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "timex.h"
#include "ztimer.h"


#include "packet.hpp"
#include "shell.h"


#define CLIENT_MESSAGE "Hello Server"

static char server_buffer[128];


static int _begin_handler(int argc, char ** argv);
static int _server_handler(int argc, char ** argv);
static int _client_handler(int argc, char ** argv);

static const shell_command_t shell_commands[] = {
	{ "begin", "Begin test", _begin_handler },
	{ "server", "Start UDP server", _server_handler },
	{ "client", "Start up UDP client", _client_handler },
	{ NULL, NULL, NULL}
};

int main() {
	struct packet * packet = new struct packet;
	
	packet->nodeID = 1;
	packet->packetNum = 1;
	memset(packet->randomData, 2, sizeof(packet->randomData));
	packet->md5Hash = HashPacket(packet);

	char line_buf[SHELL_DEFAULT_BUFSIZE];
	shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

	puts("ay");

	return 0;
}

static int _begin_handler(int argc, char ** argv) {
	(void)argc;
	(void)argv;
	puts(argv[1]);
	puts("beginning\n");
	return 0;
}

static int _server_handler(int argc, char ** argv) {
	(void)argc;
	(void)argv;

	int server_socket = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
	if (server_socket < 0) {
		puts("error initializing socket");
		server_socket = 0;
		return 1;
	}

	struct sockaddr_in6 server_addr;
	server_addr.sin6_family = AF_INET6;
	server_addr.sin6_port = htons(SERVER_PORT);	

	if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		server_socket = -1;
		puts("error binding socket");
		return 1;
	}

	int res;

	struct sockaddr_in6 src;
	socklen_t src_len = sizeof(struct sockaddr_in6);
	puts("Waiting on message!\n");
	if ((res = recvfrom(server_socket, server_buffer, sizeof(server_buffer), 0, (struct sockaddr *)&src, &src_len)) < 0) {
		puts("error on receive");
	}
	else if (res == 0) {
		puts("peer did shut down");
	}
	else {
		printf("message received: ");
		puts(server_buffer);
	}
	return 0;
}

static int _client_handler(int argc, char ** argv) {
	(void)argc;
	(void)argv;
	
	int s = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
	if (s < 0) {
		puts("error initializing socket");
		return 1;
	}
	
	struct sockaddr_in6 destination;
	destination.sin6_family = AF_INET6;
	destination.sin6_port = htons(SERVER_PORT);
	destination.sin6_scope_id = 5;

	ipv6_addr_from_str((ipv6_addr_t *)&destination.sin6_addr, SERVER_ADDR);
	
	if (sendto(s, CLIENT_MESSAGE, strlen(CLIENT_MESSAGE), 0, (struct sockaddr *)&destination, sizeof(destination)) < 0 ) {
		puts("could not send!");
	}

	return 0;
}
