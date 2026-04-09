*This project has been created as part of the 42 curriculum by lmouta-g.*

---

## Description

**libft** is a custom C library project from the 42 curriculum.
The goal is to rebuild a set of standard C library functions, along with additional utility functions that can be reused in future projects.

This library includes string manipulation, memory handling, character checks, linked list utilities, file descriptor output helpers, `get_next_line`, and `ft_printf`.

This project introduces low-level memory management, pointer manipulation, linked lists, variadic functions, and general C library design.

---

## Instructions

### Compilation

```bash
make
```

This generates one static library:

* `libft.a`

### Usage

1. Build the library:

```bash
make
```

2. Include the header in your project:

```c
#include "libft.h"
```

3. Compile your program with the library:

```bash
cc main.c -L. -lft -I includes
```

---

## Structure

The source files are organized by category:

* `src/ctype`
* `src/stdlib`
* `src/string`
* `src/memory`
* `src/io`
* `src/list`
* `src/printf`
* `src/extra`

---

## Resources

- I don't remember using any specific resources for this project. I think I mostly searched online and read 42 PDFs :D
