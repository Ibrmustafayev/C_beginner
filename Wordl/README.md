<div align="center">

# 🟩 Wordl

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-Strings%20%7C%20Arrays%20%7C%20ANSI%20Colors-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A terminal-based Wordle clone written in C.*

</div>

---

## 📌 Overview

Wordl is a command-line recreation of the popular Wordle game. A random 5-letter word is selected from a built-in list of 100 words. Guess it letter by letter — the game highlights correct letters in green, misplaced letters in yellow, and reveals confirmed letters in the display bar as you go.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Random Word** | Picks a random 5-letter target from a 100-word list on each run |
| 2 | **Color Feedback** | 🟩 Green = correct position, 🟨 Yellow = wrong position, white = not in word |
| 3 | **Revealed Letters** | Confirmed letters fill into the display bar (`[ a _ _ l e ]`) |
| 4 | **Input Validation** | Rejects any guess that isn't exactly 5 characters |
| 5 | **Case-Insensitive** | Uppercase input is automatically lowercased before checking |

---

## 🧠 Concepts Used

- `rand` / `srand` / `time` — seeded random word selection
- String comparison — `strcmp`, `strlen`, `tolower` via `ctype.h`
- Two-pass letter matching — exact matches first, then misplaced (prevents double-counting)
- ANSI escape codes — `\033[0;32m` (green), `\033[0;33m` (yellow), `\033[0m` (reset) for colored output
- Integer status arrays — `guess_status[]` and `target_used[]` to track match state per letter

---

## 🖥️ Example Output

```
[ _____ ]
> crane

[ c r a n e ]   (r = yellow, a = green)

[ __a__ ]
> trace

[ t r a c e ]   (a = green, e = green)

[ __ace ]
> grace

!!!WIN!!!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler. ANSI color codes require a color-supporting terminal (Linux/macOS Terminal, Windows Terminal).

```bash
# Compile
gcc Wordl.c -o Wordl

# Run (Linux / macOS)
./Wordl

# Run (Windows)
Wordl.exe
```

---

## 📁 Structure

```
Wordl/
├── Wordl.c    # Single-file game
└── README.md
```

---

## ⚠️ Limitations

- No guess limit — you can guess indefinitely until correct
- Word list is hardcoded — 100 words only
- ANSI colors may not display on older Windows terminals (use Windows Terminal or WSL)

---

## 📜 License

Released under the [MIT License](../LICENSE).
