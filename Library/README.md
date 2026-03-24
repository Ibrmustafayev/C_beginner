<div align="center">

# 📖 Library Manager

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Strings%20%7C%20Sorting-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A console-based library management system written in C.*

</div>

---

## 📌 Overview

Library Manager is a terminal program that lets you manage a personal book collection. You can add books, search by title, sort by rating or year, and find your top-rated book — all through a simple numbered menu.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Add Book** | Store a book's title, author, year, and rating (1–5) |
| 2 | **Search by Title** | Look up a book by its exact title |
| 3 | **Display All** | List every book in the collection |
| 4 | **Sort by Rating** | Show books from highest to lowest rating |
| 5 | **Sort by Year** | Show books from newest to oldest |
| 6 | **Top Rated** | Display the single highest-rated book |

---

## 🧠 Concepts Used

- `struct` — custom data type to group book fields together
- `fgets` / `strcspn` — safe string input and newline stripping
- `strcmp` / `strcpy` — string comparison and copying
- Sorting via index arrays — avoids moving structs in memory
- Pointer parameters — `*book_count` passed by reference to `add_book`
- `stdbool.h` — boolean type for search found/not-found logic

---

## 🖥️ Menu Preview

```
=== Library Menu ===
1. Add book
2. Search book by title
3. Display all books
4. Display books sorted by rating
5. Display books sorted by year
6. Top rated book
7. Exit
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler

```bash
# Compile
gcc Library.c -o library

# Run (Linux / macOS)
./library

# Run (Windows)
library.exe
```

---

## ⚠️ Limitations

- Maximum **20 books** can be stored (fixed-size array)
- Search is **case-sensitive** — `"dune"` will not match `"Dune"`
- Data is **not saved** between runs (no file I/O yet)

---

## 📜 License

Released under the [MIT License](../LICENSE).
