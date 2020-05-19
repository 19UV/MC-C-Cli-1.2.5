#include <stdio.h>

/*
#include <sys/socket.h> // Just for p_GetServerData
#include <arpa/inet.h>
#include <unistd.h>
*/

#include <string.h>

#include "data_types.h"

/*
int p_GetServerData(char* address, int port) {
	int s = 0;
	int v_read;

	struct sockaddr_in s_addr;
	char buff[1024] = { 0 };
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\nSocket Creation Error; Could not load server data\n");
		return -1;
	}

	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(port);

	if(inet_pton(AF_INET, address, &s_addr.sin_addr) <= 0)
	{
		printf("\nInvalid Address; Could not load server data\n");
		return -1;
	}

	if (connect(s, (struct sockaddr_in *)&s_addr, sizeof(s_addr)) < 0)
	{
		printf("\nConnection Failed; Could not load server data\n");
		return -1;
	}
	send(s,"\xFE",4,0);
	v_read = read(s,buff,1024);

	printf("Got Data\n"); // TODO: Add Feedback

	return 0;
}
*/

int p_buildLoginRequest(int version, char* user, char* packet) {
	int index = 0;
	packet[index++] = (char)0x01;
	index += writeInt(version, &packet[index]);
	index += writeString(user, &packet[index]);

	// Past This Point, You Should Be Able To Put Anything So Long As Its The Correct Length
	index += writeString("", &packet[index]);
	index += writeInt(0, &packet[index]);
	index += writeInt(0, &packet[index]);
	// index += writeInt(0, &packet[index]);
	packet[index++] = (char)0;
	packet[index++] = (char)0; // Should be Unsigned
	packet[index++] = (char)0; // Should be Unsigned

	// packet[index++] = (char)0;

	return index;
}

int p_parseLoginResponse(char* packet) {
	if (packet[0] != (char)0x01) {printf("ERROR: Packet Not Login Response");return 1;}

}

// This Function Was Only For Testing
// But It May Be Used Eventually
int getIntLen(int value) {
	int v = (float)value;
	int value_len = 1;
	for(int b=0;b<25;b++) {
		if((v/=10)>0){
			value_len++;
		}else{
			break;
		}
	}
	return value_len;
}

int p_buildHandshakePacket(char* user, char* host, int port, char* packet) {
	int index = 0;
	packet[index++] = (char)0x02;

	int user_len = strlen(user);
	int host_len = strlen(host);
	int base_len = user_len + host_len + 3;

	int pt = (float)port;
	for (int a=0;a<25;a++) { // FOR loop for limit cap
		if ((pt /= 10) > 0) {
			base_len++;
		} else {
			break;
		}
	}
	char base[base_len];

	sprintf(base, "%s;%s:%i", user, host, port);

	index += writeString(base, &packet[index]);

	return index;
}
