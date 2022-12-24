#pragma once
#include "helper.h"

// Technically its the 2A03

// 6502 has 
// - 3 Special purpose Registers PC, SP, P (status register)
// - 3 General Purpose Reg: accumultor (A), index (X & Y)
// 6502 Processor Class
class p6502 
{
public:
	p6502 ();
	~p6502 ();

private:
	// Registers
	u8 X; // Index Register X
	u8 Y; // Index Register Y
	u8 A; // Accumulator
	u8 P; // Processor Status
	u16 PC; // Program Counter
	u8 SP; // no stack overflow detection

	// Memory
	// Maybe should make class or struct dedicated to this but for now...
	u8 memory[0x10000]; // 64 KB of memory mapping
				
};

