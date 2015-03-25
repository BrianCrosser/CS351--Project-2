#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
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
    bitset<5> rs_bits1;
    
    // Access only the 7th bit to the 11th bit from the 32 bit instruction for R-format and I-format
    for (int j = 0; j < 5; j++){
        rs_bits1[j] = bits[j+6];
    }
    
    //cout << rs_bits1 << endl;
    
    return rs_bits1;
}

bitset<5> Instruction::rt()
{
    bitset<5> rt_bits;
    // Access only the 12th bit to the 16th bit from the 32 bit instruction for R-format and I-format
    for (int j = 0; j < 5; j++){
        rt_bits[j] = bits[j+6];
    }
    return rt_bits;
}

bitset<5> Instruction::rd()
{
    bitset<5> rd_bits;
    // Access only the 17th bit to the 21nd bit from the 32 bit instruction for R-format
    for (int j = 0; j < 5; j++){
        rd_bits[j] = bits[j+6];
    }
    return rd_bits;
}
bitset<5> Instruction::shamt()
{
    bitset<5> shamt_bits;
    // Access only the 22th bit to the 26nd bit from the 32 bit instruction for R-format
    for (int j = 0; j < 5; j++){
        shamt_bits[j] = bits[j+6];
    }
    return shamt_bits;
}
bitset<6> Instruction::funct()
{
    bitset<6> funct_bits;
    // Access only the 27th bit to the last bit from the 32 bit instruction for R-format
    for (int j = 0; j < 6; j++){
        funct_bits[j] = bits[j+7];
    }
    return funct_bits;
}
bitset<16> Instruction::imm()
{
    bitset<16> imm_bits;
    // Access only the 17th bit to the last bit from the 32 bit instruction for I-format
    for (int j = 0; j < 16; j++)
        imm_bits[j] = bits[j+16];
    return imm_bits;
}
    
bitset<26> Instruction::jmp_offset()
{
    bitset<26> jmp_offset_bits;
    
    // Access only the 7th bit to the last bit from the 32 bit instruction for J-format
    for (int j = 0; j < 27; j++)
        jmp_offset_bits[j] = bits[j+6];
    return jmp_offset_bits;
    
}

