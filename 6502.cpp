#include "6502.h"

p6502::p6502() {

}

p6502::~p6502() {} // default destructor for now


// Look into addressing modes
// Look at CPU instructions
void p6502::emulateCycle() {
	// Giant Case Statement

	// Fetch opcode
	u16 opcode = (memory[PC] & 0xFF00) >> 8;

	switch (opcode)
	{
	case 0x00:
		break;
	default:
		break;
	}

}