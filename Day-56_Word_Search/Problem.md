> [Word Search] - https://leetcode.com/problems/word-search/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> DFS + Backtracking
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Approach: Backtracking with DFS + Visited Matrix

### **Step-by-Step Explanation**

1. **Start from every cell**:

   * For every cell `(i, j)` on the board, try to match the word starting from that cell using DFS.

2. **Depth-First Search (DFS)**:

   * At each step, check if the current character matches.
   * If yes, explore in 4 directions: **up, down, left, right**.

3. **Use a `visited` matrix**:

   * To ensure that a cell is not reused within the current path.
   * Mark the cell as visited before recursion and unmark (backtrack) after.

4. **Base case**:

   * If the current `index` equals the word's length → **entire word matched** → return `true`.

5. **Boundary & constraint checks**:

   * If out of bounds or the cell is already visited or the character doesn't match, return `false`.

6. **Backtracking**:

   * If a path does not lead to a solution, revert the visited mark and try other directions.

---

## 🔁 Directions Array (`dir`)

```cpp
vector<int> dir{0, 1, 0, -1, 0};
```

This compact array helps move in **4 directions**:

* `(row + dir[i], col + dir[i+1])` gives:

  * Right → Down → Left → Up

---

## ⏱️ Time & Space Complexity

### **Time Complexity: `O(M × N × 4^L)`**

* `M × N`: for every cell as the starting point
* `4^L`: each step has up to 4 choices (up, down, left, right)
* `L`: length of the word
* **Worst-case**: explores all 4 directions at each character

> ❗ Time can be optimized with early exits and pruning.

### **Space Complexity: `O(L)` (Recursion Depth) + `O(M×N)` (Visited)**

* Recursion stack up to length of the word
* `visited` matrix of same size as board

---

## ✅ Key Points

* Always sort input constraints: Check for **empty board or word** upfront.
* Backtracking ensures all paths are tried; visited ensures **no reuse**.
* Sorting the word or pre-pruning may help for optimization, especially when board size is large.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
212. Word Search II - https://leetcode.com/problems/word-search-ii/description/
980. Unique Paths III - https://leetcode.com/problems/unique-paths-iii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Search for patterns in grid/word puzzle, OCR