string Instruction::to_string()
{
    //string x = bits.to_string();
    string instr;
    
    cout << "opcode" << endl;
    cout << opcode() << endl;
    cout << "funct" << endl;
    cout << funct() << endl;
    
    // ADD instruction
    if (funct().to_ulong() == 100000){
        instr = "ADD ";
        instr += rformat1();
    }
    // ADDI instruction
    else if (opcode().to_ulong() == 001000){
        instr = "ADDI ";
        instr += iformat2();
    }
    // ADDU instruction
    else if (funct().to_ulong() == 010001){
        instr = "ADDU ";
        instr += rformat1();
    }
    // ADDIU instruction
    else if (opcode().to_ulong() == 001001){
        instr = "ADDIU ";
        instr += iformat2();
    }
    // SUB instruction
    else if (funct().to_ulong() == 100010){
        instr = "SUB ";
        instr += rformat1();
    }
    // SUBU instruction
    else if (funct().to_ulong() == 100011){
        instr = "SUBU";
        instr += rformat1();
    }
    // LUI instuction
    else if (opcode().to_ulong() == 001111){
        instr = "SUBU ";
        instr += reg_names[rt().to_ulong()];
        instr += ", ";
        instr += imm().to_ulong();
    }
    // AND instruction
    else if (funct().to_ulong() == 100100){
        instr = "AND ";
        instr += rformat1();
    }
    // ANDI instruction
    
    else if (opcode().to_ulong() == 001100){
        instr = "ANDI ";
        instr += iformat2();
    }
    // NOR instruction
    else if (funct().to_ulong() == 100111){
        instr = "NOR ";
        instr += rformat1();
    }
    // OR instruction
    else if (funct().to_ulong() == 100101){
        instr = "OR ";
        instr += rformat1();
    }
    // ORI instruction
    else if (opcode().to_ulong() == 001101){
        instr = "ORI ";
        instr += iformat2();
    }
    // SLL instruction
    else if (funct().to_ulong() == 000000){
        instr = "SLL ";
        instr += rformat2();
    }
    // SRL instuction
    else if (opcode().to_ulong() == 000010){
        instr = "SRL ";
        instr += rformat2();
    }
    // BEQ instruction
    else if (opcode().to_ulong() == 000100){
        instr = "BEQ ";
        instr += iformat2();
    }
    // BNE instruction
    else if (opcode().to_ulong() == 000101){
        instr = "BNE ";
        instr += iformat2();
    }
    // J instruction
    else if (opcode().to_ulong() == 000010){
        instr = "J ";
        instr += bits.to_ulong();
    }
    // JAL instruction
    else if (opcode().to_ulong() == 000011){
        instr = "JAL ";
        instr += bits.to_ulong();
    }
    // JR instruction
    else if (funct().to_ulong() == 001000){
        instr = "JR ";
        instr += reg_names[rs().to_ulong()];
    }
    // LW instuction
    else if (opcode().to_ulong() == 100011){
        instr = "LW ";
        instr += iformat1();
    }
    // SW instruction
    else if (opcode().to_ulong() == 101011){
        instr = "SW ";
        instr += iformat1();
    }
    // LH instruction
    else if (opcode().to_ulong() == 100001){
        instr = "LH ";
        instr += iformat1();
    }
    // LHU instuction
    else if (opcode().to_ulong() == 100101){
        instr = "LHU ";
        instr += iformat1();
    }
    // SH instruction
    else if (opcode().to_ulong() == 101001){
        instr = "SH ";
        instr += iformat1();
    }
    // LB instruction
    else if (opcode().to_ulong() == 100000){
        instr = "LB ";
        instr += iformat1();
    }
    // LBU instruction
    else if (opcode().to_ulong() == 100100){
        instr = "LBU ";
        instr += iformat1();
    }
    // SB instruction
    else if (opcode().to_ulong() == 101000){
        instr = "SB ";
        instr += iformat1();
    }
    // SLT instruction
    else if (funct().to_ulong() == 101010){
        instr = "SLT ";
        instr += rformat1();
    }
    // SLTI instruction
    else if (opcode().to_ulong() == 001010){
        instr = "SLTI ";
        instr += iformat2();
    }
    // SLTU instruction
    else if (funct().to_ulong() == 101011){
        instr = "SLTU ";
        instr += rformat1();
    }
    // SLTIU instruction
    else if (opcode().to_ulong() == 001011){
        instr = "SLTUI ";
        instr += iformat2();
    }
    cout << instr << endl;
    return instr;
}


string Instruction::rformat1()
{
    string instr = reg_names[rd().to_ulong()];
    instr += ", ";
    instr += reg_names[rs().to_ulong()];
    instr += ", ";
    instr += reg_names[rt().to_ulong()];
    return instr;
}

string Instruction::rformat2()
{
    string instr = reg_names[rd().to_ulong()];
    instr += ", ";
    instr += reg_names[rt().to_ulong()];
    instr += ", ";
    long shamt_val = shamt().to_ulong();
    stringstream ss;
    ss << shamt_val;
    instr += ss.str();
    return instr;
}

string Instruction::iformat1()
{
    string instr = reg_names[rt().to_ulong()];
    instr += ", ";
    instr += reg_names[imm().to_ulong()];
    instr += "(";
    instr += rs().to_ulong();
    instr += ")";
    return instr;
}

string Instruction::iformat2()
{
    string instr = reg_names[rt().to_ulong()];
    instr += ", ";
    instr += reg_names[rs().to_ulong()];
    instr += ", ";
    long imm_val= imm().to_ulong();
    stringstream ss;
    ss << imm_val;
    instr += ss.str();
    return instr;
}

string Instruction::jformat()
{
    string instr = reg_names[jmp_offset().to_ulong()];
    return instr;
}

    
    
    
