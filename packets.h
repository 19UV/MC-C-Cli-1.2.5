#ifndef __packets_h
#define __packets_h

int p_GetServerData(char* address, int port);
int p_buildLoginRequest(int version, char* user, char* packet);
int p_buildHandshakePacket(char* user, char* host, int port, char* packet); // Currently doesn't effect anything

#endif
