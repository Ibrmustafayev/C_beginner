<div align="center">

# 🎓 Mini Student Database

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Arrays%20%7C%20Sorting-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A console-based student grade management system written in C.*

</div>

---

## 📌 Overview

Mini Student Database is a terminal program that lets you manage a small student records. You can add students with their grades, view the full list, sort by average, and instantly identify the strongest and weakest performer — all through a simple numbered menu.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Add Student** | Store a student's name and 3 grades |
| 2 | **Show All** | List every student with their grades |
| 3 | **Sort by Average** | Display students from highest to lowest average |
| 4 | **Strongest & Weakest** | Show the top and bottom student by average |

---

## 🧠 Concepts Used

- `struct` — custom data type to group student fields together
- `fgets` / `strcspn` — safe string input and newline stripping
- `find_average()` — grade average calculation using float division
- Selection sort — sorts an index array without moving structs in memory
- Pointer parameters — `*students`, `*averages`, `*indexes` passed by reference
- `is_sorted` flag — guards against accessing unsorted data in option 4

---

## 🖥️ Menu Preview

```
=== Menu ===
1. Add student
2. Show all students
3. Show sorted by average
4. Show strongest & weakest
5. Exit
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler

```bash
# Compile
gcc MiniStudentDB.c -o MiniStudentDB

# Run (Linux / macOS)
./MiniStudentDB

# Run (Windows)
MiniStudentDB.exe
```

---

## ⚠️ Limitations

- Maximum **30 students** can be stored (fixed-size array)
- Each student has exactly **3 grades**
- Option 4 requires running **Option 3 first** to sort the data
- Data is **not saved** between runs (no file I/O yet)

---

## 📜 License

Released under the [MIT License](../LICENSE).
