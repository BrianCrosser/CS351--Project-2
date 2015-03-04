#include <bitset>
#include <iostream>
#include "instruction.hpp"
using namespace std;

// Access the different fields
bitset<6> Instruction::opcode()
{
    bitset<6> op_bits;
    // Access only the first 6 bits from the 32 bit instruction
    for (int i = 0; i < 6; i++){
        op_bits[i] = bits[i];
    }
    return op_bits;
}

bitset<5> Instruction::rs()
{
    bitset<5> rs_bits;
    // Access only the 7th bit to the 11th bit from the 32 bit instruction for R-format and I-format
    for (int i = 6; i < 11; i++){
		rs_bits[i] = bits[i];
    }
    return rs_bits;
}

bitset<5> Instruction::rt()
{
    bitset<5> rt_bits;
    // Access only the 12th bit to the 16th bit from the 32 bit instruction for R-format and I-format
    for (int i = 11; i < 16; i++){
		rt_bits[i] = bits[i];
    }
    return rt_bits;
}

bitset<5> Instruction::rd()
{
    bitset<5> rd_bits;
    // Access only the 17th bit to the 21nd bit from the 32 bit instruction for R-format
    for (int i = 16; i < 21; i++){
		rd_bits[i] = bits[i];
    }
    return rd_bits;
}
bitset<5> Instruction::shamt()
{
    bitset<5> shamt_bits;
    // Access only the 22th bit to the 26nd bit from the 32 bit instruction for R-format
    for (int i = 21; i < 26; i++){
		shamt_bits[i] = bits[i];
    }
    return shamt_bits;
}
bitset<6> Instruction::funct()
{
    bitset<6> funct_bits;
    // Access only the 27th bit to the last bit from the 32 bit instruction for R-format
    for (int i = 26; i < 32; i++){
		funct_bits[i] = bits[i];
    }
    return funct_bits;
}
bitset<16> Instruction::imm()
{
    bitset<16> imm_bits;
    // Access only the 17th bit to the last bit from the 32 bit instruction for I-format
    for (int i = 16; i < 32; i++){
		imm_bits[i] = bits[i];
    }
    return imm_bits;
}
bitset<26> Instruction::jmp_offset()
{
    bitset<26> jmp_offset_bits;
    // Access only the 7th bit to the last bit from the 32 bit instruction for J-format
    for (int i = 6; i < 32; i++){
		jmp_offset_bits[i] = bits[i];
    }
    return jmp_offset_bits;
}

string Instruction::to_string()
{
	string x = bits.to_string();
	return x;
}