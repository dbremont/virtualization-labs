# janusvm

> **JanusVM** is a lightweight, modular virtual machine designed to execute bytecode efficiently.

## Model

> ...

### Spec

- 16 bit virtual machine
- 65536 bytes (65 KB) bytes of addressable memory
- Serial COM Port
- Floppy Drive

```c
    // int8 *code;
    // int8 *stack;
    // int8 *heap;
    // int8 *globals;
    // int8 *constants;
    // int8 *strings;
    // int8 *symbols;
    // int8 *functions;
    // int8 *modules;
    // int8 *exceptions;
    // int8 *threads;
    // int8 *processes;
    // int8 *events;
    // int8 *timers;
```

### Components

- **CPU**: Virtual processor executing instructions.
- **ALU (Arithmetic Logic Unit)**: Handles computations and logic operations.
- **Instruction Set**: Defines valid operations (bytecode, IR, or direct machine code).
- **Memory Model**: Manages virtualized memory (heap, stack, registers).
- **Execution Engine**: Executes instructions via interpretation, JIT, AOT compilation, or hybrid methods.
- **Control Unit**: Directs execution flow (fetch-decode-execute).
- **I/O Manager**: Handles virtualized peripherals (disk, network, display, keyboard, etc.).

### Architecture Diagram

```text
+--------------------------------------------------+
|                  Virtual Machine                |
+--------------------------------------------------+
| +---------+   +-----------------------------+   |
| |         |   |       Instruction Set       |   |
| |  CPU    |   |  (Bytecode, IR, or Native)  |   |
| |         |   +-----------------------------+   |
| +---------+                                    |
| +---------+   +-----------------------------+   |
| |         |   |        Memory Model         |   |
| |  ALU    |   |  (Heap, Stack, Registers)   |   |
| |         |   +-----------------------------+   |
| +---------+                                    |
| +---------+   +-----------------------------+   |
| |         |   |  Execution Engine (Interp,  |   |
| | Control |   |   JIT, AOT, or Hybrid)      |   |
| |  Unit   |   +-----------------------------+   |
| +---------+                                    |
| +---------+   +-----------------------------+   |
| |  I/O    |   |     Virtual Peripherals     |   |
| | Manager |   | (Disk, Network, Display)    |   |
| +---------+   +-----------------------------+   |
+--------------------------------------------------+
```

### Register Model

- AX
- BX
- CX
- DX
- SP
- IP

## References

- [Emulator](https://righteous-guardian-68f.notion.site/Emulator-1aec0f5171ec8094b5c7cf0af46f8ff4?pvs=74)
