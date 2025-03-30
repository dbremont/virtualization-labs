#include "janusvmutil.h"
#include "janusvm.h"

int opcode_from_string(const char *str) {
    if (strcmp(str, "MOV_REG_IMM") == 0) return MOV_REG_IMM;
    if (strcmp(str, "MOV_REG_REG") == 0) return MOV_REG_REG;
    if (strcmp(str, "MOV_REG_MEM") == 0) return MOV_REG_MEM;
    if (strcmp(str, "MOV_MEM_REG") == 0) return MOV_MEM_REG;
    if (strcmp(str, "ADD") == 0) return ADD;
    if (strcmp(str, "SUB") == 0) return SUB;
    if (strcmp(str, "PRINT") == 0) return PRINT;
    if (strcmp(str, "HALT") == 0) return HALT;
    return -1; // Invalid opcode
}

int load_program_from_file(const char *filename, uint8_t *program) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int index = 0;

    while (fgets(line, sizeof(line), file) && index < MAX_PROGRAM_SIZE) {
        char instr[16];
        int arg1, arg2;
        int count = sscanf(line, "%s %d %d", instr, &arg1, &arg2);

        int opcode = opcode_from_string(instr);
        if (opcode == -1) {
            fprintf(stderr, "Unknown instruction: %s\n", instr);
            continue;
        }

        program[index++] = (uint8_t)opcode;
        if (count > 1) program[index++] = (uint8_t)arg1;
        if (count > 2) program[index++] = (uint8_t)arg2;
    }

    fclose(file);
    return index; // Return number of bytes loaded
}