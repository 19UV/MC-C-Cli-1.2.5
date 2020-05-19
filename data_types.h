#ifndef __data__types_h
#define __data__types_h

int writeVarInt(int value, char* buffer);
int writeString(char* value, char* buffer);
int writeInt(int value, char* buffer);
int writeShort(short value, char* buffer);

#endif
