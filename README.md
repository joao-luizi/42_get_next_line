# get_next_line

## Summary
The goal of this project is to implement a function that reads one line at a time from a file descriptor. It introduces the use of **static variables** in C and emphasizes careful memory management and buffer control.

---

## Table of Contents

- [Project Goals](#project-goals)
- [Features](#features)
- [Learning Highlights](#learning-highlights)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Compilation](#compilation)
- [Bonus](#bonus)
- [License](#license)

---

## Project Goals

- Create a function:  
```c
  char *get_next_line(int fd);
```
- The function should return:
  - One line per call, including the newline (\n) if present
  - NULL when EOF is reached or on error
- It must handle:
  - Arbitrary buffer sizes via the BUFFER_SIZE macro
  - File descriptors from regular files and standard input
 
## Features
|Requirement	          |Description                              |
|-----------------------|-----------------------------------------|
|✅ Static variable	    |Persistent data across function calls    |
|✅ Norm-compliant	    |Fully adheres to 42's C Norm             |
|✅ No memory leaks	    |All allocated memory is properly freed   |
|✅ No global variables	|Uses local static data only              |
|✅ No lseek()	        |File pointer must not be reset manually  |
|✅ Works with stdin	  |Supports both files and standard input   |
|✅ Bonus: multi-FD	    |Manages multiple FDs simultaneously      |

## Learning Highlights
- Understood and used static variables for memory persistence
- Handled buffer slicing and string joins with precision
- Explored file descriptors, including edge cases like stdin
- Implemented multi-FD state handling (bonus)

## File Structure
```cpp
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils_bonus.c
```
## Usage
```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Compilation
### Mandatory
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
### Bonus
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```
Replace 42 with any buffer size to test behavior.

### Bonus
The bonus implementation supports:
- Reading from multiple file descriptors at once
- Preserving reading context for each FD using only one static variable

## Example usage:
```c
char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
```
You can alternate between FDs without interfering with others.

### License
This project is licensed under the [MIT License](LICENSE).
