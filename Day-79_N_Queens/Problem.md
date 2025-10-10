> [N Queens] - https://leetcode.com/problems/n-queens/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking + Pruning
--------------------------------------------------------------------------------------------------------------------------------------

## ✅ 1. Naive Backtracking

### 🔍 How It Works (Step-by-Step)

1. Start from the top row (`row = 0`) and try placing a queen in each column.
2. For each cell `(row, col)`, check if it's safe:

   * No queen in the same **column**.
   * No queen in the **left diagonal**.
   * No queen in the **right diagonal**.
3. If it's safe, place a queen (`'Q'`) and move to the next row (`row + 1`).
4. If all rows are filled (`row == n`), save the board as a valid solution.
5. Backtrack: Remove the queen and try the next column.

### ✅ Time Complexity

* Worst case: `O(N!)`
* Each queen has `N` choices initially, but they reduce as placement constraints increase.

### ✅ Space Complexity

* `O(N^2)` for storing the board.
* `O(N)` recursion stack depth.

---

## 🧮 2. Optimized Backtracking Using Hash Arrays

### 🔍 How It Works (Step-by-Step)

1. Instead of checking the board repeatedly, use **hash arrays** to track whether a queen exists in:

   * A **column** (`cols[col]`)
   * A **left-to-right diagonal** (`diag1[row + col]`)
   * A **right-to-left diagonal** (`diag2[row - col + n - 1]`)
2. Before placing a queen, check these arrays instead of looping.
3. This avoids `O(N)` scans in `isSafe()` and reduces it to `O(1)`.

### ✅ Time Complexity

* Still `O(N!)`, but with faster checks: reduced constant factor.

### ✅ Space Complexity

* `O(N)` for hash arrays + `O(N^2)` for the board.

---

## ⚡ 3. Bit Manipulation Approach (Highly Optimized)

### 🔍 How It Works (Step-by-Step)

1. Use integers as **bit masks** to represent:

   * **Occupied columns**
   * **Diagonals**: Left (`diag1`) and right (`diag2`)
2. `available = ~(cols | diag1 | diag2) & ((1 << n) - 1)` gives all valid positions in current row.
3. Pick the **rightmost available bit**, place queen, and recurse.
4. Shift diagonals:

   * Left diag: `diag1 << 1`
   * Right diag: `diag2 >> 1`
5. Use backtracking and **bit clearing** to remove placed queens.

### ✅ Time Complexity

* `O(N!)` in terms of placements, but bitmasking offers huge speedup (up to `~10x` over naive for large `N`).

### ✅ Space Complexity

* `O(N)` for recursion + position vector.

---

## 🆚 Summary Table

| Approach                   | Time Complexity | Space Complexity | Key Optimizations                     |
| -------------------------- | --------------- | ---------------- | ------------------------------------- |
| Naive Backtracking         | `O(N!)`         | `O(N^2)`         | Simple recursive + safety checks      |
| Optimized with Hash Arrays | `O(N!)`         | `O(N^2)`         | `O(1)` safety checks using arrays     |
| Bit Manipulation           | `O(N!)`         | `O(N)`           | Bitmasking: faster & compact tracking |

---

## 📌 Notes for Interviews

* Always mention optimizations using **hashing or bitmasking** if time is tight.
* Start from naive for clarity, and **progress to optimized** for demonstrating growth.
* For real systems or large boards (e.g., `n > 12`), use bitmasking or constraint programming.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
37. Sudoku Solver - https://leetcode.com/problems/sudoku-solver/description/
52. N-Queens II - https://leetcode.com/problems/n-queens-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Scheduling problems, constraint satisfaction systems. 