#include <bitset>
#include <iostream>
#include "instruction.hpp"
using namespace std;

// Access the different fields
bitset<6> opcode()
{
    bitset<6> op_bits;
    // Access only the first 6 bits from the 32 bit instruction
    for (int i = 0; i < 5; i++){
        op_bits += bits[i];
    }
    return op_bits;
}

bitset<5> rs()
{
    bitset<5> rs_bits;
    // Access only the 7th bit to the 11th bit from the 32 bit instruction for R-format and I-format
    for (int i = 7; i < 12; i++){
        rs_bits += bits[i];
    }
    return rs_bits;
}

bitset<5> rt()
{
    bitset<5> rt_bits;
    // Access only the 12th bit to the 16th bit from the 32 bit instruction for R-format and I-format
    for (int i = 12; i < 17; i++){
        rt_bits += bits[i];
    }
    return rt_bits;
}

bitset<5> rd()
{
    bitset<5> rd_bits;
    // Access only the 17th bit to the 21nd bit from the 32 bit instruction for R-format
    for (int i = 17; i < 22; i++){
        rd_bits += bits[i];
    }
    return rd_bits;
}
bitset<5> shamt()
{
    bitset<5> shamt_bits;
    // Access only the 22th bit to the 26nd bit from the 32 bit instruction for R-format
    for (int i = 22; i < 27; i++){
        shamt_bits += bits[i];
    }
    return shamt_bits;
}
bitset<6> funct()
{
    bitset<6> funct_bits;
    // Access only the 27th bit to the last bit from the 32 bit instruction for R-format
    for (int i = 27; i < 33; i++){
        funct_bits += bits[i];
    }
    return funct_bits;
}
bitset<16> imm()
{
    bitset<16> imm_bits;
    // Access only the 17th bit to the last bit from the 32 bit instruction for I-format
    for (int i = 17; i < 33; i++){
        imm_bits += bits[i];
    }
    return imm_bits;
}
bitset<26> jmp_offset()
{
    bitset<26> jmp_offset_bits;
    // Access only the 7th bit to the last bit from the 32 bit instruction for J-format
    for (int i = 7; i < 33; i++){
        jmp_offset_bits += bits[i];
    }
    return jmp_offset_bits;
}
