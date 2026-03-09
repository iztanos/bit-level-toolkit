# Bit-level Toolkit
Ongoing - Last updated 3/9/2026

Tiny C utilities for basic bit operations and a small test harness.

Quick build & run

# Bit-level Toolkit

Small C utilities for inspecting and manipulating bits.

Quick start

```bash
gcc -I. tests/test_bit_ops.c bit_ops.c -o test_bit_ops
./test_bit_ops
```

Files

- `bit_ops.h` / `bit_ops.c` — print binary, set/clear/toggle bits, count bits, memory helpers
- `memory.h` / `memory.c` — placeholders
- `main.c` — minimal CLI stub
- `tests/test_bit_ops.c` — simple tests/assertions

Status

Core bit operations implemented and covered by the test harness. `main.c` and `memory.*` are incomplete.



