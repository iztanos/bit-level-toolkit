# Bit-level Toolkit
Ongoing - Last updated 3/8/2026

Tiny C utilities for basic bit operations and a small test harness.

Quick build & run

```
gcc -I. tests/test_bit_ops.c bit_ops.c -o test_bit_ops
./test_bit_ops
```

What’s here

- `bit_ops.h` / `bit_ops.c` — print binary, set/clear/toggle bits
- `memory.h` / `memory.c` — placeholders (empty)
- `main.c` — simple CLI stub (TODO)
- `tests/test_bit_ops.c` — basic assertions for operations

Notes

- `main.c` and the `memory` files are not yet implemented.
	Tests exercise the core bit operations.

