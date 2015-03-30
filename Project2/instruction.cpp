#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "instruction.hpp"

using namespace std;

Instruction::Instruction()
{
    this->bits = 00000000000000000000000000000000;
}

Instruction::Instruction(string s)
{
    /*
    unsigned long temp;
    stringstream ss(s);
    ss >> temp;
    cout << temp << endl;
    this->bits = bitset<32> (temp);
    
    
    unsigned long temp = strtoul(s.c_str(), NULL, 0);
    cout << s << endl;
    cout << temp << endl;
     */
    this->bits = bitset<32> (string(s));
}

Instruction::Instruction(unsigned long num)
{
    this->bits = bitset<32> (num);
}


// Access the different fields
bitset<6> Instruction::opcode()
{
    bitset<6> op_bits;
    //cout << bits << endl;
    // Access only the first 6 bits from the 32 bit instruction
    for (int i = 0; i < 6; i++){
        //cout << bits[32-i] << endl;
        op_bits[i] = bits[26+i];
    }
    //cout << op_bits << endl;
    return op_bits;
}

bitset<5> Instruction::rs()
{
    bitset<5> rs_bits1;
    
    // Access only the 7th bit to the 11th bit from the 32 bit instruction for R-format and I-format
    for (int j = 0; j < 5; j++){
        rs_bits1[j] = bits[21+j];
    }
    
    //cout << rs_bits1 << endl;
    
    return rs_bits1;
}

bitset<5> Instruction::rt()
{
    bitset<5> rt_bits;
    // Access only the 12th bit to the 16th bit from the 32 bit instruction for R-format and I-format
    for (int j = 0; j < 5; j++){
        rt_bits[j] = bits[16+j];
    }
    return rt_bits;
}

bitset<5> Instruction::rd()
{
    bitset<5> rd_bits;
    // Access only the 17th bit to the 21nd bit from the 32 bit instruction for R-format
    for (int j = 0; j < 5; j++){
        rd_bits[j] = bits[11+j];
    }
    return rd_bits;
}
bitset<5> Instruction::shamt()
{
    bitset<5> shamt_bits;
    // Access only the 22th bit to the 26nd bit from the 32 bit instruction for R-format
    for (int j = 0; j < 5; j++){
        shamt_bits[j] = bits[6+j];
    }
    return shamt_bits;
}
bitset<6> Instruction::funct()
{
    bitset<6> funct_bits;
    // Access only the 27th bit to the last bit from the 32 bit instruction for R-format
    for (int j = 0; j < 6; j++){
        funct_bits[j] = bits[j];
    }
    return funct_bits;
}
bitset<16> Instruction::imm()
{
    bitset<16> imm_bits;
    // Access only the 17th bit to the last bit from the 32 bit instruction for I-format
    for (int j = 0; j < 16; j++)
        imm_bits[j] = bits[j];
    return imm_bits;
}
    
bitset<26> Instruction::jmp_offset()
{
    bitset<26> jmp_offset_bits;
    
    // Access only the 7th bit to the last bit from the 32 bit instruction for J-format
    for (int j = 0; j < 27; j++)
        jmp_offset_bits[j] = bits[6+j];
    return jmp_offset_bits;
    
}

