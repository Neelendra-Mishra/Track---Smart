# 📊 Track Smart

## 📌 Project Overview

This C-based terminal application simulates a simple spreadsheet system to help manage student grades.
It reads a structured file containing grade data, performs calculations, allows sorting and editing, and provides visual outputs like histograms.
It is designed to replicate basic spreadsheet functionality, such as what you might find in a simplified version of Excel.

---

## 📁 Project Structure

- `spreadsheet.c` — Main program containing the menu and app control flow.
- `data.c` — Handles reading/parsing of the input file.
- `ordering.c` — Contains sorting functions based on different fields.
- `calc.c` — Performs grade calculations, histogram generation, and record updates.
- `*.h` — Header files for modular design and function declarations.
- `students.txt` — Input data file that must exist before execution.

---

## 🔧 Features (Menu Options)

| Option | Description              |
|--------|--------------------------|
| 1      | Display Spreadsheet      |
| 2      | Display Histogram        |
| 3      | Set Sort Column          |
| 4      | Update Last Name         |
| 5      | Update Exam Grade        |
| 6      | Update Grade Mapping     |
| 7      | Delete Student           |
| 8      | Exit                     |

---

## 🧱 Programming Concepts Used

- **Structs & Dynamic Memory Allocation**
- **Modular Programming** (with multiple `.c` and `.h` files)
- **File I/O** using 
- **Sorting Algorithms** 
- **Input Validation** for user entries
- **Console Output Formatting** (aligned columns, headers, ASCII histogram)

---

## 📊 Sample Outputs

The program:
- Reads and displays a formatted spreadsheet from `students.txt` (**Note:** The file is expected to already exist. It is not created or written by the program.)
- Shows calculated total grades and letter grades
- Responds interactively to user input
- Reflects updated data immediately in displays and histograms

---

## 🛠 Technologies

- **Language**: C
- **Compiler**: GCC
- **Environment**: VS Code (with GCC), Docker
- **Tools**: Valgrind (for memory leak checks), GDB (for debugging)

