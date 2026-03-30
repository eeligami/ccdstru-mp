# **RIPPLE: A CHAIN REACTION GAME**

## Getting Started
### Requirements
+ GCC (or any C compiler)
+ A terminal

### Compile and Run
```bash
gcc ccdstru_mp.c -o ripple
./ripple
```

## What is Ripple?
### Gameplay
Two players, R (Red) and B (Blue), battle for control of a 3×3 grid.\
Place your pieces, then unleash them to capture your opponent's territory in a chain reaction.\
One move can flip the whole board, so think before you expand!

### How to play?
#### First Phase
Each player places one piece on any empty cell. R goes first, then B. Once both players have placed their first piece, the game moves to the main phase.
+ Enter your move as: `row column` (space-separated)
+ Rows and columns are numbered 0 to 2

##### Game Board
```
    0   1   2
  +---+---+---+
0 | . | . | . |
  +---+---+---+
1 | . | . | . |
  +---+---+---+
2 | . | . | . |
  +---+---+---+
```

#### Second Phase
After both players have placed their starting piece, turns alternate between **R** and **B**.\
On your turn, you **must select one of your own pieces** on the board to activate it.

When you activate a piece, it either:
1. **Gets marked** (first activation  nothing visible happens yet), or
2. **Triggers a chain reaction** (second activation on the same cell)
      
#### Chain Reaction
When a piece triggers a chain reaction via `Expand`, here's what goes down:
1. The activated piece is removed from its cell.
2. Depending on whose turn it is:
   + **R** spreads **up** (row - 1), **left** (col - 1), and **right** (col + 1)
   + **B** spreads **down** (row + 1), **left** (col - 1), and **right** (col + 1)
3. **Each neighboring cell gets replaced**: your color takes over, and if the opponent was there, they're gone.
4. If a replaced cell has already been activated before, it can chain again, cascading reactions across the board!

#### End Conditions
| **Condition** | **Description** |
| :--- | :--- |
| F = 3 | Only 3 empty cells remain on the board |
| val >= 20 | 20 turns have been played |
| Wipeout | One player has no pieces left (after setup) |

#### Win Scenarios
| **Result** | **Condition** |
| :--- | :--- |
| R Wins | R pieces > B pieces |
| B Wins | B pieces > R pieces |
| Draw | R pieces == B pieces |
