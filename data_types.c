#include <string.h>
#include "data_types.h"

int writeVarInt(int value, char* buffer) {
	int bytes_written = 0;
	do {
		char temp = (char)(value & 0x7f);

		value = (unsigned int)value >> 7; // Note: If Negitive Stuff May Catch on Fire
		if (value != 0) {
			temp |= 0x80;
		}
		buffer[bytes_written++] = temp;
	} while (value != 0);
	return bytes_written;
}

int writeString(char* value, char* buffer) {
	int bytes_written = 0;
	int string_len = strlen(value);

	bytes_written += writeShort((short)string_len, buffer);
	for (int i=0;i<string_len;i++) {
		buffer[bytes_written++] = (char)0;
		buffer[bytes_written++] = value[i];
		// buffer[bytes_written++] = (char)0;
	}

	return bytes_written;
}

int writeShort(short value, char* buffer) {
	int bytes_written = 0;
	for (int i=1;i>=0;i--) {
		buffer[bytes_written++] = (char)(value>>8*i);
	}
	return bytes_written;
}

int writeInt(int value, char* buffer) {
	int bytes_written = 0;
	for (int i=3;i>=0;i--) {
		buffer[bytes_written++] = (char)(value>>8*i);
	}

	return bytes_written;
}
