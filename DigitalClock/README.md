<div align="center">

# 🕐 Digital Clock

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-Loops%20%7C%20System%20Calls%20%7C%20Time-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A real-time digital clock running in the terminal, written in C.*

</div>

---

## 📌 Overview

Digital Clock displays a continuously updating HH : MM : SS clock in the terminal. It counts seconds, rolls over minutes and hours, and resets at midnight — all in an infinite loop with a 1-second delay between ticks.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Live Display** | Updates every second in-place by clearing the terminal |
| 2 | **Rollover Logic** | Seconds → minutes → hours, resets to 00:00:00 at 24:00:00 |
| 3 | **Flush Output** | `fflush(stdout)` ensures the display updates immediately |

---

## 🧠 Concepts Used

- `sleep(1)` — 1-second delay between ticks via `unistd.h`
- `system("cls")` — clears the terminal each tick for in-place updating
- `fflush(stdout)` — forces buffered output to display immediately
- Manual time tracking — hour/minute/second counters with rollover conditions

---

## 🖥️ Example Output

```
 9 : 41 : 35
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler. Designed for Windows (`system("cls")`).

```bash
# Compile
gcc DigitalClock.c -o DigitalClock

# Run (Windows)
DigitalClock.exe
```

> **Note:** On Linux/macOS, replace `system("cls")` with `system("clear")` before compiling.

---

## 📁 Structure

```
DigitalClock/
├── DigitalClock.c    # Single-file clock
└── README.md
```

---

## ⚠️ Limitations

- Does **not** read the system time — starts from `00:00:00` on every run
- Uses `system("cls")` which is Windows-specific

---

## 📜 License

Released under the [MIT License](../LICENSE).
