#pragma once
#include <stdio.h>
#include "helper.h"
#include <stdlib.h>

struct ROM {
	u8* rom_data;
	u8* vrom_data;
};

void loadRom(char* rom) {
	FILE* fp;

	if (fopen_s(&fp, rom, "rb")) {
		fprintf(stderr, "Cannot open file exiting");
		exit(1);
	}
	char buf[4096];
	fread(buf, 1, 4096, fp); // Works under the assumption that rom is less than memory, though better implementation would look at filesize
	printf("ROM LOADED: %s\n", rom);
	fclose(fp);

	// TODO: add check to see if it is a NES file by looking for the NES^Z signature in the first four bytes
	u8 rom_banks_16 = buf[4];
	u8 vrom_banks_8 = buf[5];
	u8 hw_flags_1 = buf[6];
	u8 hw_flags_2 = buf[7];
	u8 ram_banks_8 = buf[8];

	u8* rom_data = new u8[0x4000 * rom_banks_16]; // C++ syntax feels strange after using C
	u8* vrom_data = new u8[0x2000 * vrom_banks_8];
}

class NES
{
	// Composed of
	// 20A3 CPU
	// PPU
	// APU
	// Memory Map
	// I/O Registers
};

