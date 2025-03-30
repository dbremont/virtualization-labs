# janusvm

> **JanusVM** is a lightweight, modular virtual machine designed to execute bytecode efficiently.

## Model

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

## References

- [Emulator](https://righteous-guardian-68f.notion.site/Emulator-1aec0f5171ec8094b5c7cf0af46f8ff4?pvs=74)
