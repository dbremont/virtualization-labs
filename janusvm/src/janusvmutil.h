#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_PROGRAM_SIZE 256
#define MAX_LINE_LENGTH 32
int opcode_from_string(const char *str);
int load_program_from_file(const char *filename, uint8_t *program);
