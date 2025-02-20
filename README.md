# get_next_line

A 42 Amman project that involves creating a function to read content line by line from a file descriptor.

## Description

`get_next_line` is a function that returns a line read from a file descriptor. When called in a loop, the function reads the text file pointed to by the file descriptor one line at a time until the end of the file.

## Features

- Read from file descriptor line by line
- Handle multiple file descriptors
- Memory efficient with proper allocation and deallocation
- Support for both static and dynamic buffer sizes

## Usage

```c
#include "get_next_line.h"

char *line;
int fd = open("example.txt", O_RDONLY);

while ((line = get_next_line(fd)) != NULL)
{
    // Process the line
    free(line);
}
close(fd);
```

## Function Prototype

```c
char *get_next_line(int fd);
```

## Return Values

- Returns the line that was read (including the terminating `\n` character)
- Returns NULL if there is nothing else to read or if an error occurred

## Compilation

The project includes a Makefile with the following rules:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild the project
```

You can also compile manually:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line.c src/get_next_line_utils.c -I include
```

## Testing

You can test the function with different buffer sizes by modifying the BUFFER_SIZE macro:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 src/get_next_line.c src/get_next_line_utils.c -I include
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line.c src/get_next_line_utils.c -I include
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 src/get_next_line.c src/get_next_line_utils.c -I include
```

## Project Structure

```
.
├── Makefile
├── src/
│   ├── get_next_line.c
│   └── get_next_line_utils.c
└── include/
    └── get_next_line.h
```

## Author

- **Hamza Almuhisen** - *42 Amman Student*
  - GitHub: [@hamzah1432](https://github.com/hamzah1432)
  - 42 Intra: [halmuhis](https://profile.intra.42.fr/)

## License

This project is part of 42 Amman cursus. For detailed information about the license, please refer to the 42 Amman guidelines.
