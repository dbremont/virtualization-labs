#include "janusvm.h"
#include "janusvmutil.h"

void print_help() {
    printf("Usage: ./janusvm <program.jvm>\n");
    printf("Options:\n");
    printf("  --help   Show this help message\n");
}

void start_vm(const char *filename){
    VM vm;
    init_vm(&vm);

    int size = load_program_from_file(filename, vm.code);
    if (size > 0) {
        vm.run(&vm);
    }

}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Error: No input file provided.\n");
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    start_vm(argv[1]);

    return 0;
}
