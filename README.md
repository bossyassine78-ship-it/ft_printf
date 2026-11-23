*This project has been created as part of the 42 curriculum by yael-hil.*

# ft_printf

## Description

`ft_printf` is my implementation of the mandatory subset of the C `printf` function. The project focuses on variadic arguments, format-string parsing, number conversion, and writing formatted output without implementing the buffering of the original `printf`.

It builds a static library named `libftprintf.a` and exposes:

```c
int ft_printf(const char *format, ...);
```

Supported conversions:

| Conversion | Output |
| --- | --- |
| `%c` | One character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | Lowercase hexadecimal |
| `%X` | Uppercase hexadecimal |
| `%%` | A literal percent sign |

The function returns the number of characters written, or `-1` if a write fails. This repository implements the mandatory part only; formatting flags, field width, and precision are not supported.

## Instructions

### Compile

```sh
make
```

This creates `libftprintf.a` in the repository root using `cc`, `-Wall -Wextra -Werror`, and `ar`.

### Use the library

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, the answer is %d\n", "42", 42);
    return (0);
}
```

With the example saved as `main.c` in the repository root:

```sh
cc -Wall -Wextra -Werror main.c -I. libftprintf.a -o demo
./demo
```

### Makefile rules

```sh
make         # Build libftprintf.a
make clean   # Remove object files
make fclean  # Remove object files and the library
make re      # Rebuild from scratch
```

## Algorithm and Data Structure

**42 subject requirement (v12.1, Chapter V):**

> A detailed explanation and justification of the chosen algorithm and data structure must also be included.

### 1. One-pass format parsing

I chose to read the format string **from left to right, one character at a time**, rather than copying or splitting it.

The flow follows the actual functions in this repository:

1. `ft_printf` initializes a `va_list` with `va_start` and passes it to `print_argument`.
2. `print_argument` keeps an index `i` for the format string and a running output count.
3. For an ordinary character, `print_db` calls `ft_putchar`.
4. For `%`, `print_db` looks at the following character. If it is supported, `check_arguments` selects the matching conversion helper.
5. The helper writes its output and returns the number of characters written. `print_argument` adds that number to the total.
6. If a helper reports `-1`, parsing stops and the error is returned to the caller.

For an unsupported conversion, my parser writes the `%` literally and then processes the following character on the next iteration. A trailing `%` returns `-1`. Unsupported conversions are outside the mandatory conversion set.

**Why this algorithm?** The input is already a string, so a simple index is enough to scan it. One pass keeps the control flow direct, avoids allocations and temporary format buffers, and makes each conversion easy to isolate and debug.

### 2. Dispatching variadic arguments

`ft_printf` creates one `va_list ap` and passes its address (`va_list *`) through the parser to `check_arguments`. This allows the dispatcher to advance the same argument list whenever a conversion consumes a value.

| Specifier | Type retrieved with `va_arg` | Helper |
| --- | --- | --- |
| `%c` | `int` | `ft_putchar` |
| `%s` | `char *` | `ft_putstr` |
| `%p` | `void *` | `for_p` |
| `%d`, `%i` | `int` | `ft_putdec` |
| `%u` | `unsigned int` | `ft_putdec_unsigned` |
| `%x` | `unsigned int` | `ft_puthex` |
| `%X` | `unsigned int` | `ft_puthex_unsigned` |
| `%%` | No argument | Direct `write` |

**Why this choice?** The `<stdarg.h>` interface already provides the state needed to traverse variadic arguments. Passing a pointer to that state keeps argument consumption consistent across the helper functions, without a custom argument container.

### 3. Recursive number conversion

The decimal and hexadecimal functions use the same **division-and-remainder** idea:

1. Choose a digit alphabet: `0123456789`, `0123456789abcdef`, or `0123456789ABCDEF`.
2. If `number >= base`, recursively print `number / base` first.
3. Print the final digit using `digits[number % base]`.

For example, printing `42` in base 10 first processes `4`, then prints `2`. For signed decimal values, `ft_putdec` prints `-` before converting the magnitude. The `%p` helper handles a null pointer as `(nil)`; otherwise, it prints `0x` followed by the lowercase hexadecimal representation of the address.

**Why recursion?** Printing the quotient first naturally puts the most significant digit first. There is no need to build a reversed string, allocate a digit buffer, or reverse the result afterwards. The tradeoff is a small call stack whose depth depends on the number of digits.

### 4. Writing, counting, and errors

Output is written directly to standard output with `write` (usually through `ft_putchar`). Each printing helper returns the number of characters it actually wrote. Recursive helpers add the counts from deeper calls, and `print_argument` accumulates the final result.

Every helper checks for failed writes and propagates `-1` upward immediately. There is **no printf-style output buffer**, which follows the mandatory project's constraints.

**Why this design?** Keeping the count and error handling in the same helpers that write characters makes the return value straightforward to track. The tradeoff is more `write` calls than a buffered implementation, but buffering is not part of this project.

### 5. Data structures and complexity

No custom structure or heap allocation is needed:

- `const char *format` refers to the input format string.
- `int i` tracks the current format position; `int count` tracks written characters.
- `va_list ap` maintains variadic argument traversal state.
- Fixed digit alphabets are used to map remainders to printable characters.
- Recursive calls use the call stack temporarily for numeric conversion.

The parser itself scans each format character once, so its traversal cost is **O(n)** for a format string of length `n`, excluding the work of printing expanded arguments. Conversion work is proportional to the output digits/characters. The parser needs **O(1)** additional state, while number printing uses **O(d)** stack frames for `d` digits.

## Resources

- [printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) — conversion syntax and return values.
- [stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html) — `va_list`, `va_start`, `va_arg`, and `va_end`.
- [write(2)](https://man7.org/linux/man-pages/man2/write.2.html) — output and write errors.
- ISO C, section 7.16 (`<stdarg.h>`) — variable argument handling.
- System V AMD64 ABI — background on variadic calling conventions.

### AI use

AI was used as a learning and review tool to discuss variadic arguments, the `va_list` mechanism, recursion, Makefile behavior, parsing edge cases, and write-error propagation. It also helped review the implementation and organize this README. The final project code, design decisions, and evaluation readiness remain the author's responsibility.
