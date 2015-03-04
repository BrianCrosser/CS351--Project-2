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
	int counter = 0;
    // Access only the 7th bit to the 11th bit from the 32 bit instruction for R-format and I-format
    for (int i = 6; i < 11; i++){
		rs_bits[counter] = bits[i];
		counter++;
    }
    return rs_bits;
}

bitset<5> Instruction::rt()
{
    bitset<5> rt_bits;
	int counter = 0;
	// Access only the 12th bit to the 16th bit from the 32 bit instruction for R-format and I-format
    for (int i = 11; i < 16; i++){
		rt_bits[counter] = bits[i];
		counter++;
    }
    return rt_bits;
}

bitset<5> Instruction::rd()
{
    bitset<5> rd_bits;
	int counter = 0;
    // Access only the 17th bit to the 21nd bit from the 32 bit instruction for R-format
    for (int i = 16; i < 21; i++){
		rd_bits[counter] = bits[i];
		counter++;
	}
    return rd_bits;
}
bitset<5> Instruction::shamt()
{
    bitset<5> shamt_bits;
	int counter = 0;
	// Access only the 22th bit to the 26nd bit from the 32 bit instruction for R-format
    for (int i = 21; i < 26; i++){
		shamt_bits[counter] = bits[i];
		counter++;
    }
    return shamt_bits;
}
bitset<6> Instruction::funct()
{
    bitset<6> funct_bits;
	int counter = 0;
    // Access only the 27th bit to the last bit from the 32 bit instruction for R-format
    for (int i = 26; i < 32; i++){
		funct_bits[counter] = bits[i];
		counter++;
    }
    return funct_bits;
}
bitset<16> Instruction::imm()
{
    bitset<16> imm_bits;
	int counter = 0;
	// Access only the 17th bit to the last bit from the 32 bit instruction for I-format
    for (int i = 16; i < 32; i++){
		imm_bits[counter] = bits[i];
		counter++;
    }
    return imm_bits;
}
bitset<26> Instruction::jmp_offset()
{
    bitset<26> jmp_offset_bits;
	int counter = 0;
	// Access only the 7th bit to the last bit from the 32 bit instruction for J-format
    for (int i = 6; i < 32; i++){
		jmp_offset_bits[counter] = bits[i];
		counter++;
    }
    return jmp_offset_bits;
}

string Instruction::to_string()
{
    string x = bits.to_string();
    string instr;
    
    // ADD instruction
    if (funct() == 10100){
        instr = "ADD";
    }
    // ADDI instruction
    if (opcode() == 01000){
        instr = "ADDI";
    }
    // ADDU instruction
    if (funct() == 10101){
        instr = "ADDU";
    }
    // ADDIU instruction
    if (opcode() == 01001){
        instr = "ADDIU";
    }
    // SUB instruction
    if (funct() == 10110){
        instr = "SUB";
    }
    // SUBU instruction
    if (funct() == 10111){
        instr = "SUBU";
    }
    // LUI instuction
    if (opcode() == 01111){
        instr = "SUBU";
    }
    // AND instruction
    if (funct() == 11000){
        instr = "AND";
    }
    // ANDI instruction
    if (opcode() == 01100){
        instr = "ANDI";
    }
    // NOR instruction
    if (funct() == 11011){
        instr = "NOR";
    }
    // OR instruction
    if (funct() == 11001){
        instr = "OR";
    }
    // ORI instruction
    if (opcode() == 01101){
        instr = "ORI";
    }
    // SLL instruction
    if (funct() == 00000){
        instr = "SLL";
    }
    // SRL instuction
    if (opcode() == 00010){
        instr = "SRL";
    }

	return x;
}
