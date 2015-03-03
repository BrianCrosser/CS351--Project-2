#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int WORD_SIZE = 32;  // MIPS word size
const unsigned int NUM_REGS = 32;   // Number of registers in regfile

// Register names by their numeric ID
const std::string reg_names[32] = {
    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
    "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};


#endif
