## Description

> [!NOTE]
> This libft is **not** the minimal version required for the 42 project.

This is an **extended** version that I develop and maintain to support my future projects.

### Content

| Category | Description |
|----------|-------------|
| **Mandatory** | Base functions from libft project |
| **Bonus** | Linked list manipulation |
| **Extras** | Personal additions (`ft_isspace`, etc.) |

---

## Structure

```
libft/
├── includes/
│   └── libft.h
├── src/
│   └── *.c
├── Makefile
└── README.md
```

---

## Compilation

```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove everything
make re     # Rebuild
```

---

## Usage

```c
#include "libft.h"
```

```bash
cc main.c -L. -lft -I includes
```

---

## Warning

> [!CAUTION]
> **If you are a 42 student:**
> - **Do not copy** this code
> - Take time to **understand** each function
> - **Write your own code**
>
> The purpose of the libft project is to learn. Copying deprives you of this learning and you will be stuck on future projects.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