string Instruction::to_string()
{
    //string x = bits.to_string();
    string instr;
    
    cout << "opcode" << endl;
    cout << opcode() << endl;
    cout << "rt" << endl;
    cout << rt() << endl;
    cout << "rs" << endl;
    cout << rs() << endl;
    cout << "rd" << endl;
    cout << rd() << endl;
    cout << "immediate" << endl;
    cout << imm() << endl;
    cout << "funct" << endl;
    cout << funct() << endl;
    cout << "shamt" << endl;
    cout << shamt() << endl;
    cout << endl;
    
    // ADD instruction
    if (funct().to_string() == "100000"){
        instr = "ADD ";
        instr += rformat1();
    }
    // ADDI instruction
    else if (opcode().to_string() == "001000"){
        instr = "ADDI ";
        instr += iformat2();
    }
    // ADDU instruction
    else if (funct().to_string() == "010001"){
        instr = "ADDU ";
        instr += rformat1();
    }
    // ADDIU instruction
    else if (opcode().to_string() == "001001"){
        instr = "ADDIU ";
        instr += iformat2();
    }
    // SUB instruction
    else if (funct().to_string() == "100010"){
        instr = "SUB ";
        instr += rformat1();
    }
    // SUBU instruction
    else if (funct().to_string() == "100011"){
        instr = "SUBU";
        instr += rformat1();
    }
    // LUI instuction
    else if (opcode().to_string() == "001111"){
        instr = "LUI ";
        instr += reg_names[rt().to_ulong()];
        instr += ", ";
        instr += imm().to_ulong();
    }
    // AND instruction
    else if (funct().to_string() == "100100"){
        instr = "AND ";
        instr += rformat1();
    }
    // ANDI instruction
    else if (opcode().to_string() == "001100"){
        instr = "ANDI ";
        instr += iformat2();
    }
    // NOR instruction
    else if (funct().to_string() == "100111"){
        instr = "NOR ";
        instr += rformat1();
    }
    // OR instruction
    else if (funct().to_string() == "100101"){
        instr = "OR ";
        instr += rformat1();
    }
    // ORI instruction
    else if (opcode().to_string() == "001101"){
        instr = "ORI ";
        instr += iformat2();
    }
    // SLL instruction
    else if (funct().to_string() == "000000"){
        instr = "SLL ";
        instr += rformat2();
    }
    // SRL instuction
    else if (funct().to_string() == "000010"){
        instr = "SRL ";
        instr += rformat2();
    }
    // BEQ instruction
    else if (opcode().to_string() == "000100"){
        instr = "BEQ ";
        instr += iformat2();
    }
    // BNE instruction
    else if (opcode().to_string() == "000101"){
        instr = "BNE ";
        instr += iformat2();
    }
    // J instruction
    else if (opcode().to_string() == "000010"){
        instr = "J ";
        instr += bits.to_ulong();
    }
    // JAL instruction
    else if (opcode().to_string() == "000011"){
        instr = "JAL ";
        instr += bits.to_ulong();
    }
    // JR instruction
    else if (funct().to_string() == "001000"){
        instr = "JR ";
        instr += reg_names[rs().to_ulong()];
    }
    // LW instuction
    else if (opcode().to_string() == "100011"){
        instr = "LW ";
        instr += iformat1();
    }
    // SW instruction
    else if (opcode().to_string() == "101011"){
        instr = "SW ";
        instr += iformat1();
    }
    // LH instruction
    else if (opcode().to_string() == "100001"){
        instr = "LH ";
        instr += iformat1();
    }
    // LHU instuction
    else if (opcode().to_string() == "100101"){
        instr = "LHU ";
        instr += iformat1();
    }
    // SH instruction
    else if (opcode().to_string() == "101001"){
        instr = "SH ";
        instr += iformat1();
    }
    // LB instruction
    else if (opcode().to_string() == "100000"){
        instr = "LB ";
        instr += iformat1();
    }
    // LBU instruction
    else if (opcode().to_string() == "100100"){
        instr = "LBU ";
        instr += iformat1();
    }
    // SB instruction
    else if (opcode().to_string() == "101000"){
        instr = "SB ";
        instr += iformat1();
    }
    // SLT instruction
    else if (funct().to_string() == "101010"){
        instr = "SLT ";
        instr += rformat1();
    }
    // SLTI instruction
    else if (opcode().to_string() == "001010"){
        instr = "SLTI ";
        instr += iformat2();
    }
    // SLTU instruction
    else if (funct().to_string() == "101011"){
        instr = "SLTU ";
        instr += rformat1();
    }
    // SLTIU instruction
    else if (opcode().to_string() == "001011"){
        instr = "SLTUI ";
        instr += iformat2();
    }
    cout << instr << endl;
    cout << endl;
    
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
    long imm_long = imm().to_ulong();
    string imm_string = std::__1::to_string(imm_long);
    instr += imm_string;
    instr += "(";
    instr += reg_names[rs().to_ulong()];
    instr += ")";
    return instr;
}

string Instruction::iformat2()
{
    string instr = reg_names[rt().to_ulong()];
    instr += ", ";
    instr += reg_names[rs().to_ulong()];
    instr += ", ";
    /*
    long imm_val= imm().to_ulong();
    int imm_int =
    string imm_long = std::__1::to_string(imm_val);
    instr += imm_long;
*/
    //*****     we've tried the above code and below *****                  ERROR HERE
    string imm_string = imm().to_string();     //gets bitset into string resulting in "111111111"
    
    unsigned long long imm_long = bitset<16>(imm_string).to_ulong();     //changes string to decimal resulting in -1
    
    int imm_long;
    
    imm_string = std::__1::to_string(imm_long);     //converts decimal to string resulting in "-1"
    
    instr += imm_string;     //adds string to output string
    return instr;
}

string Instruction::jformat()
{
    string instr = reg_names[jmp_offset().to_ulong()];
    return instr;
}

    
    
    
