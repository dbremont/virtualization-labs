# Notes

## VM Creation

```c
{
    VM *vm = (VM *)malloc(sizeof(VM));
    if (!vm) {
        perror("Failed to allocate memory for VM");
        exit(EXIT_FAILURE);
    }

    // Initialize CPU registers
    vm->c.r.ax = (Reg *)malloc(sizeof(Reg));
    vm->c.r.bx = (Reg *)malloc(sizeof(Reg));
    vm->c.r.cx = (Reg *)malloc(sizeof(Reg));
    vm->c.r.dx = (Reg *)malloc(sizeof(Reg));
    vm->c.r.sp = (Reg *)malloc(sizeof(Reg));
    vm->c.r.ip = (Reg *)malloc(sizeof(Reg));

    if (!vm->c.r.ax || !vm->c.r.bx || !vm->c.r.cx || !vm->c.r.dx || !vm->c.r.sp || !vm->c.r.ip) {
        perror("Failed to allocate memory for registers");
        free(vm);
        exit(EXIT_FAILURE);
    }

    // Initialize stack and program pointer
    memset(vm->s, 0, sizeof(Stack));
    vm->p = NULL;

    return vm;
}
```
