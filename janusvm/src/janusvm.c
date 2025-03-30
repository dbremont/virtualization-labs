#include "janusvm.h"

void run(VM *vm) {
    while (1) {
        uint8_t op = vm->code[vm->ip++];
        switch (op) {
            case MOV_REG_IMM: {
                uint8_t reg = vm->code[vm->ip++];
                int value = vm->code[vm->ip++];
                vm->registers[reg] = value;
                break;
            }
            case MOV_REG_REG: {
                uint8_t dest = vm->code[vm->ip++];
                uint8_t src = vm->code[vm->ip++];
                vm->registers[dest] = vm->registers[src];
                break;
            }
            case MOV_REG_MEM: {
                uint8_t reg = vm->code[vm->ip++];
                uint8_t addr = vm->code[vm->ip++];
                vm->registers[reg] = vm->memory[addr];
                break;
            }
            case MOV_MEM_REG: {
                uint8_t addr = vm->code[vm->ip++];
                uint8_t reg = vm->code[vm->ip++];
                vm->memory[addr] = vm->registers[reg];
                break;
            }
            case ADD: {
                uint8_t reg1 = vm->code[vm->ip++];
                uint8_t reg2 = vm->code[vm->ip++];
                vm->registers[reg1] += vm->registers[reg2];
                break;
            }
            case SUB: {
                uint8_t reg1 = vm->code[vm->ip++];
                uint8_t reg2 = vm->code[vm->ip++];
                vm->registers[reg1] -= vm->registers[reg2];
                break;
            }
            case PRINT: {
                uint8_t reg = vm->code[vm->ip++];
                printf("Reg[%d] = %d\n", reg, vm->registers[reg]);
                break;
            }
            case HALT:
                return;
        }
    }
}

void init_vm(VM *vm) {
    memset(vm->memory, 0, MEM_SIZE);
    memset(vm->registers, 0, sizeof(vm->registers));
    vm->ip = 0;
    vm->run = run;
}