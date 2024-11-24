# C++ Useful Tools

A lightweight collection of C++ utilities for gathering system information. This repository currently includes tools to fetch memory information and system process details.

---

## Overview

This repository provides two standalone C++ utilities:
1. **Get Memory Info (`get_memory_info.cpp`)**: Retrieves detailed information about system memory.
2. **Get Top Info (`get_top_info.cpp`)**: Mimics the functionality of the `top` command to display system and process-level information.

These tools demonstrate how to use system-level APIs in C++ to gather useful system data.

---

## Files

### 1. `get_memory_info.cpp`
- **Description**: Fetches memory details such as:
  - Total system memory
  - Used memory
  - Free memory
- **Usage**:
  ```bash
  g++ get_memory_info.cpp -o get_memory_info
  ./get_memory_info
  ```

### 2. `get_top_info.cpp`
- **Description**: Displays system and process information, including:
  - CPU usage
  - Memory usage by processes
  - Top running processes
- **Usage**:
  ```bash
  g++ get_top_info.cpp -o get_top_info
  ./get_top_info
  ```

---

## Build and Run Instructions

### Prerequisites
- A C++ compiler, such as `g++`.

### Steps to Build and Run:
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cpp-useful-tools.git
   cd cpp-useful-tools
   ```

2. Compile the desired tool:
   - For memory info:
     ```bash
     g++ get_memory_info.cpp -o get_memory_info
     ```
   - For top info:
     ```bash
     g++ get_top_info.cpp -o get_top_info
     ```

3. Run the tool:
   - For memory info:
     ```bash
     ./get_memory_info
     ```
   - For top info:
     ```bash
     ./get_top_info
     ```

---

## Example Output

### Memory Info (`get_memory_info`)
```plaintext
Total Memory: 8 GB
Used Memory: 4 GB
Free Memory: 4 GB
```

### Top Info (`get_top_info`)
```plaintext
PID    CPU%    MEM%    COMMAND
1234   15.2    10.3    my_process
5678   10.1    5.2     another_process
...
```

---

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute as needed.

---

## Contact

Feel free to reach out with questions, suggestions, or feedback:
- **Author:** Jayachandran Dharuman
- **GitHub:** [jdharuman](https://github.com/jdharuman)

---

Happy coding! 🎉
```

This single README includes:
- A concise overview of the tools.
- File descriptions and usage instructions.
- Build and run instructions.
- Example output for context.
- Licensing and contact details.
