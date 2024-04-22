#ifndef _system_data_h_
#define _system_data_h_ 1

#include <iostream>
#include "chip8.h"

#define NUM_V_REGISTERS 16
#define RAM_SIZE 4096
#define SCREEN_SIZE 64 * 32
#define STACK_SIZE 16

typedef class Registers {
public:
    unsigned short I; // index registers
    unsigned short pc; // program counter
    unsigned char V[NUM_V_REGISTERS]; // Registers V[0] - V[15]

    Registers() {
        I = 0;
        pc = 0;
        for(int i = 0; i < NUM_V_REGISTERS; ++i) {
            V[i] = 0;
        }        
    }

} Registers;

typedef class Stack {
public:
    unsigned short sp;
    unsigned short stack[STACK_SIZE];

    Stack() {
        sp = 0;
        for(int i = 0; i < STACK_SIZE; ++i) {
            stack[i] = 0;
        } 
    }
} Stack;

typedef class SystemData {
public: 
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short opcode; // current opcode
    unsigned char memory[RAM_SIZE]; // 4KB of RAM

    unsigned char keypad;
    unsigned char screen[SCREEN_SIZE];

    Stack stack;
    Registers registers;

    SystemData() {
        delay_timer = 0;
        sound_timer = 0;
        keypad = 0;
        opcode = 0;
        for(int i = 0; i < RAM_SIZE; ++i) {
            memory[i] = 0;
        }
    }
} SystemData;

#endif