<div align="center">

# 🃏 Card Dealer

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Concepts](https://img.shields.io/badge/Concepts-Structs%20%7C%20Arrays%20%7C%20Randomization-informational?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

*A console-based card dealer written in C that shuffles a full deck and deals a hand.*

</div>

---

## 📌 Overview

Card Dealer simulates a standard 52-card deck. It builds the full deck, shuffles it using the Fisher-Yates algorithm, deals however many cards you ask for, and displays your hand along with its total value.

---

## ✨ Features

| # | Feature | Description |
|---|---|---|
| 1 | **Full Deck** | Generates all 52 cards with correct suits and values |
| 2 | **Shuffle** | Randomizes the deck using Fisher-Yates shuffle |
| 3 | **Deal** | Deals any number of cards between 1 and 52 |
| 4 | **Hand Value** | Calculates and displays the total value of your hand |

---

## 🧠 Concepts Used

- `struct` — custom `Card` type grouping suit name and value
- `srand` / `rand` — seeded randomization via `time.h`
- `snprintf` — safe string formatting for card names
- Fisher-Yates shuffle — unbiased in-place deck randomization
- Variable-length arrays — `deal_cards[deal_count]` sized at runtime

---

## 🖥️ Example Output

```
How many cards to deal? 5

Your hand:
  King of Spades
  3 of Hearts
  Ace of Diamonds
  7 of Clubs
  10 of Spades

Hand value: 41
```

---

## 🔧 How to Compile & Run

**Requirements:** GCC or any C99-compatible compiler

```bash
# Compile
gcc CardDealer.c -o CardDealer

# Run (Linux / macOS)
./CardDealer

# Run (Windows)
CardDealer.exe
```

---

## 📁 Structure

```
CardDealer/
├── CardDealer.c   # Single-file application
└── README.md
```

---

## ⚠️ Limitations

- Ace is always valued at **11** (no dynamic Ace handling)
- Data is **not saved** between runs
- No game logic yet — purely a dealer and hand evaluator

---

## 📜 License

Released under the [MIT License](../LICENSE).
