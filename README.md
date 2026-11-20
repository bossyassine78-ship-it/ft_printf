*This project has been created as part of the 42 curriculum by yael-hil.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf` function.

The project builds the static library `libftprintf.a`, which provides:

```c
int	ft_printf(const char *format, ...);
```

It handles the mandatory conversions:

- `%c` character
- `%s` string
- `%p` pointer address in lowercase hexadecimal
- `%d` and `%i` signed decimal integer
- `%u` unsigned decimal integer
- `%x` lowercase hexadecimal
- `%X` uppercase hexadecimal
- `%%` percent sign

Like `printf`, `ft_printf` returns the number of characters printed, or `-1` if a write operation fails.

## Instructions

### Build the library

```sh
make
```

This creates `libftprintf.a` at the repository root.

### Use it in another program

Include the project header and link the archive:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("value: %d\n", 42);
	return (0);
}
```

```sh
cc main.c -I. libftprintf.a
./a.out
```

### Makefile rules

```sh
make        # build libftprintf.a
make clean  # remove object files
make fclean # remove object files and the library
make re     # rebuild everything
```

## Implementation choices

### Format parsing

The format string is read once from left to right.

- Regular characters are written directly.
- When `%` is encountered, the next character is sent to the conversion dispatcher.
- The dispatcher chooses the suitable printing helper.
- Every helper returns its printed-character count. Those counts are accumulated by `ft_printf`.

This is a single-pass parser: the format string is not copied, split, or stored in an additional structure. Its time complexity is O(n), where n is the format string length, excluding the characters produced by conversions.

### Variable arguments

`va_list` stores the traversal state of the variable arguments passed after `format`.

`ft_printf` initializes it with `va_start`, then passes it to the parsing and dispatch functions. Each relevant conversion retrieves its next argument with `va_arg` using the correct type:

- `int` for `%c`, `%d`, and `%i`
- `unsigned int` for `%u`, `%x`, and `%X`
- `void *` for `%p`
- `char *` for `%s`

No custom data structure is used. `va_list` is the only stateful object needed to walk through the changing argument list.

### Numeric conversions

The decimal and hexadecimal helpers use recursion.

For a number in a base such as 10 or 16:

1. The function first prints `number / base` when the number is at least the base.
2. It then prints the digit at `number % base`.

Calling the recursive part first prints the most significant digit before the following ones. This avoids an extra buffer or a reverse operation. The recursion depth is limited to the number of digits.

### Pointer conversion

The pointer helper prints `(nil)` for a null pointer. Otherwise, it writes the `0x` prefix and converts the pointer address to an `unsigned long` before printing it in lowercase hexadecimal.

### Error propagation

The lowest-level output function uses `write`. Each helper propagates `-1` immediately when writing fails, so `ft_printf` can also return `-1`.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- ISO C standard, section 7.16: Variable arguments (`<stdarg.h>`)
- System V AMD64 ABI, for background on how variadic arguments are passed on x86-64

### AI use

AI was used as a learning and review aid: to explain variadic arguments, `va_list`, compilation, Makefiles, recursion, and the causes of bugs encountered during development. The implementation was written, tested, and integrated by the author.
