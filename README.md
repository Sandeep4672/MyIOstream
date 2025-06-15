# myiostream

A minimal, low-level custom C++ I/O stream library that mimics the behavior of `iostream`, including replacements for `cin` and `cout`.

## 🔧 What Is This?

`myiostream` is a custom-built C++ header and source implementation that defines:

- `myios`: A base class representing stream state and file descriptor.
- `myistream`: A class for console input (`>>` operator).
- `myostream`: A class for console output (`<<` operator).
- `myiostream`: A class combining both `myistream` and `myostream`, similar to `iostream`.

This library **bypasses the C++ Standard Library** and uses **direct Linux system calls** (`read` and `write`), giving complete control over I/O behavior.

---

## ✅ Features Implemented

- `myostream`:
  - Supports `<<` for:
    - `int`
    - `char`
    - `const char*`
- `myistream`:
  - Supports `>>` for:
    - `int`
    - `char*` (word-by-word)
- Low-level I/O using:
  - `write()` for output
  - `read()` for input
- Global objects:
  - `mycout` (stdout)
  - `mycin` (stdin)
- Minimal dependencies (`<unistd.h>`, `<cstdio>`, `<cstdlib>`)

---

## 🧭 Planned Enhancements

### 1. Buffering and Flushing
- Internal output buffer for efficient writes.
- `flush()` and `endl` manipulators.

### 2. Support for More Data Types
- `float`, `double`, `long`, `bool`, etc.
- Overloaded `<<` and `>>` operators for each.

### 3. Error and State Handling
- `failbit`, `eofbit`, and `badbit` flags.
- Member functions like `good()`, `fail()`, `eof()`.

### 4. Format Manipulators
- `endl`, `flush`, `setw`, `setprecision`.
- Hexadecimal and octal output using `hex`, `dec`, `oct`.

### 5. Namespacing
- Encapsulate everything inside a `myio` namespace.

### 6. Cross-Platform Support
- Abstract platform-specific I/O operations (Windows compatibility).

---

## 📁 File Structure
```plaintext
myiostream/
├── myiostream.h # Header file with class definitions
├── myiostream.cpp # Source file with object definitions
├── program1.cpp # Sample usage file


Compile with:
```bash

g++ myiostream.cpp program1.cpp -o myapp
