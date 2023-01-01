#pragma once
#include "helper.h"

// Technically its the 2A03

// Note for later, hardware bug where JMP would not work correctly if of for $xxFF when reading two bytes from specified address

// 6502 has 
// - 3 Special purpose Registers PC, SP, P (status register)
// - 3 General Purpose Reg: accumultor (A), index (X & Y)
// 6502 Processor Class
class p6502 
{
public:
	p6502 ();
	~p6502 ();

	void emulateCycle(); // 

private:
	// Registers
	u8 X; // Index Register X
	u8 Y; // Index Register Y
	u8 A; // Accumulator
	u8 P; // Processor Status NV-BDIZC
	u16 PC; // Program Counter
	u8 SP; // no stack overflow detection

	uint8_t address_mode; // Addressing mode of the device

	// Memory
	// Maybe should make class or struct dedicated to this but for now...
	u8 memory[0x10000]; // 64 KB of memory mapping, 2KB of RAM $0000 to $0800 $1000 to $1800 mirrors this
	u8 stack[256]; // Should check if stack is part of memory
				
};

