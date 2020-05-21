// MinecraftClient_1_2_5.cpp

// #include <iostream>
// std::cout << "String\n"

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// #include <stdint.h> // uint32, int32, etc

extern "C" {
	#include "data_types.h"
	#include "packets.h"
}

#define PLAYER_USERNAME "19UV"

#define SERVER_IP "192.168.1.7"
#define SERVER_PORT 25565

#define SERVER_PING "\xFE"

#define VERSION_NUMBER 29
#define MAX_PACKET_LEN 256



int main(int argc, char const *argv[])
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	/*
	send(sock, SERVER_PING, strlen(SERVER_PING), 0);
	valread = read(sock, buffer, 1024);
	int current_field = 0;
	for (int i=4;i<valread;i+=2) {
		if (buffer[i] == (char)0xA7) {
			if (current_field == 0) {
				printf(" ");
			} else {
				printf("/");
			}
			current_field++;
		} else {
			printf("%c", buffer[i]);
		}
	}
	printf("\n");
	*/

	char pkt[MAX_PACKET_LEN];
	int pkt_len = p_buildHandshakePacket((char*)PLAYER_USERNAME, (char*)SERVER_IP, SERVER_PORT, pkt);

	send(sock, pkt, pkt_len, 0);
	valread = read(sock, buffer, 1024);

	printf("%i\n", valread);
	for (int i=0;i<valread;i++) {
		printf("%02x ", buffer[i]);
	}
	printf("\n");

	pkt_len = p_buildLoginRequest(VERSION_NUMBER, (char*)PLAYER_USERNAME, pkt);
	send(sock, pkt, pkt_len, 0);
	valread = read(sock, buffer, 1024);

	printf("%i\n", valread);
	for(int i=0;i<valread;i++) printf("%02x ",buffer[i]);
	printf("\n");

	/*
	char pkt[MAX_PACKET_LEN];
	char username[] = "19UV"; // TODO: Change
	int pkt_len = p_buildLoginRequest(50, username, pkt);

	send(sock, pkt, pkt_len, 0);
	send(sock, (char)0, 1, 0);

	valread = read(sock, buffer, 1024);

	printf("%i\n",valread);
	for (int i=0;i<valread;i++) {
		printf("%02x ",buffer[i]);
	}
	*/

	return 0;
}
