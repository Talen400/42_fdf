Of course! Here's the full `README.md` translated into **English**, keeping the structure and style consistent with the original:

---

# 📚 Libft Ultimate

A custom C library that combines three essential projects from the 42 curriculum: **Libft**, **Printf**, and **Get Next Line** — all in one place for easier development and code reuse.

> Maintained by **tlavared** – 42 São Paulo

---

## ✨ Features

### 🧱 Libft

* Reimplementation of several standard C library functions (`<string.h>`, `<ctype.h>`, etc.)
* String, memory, character, and number manipulation
* Support for linked list operations

### 🖨️ Ft\_Printf

* Custom implementation of the `printf` function
* Supports multiple format specifiers:

  * `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`

### 📄 Get Next Line (GNL)

* Reads a file line by line
* **Bonus version** supports multiple file descriptors
* Efficient buffer and memory handling

---

## 🏗️ Project Structure

```
📁 libft_ultimate/
├── 🧱 Libft Functions (e.g. ft_itoa.c, ft_strjoin.c, ...)
├── 🖨️ Ft_Printf (ft_printf.c, ft_printf.h, ft_print*.c)
├── 📄 Get Next Line Bonus (get_next_line_bonus.c/.h)
├── 📄 Headers (libft.h, ft_printf.h, get_next_line_bonus.h)
├── 🛠️ Makefile
└── 📄 README.md
```

---

## 🔧 How to Use

### 🛠️ Compilation

Compile the library using the `Makefile`:

```bash
make            # Compile all files and create libft.a
make clean      # Remove object files
make fclean     # Remove object files and libft.a
make re         # Recompile everything
```

### 🔗 Linking in Your Project

In your main C file:

```c
#include "libft.h"
```

And compile with:

```bash
gcc -Wall -Wextra -Werror your_program.c libft.a
```

Alternatively, you can compile source files directly, but using the static library is recommended.

---

## 🧪 Usage Examples

### `ft_printf`

```c
ft_printf("Number: %d\n", 42);
ft_printf("Hex: %x\n", 255);
```

### `get_next_line_bonus`

```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    ft_printf("%s", line);
    free(line);
}
close(fd);
```

### Libft Functions

```c
char *s = ft_strdup("Hello 42!");
ft_putendl_fd(s, 1);
free(s);
```

---

## 📌 Technical Highlights

* **Modular Code**: Each feature is in its own file
* **Safe Memory Management**: No memory leaks
* **Compatible**: Fully adheres to 42 project standards

---

## ⚙️ Implementations

### Libft (Partial List)

* `ft_strlen`, `ft_strncmp`, `ft_strdup`, `ft_substr`, `ft_strjoin`
* `ft_atoi`, `ft_calloc`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
* `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* Linked list functions: `ft_lstnew_bonus`, `ft_lstadd_front_bonus`, etc.

### `ft_printf`

* Supported conversions:

  * `c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, `%`
* Modular architecture:

  * Each format specifier is handled in its own file

### `get_next_line_bonus`

* Uses a linked list to support multiple file descriptors
* Reads files line-by-line, buffering as needed

---

## 🧩 Architecture Overview

* Each module (Libft, Printf, GNL) has its own header
* Utility functions are grouped by functionality
* `BUFFER_SIZE` can be set at compile time using `-D BUFFER_SIZE=...`

---

## 📊 Complexity

| Function          | Time     | Space                      |
| ----------------- | -------- | -------------------------- |
| `ft_strlen`       | O(n)     | O(1)                       |
| `ft_printf`       | O(n)     | O(n)                       |
| `get_next_line`   | O(n)     | O(BUFFER\_SIZE + line len) |
| Linked list (GNL) | O(k × n) | O(k)                       |

---

## 🧠 Potential Improvements

* Add automated test suite
* Extend `ft_printf` to support more specifiers (e.g., long double)
* Generate documentation with Doxygen

---

## 👤 Author

**tlavared**
42 São Paulo

---

*Made with 💻 and dedication at the heart of 42 SP.*
