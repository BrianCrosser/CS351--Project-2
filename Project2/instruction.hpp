#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <bitset>
#include <iostream>
#include "constants.hpp"
using namespace std;

class Instruction {

    public:
        Instruction() : bits(0) { };
        Instruction(string s) : bits(s) { };
        Instruction(unsigned long num) : bits(num) { };

        // No dynamically allocated memory to delete
        ~Instruction() { }

        // Access the different fields
        bitset<6> opcode();
        bitset<5> rs();
        bitset<5> rt();
        bitset<5> rd();
        bitset<5> shamt();
        bitset<6> funct();
        bitset<16> imm();
        bitset<26> jmp_offset();

        // For debugging -- uses bitset to_string() method
        string dump() { return bits.to_string(); }

        // String representation (in assembly)
        string to_string();


    private:
        bitset<WORD_SIZE> bits;
};

#endif
