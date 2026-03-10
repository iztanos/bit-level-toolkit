# Bit-level Toolkit
Last updated 3/10/2026

Small C utilities for inspecting and manipulating bits.

Quick start (using make)

```bash
cd bit-level-toolkit
make        # builds the CLI `bit-tool`
make test   # builds and runs the test harness
```

What’s included

- `memory.c` / `bit_ops.c` — print binary, set/clear/toggle bits, count bits, memory helpers
- `main.c` — CLI with simple commands (print, set, clear, toggle, count, memory, endian)
- `tests/test_bit_ops.c` — assertions that exercise functionality

License: MIT




