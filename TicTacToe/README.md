<div align="center">

# ⭕ Tic Tac Toe ❌

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-2D%20Arrays%20%7C%20Game%20Logic%20%7C%20Input%20Validation-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A two-player terminal Tic Tac Toe game written in C.*

</div>

---

## 📌 Overview

Tic Tac Toe is a classic two-player game played on a 3×3 grid. Players enter their names, then take turns placing `x` and `o` by entering coordinates. The game detects wins across rows, columns, and diagonals, and handles ties automatically.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Two Players** | Custom names for Player 1 (`x`) and Player 2 (`o`) |
| 2 | **Coordinate Input** | Players enter row and column as `y x` (e.g. `2 2` for center) |
| 3 | **Win Detection** | Checks all rows, columns, and both diagonals after every move |
| 4 | **Tie Detection** | Automatically declares a tie if all 9 squares are filled with no winner |
| 5 | **Input Validation** | Rejects out-of-bounds coordinates and already-taken spots |

---

## 🧠 Concepts Used

- 2D array — `board[3][3]` of `char` initialized with spaces
- `win()` — row, column, and diagonal checks using index-based comparisons
- `turn % 2` — alternates between Player 1 and Player 2 each round
- `fgets` / `strcspn` — safe name input with newline stripping
- `const char board[3][3]` — read-only board passed to display and win-check functions

---

## 🖥️ Example Output

```
Welcome to Tic Tac Toe!!!

Enter a name for 'Player 1': Alice
Enter a name for 'Player 2': Bob

 x | o | x 
___|___|___
 o | x | o 
___|___|___
 x |   |   
   |   |   

!!!WIN!!! Player 1 won!
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler

```bash
# Compile
gcc TicTacToe.c -o TicTacToe

# Run (Linux / macOS)
./TicTacToe

# Run (Windows)
TicTacToe.exe
```

---

## 📁 Structure

```
TicTacToe/
├── TicTacToe.c    # Single-file game
└── README.md
```

---

## ⚠️ Limitations

- Two players only — no AI opponent
- No replay option — restart the program to play again

---

## 📜 License

Released under the [MIT License](../LICENSE).
