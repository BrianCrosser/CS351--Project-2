#include <iostream>
#include <cassert>
#include "constants.hpp"
#include "instruction.hpp"

using namespace std;


int main() {
    // Initialize an instruction to all 1's, and
    // test each field. Then, print instruction.
    Instruction i(0xffffffff);
    cout << i.dump() << endl;
    cout << i.opcode().to_ulong() << "\t"
         << i.opcode().to_string() << endl;
    assert (i.opcode().to_ulong() == 0x3f);

    // Asserts for the other fields
    // You can insert more debug statements if any of
    // these fail.
    assert (i.rs().to_ulong() == 0x1f);
    assert (i.rt().to_ulong() == 0x1f);
    assert (i.rd().to_ulong() == 0x1f);
    assert (i.shamt().to_ulong() == 0x1f);
    assert (i.funct().to_ulong() == 0x3f);
    assert (i.imm().to_ulong() == 0xffff);
    assert (i.jmp_offset().to_ulong() == 0x3ffffff);

    // Print instruction
    cout << i.to_string() << endl;
    assert (i.to_string() == "INVALID OPCODE");

    // 32 bits of 0 = SLL $zero, $zero, 0
    Instruction i2(0);
    cout << i2.to_string() << endl;
    assert(i2.to_string() == "SLL $zero, $zero, 0");

    // How to build a general-purpose instruction
    // This one is ADDI $s0, $s1, -1
    Instruction i3(0x08 << 26 | 17 << 21 | 16 << 16 | 0xffff);
    cout << i3.to_string() << endl;
    assert(i3.to_string() == "ADDI $s0, $s1, -1");

    cout << "All asserts OK" << endl;
    return 0;
}
