#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 256
#define REG_COUNT 4

// Opcodes
typedef enum {
    MOV_REG_IMM, // Move immediate to register
    MOV_REG_REG, // Move register to register
    MOV_REG_MEM, // Move memory to register
    MOV_MEM_REG, // Move register to memory
    ADD,         // Add two registers
    SUB,         // Subtract two registers
    PRINT,       // Print register value
    HALT         // Stop execution
} Opcode;

typedef struct  VM{
    uint8_t memory[MEM_SIZE];
    int registers[REG_COUNT];
    uint8_t code[MEM_SIZE];

    int ip; // Instruction pointer

    void (*run)(struct VM *);
} VM;

void run(VM *vm);
void init_vm(VM *vm);