> [Number Of Islands] - https://leetcode.com/problems/number-of-islands/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> BFS/DFS
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ Approach 1: DFS (Recursive)

### 🔍 Idea:

* Traverse the grid.
* When a `'1'` is found, increment the island count.
* Use **DFS** to mark all connected `'1'`s (land) as `'0'` (visited).

### 🧠 Steps:

1. Loop through each cell.
2. When a `'1'` is found, call DFS and mark all reachable land as `'0'`.
3. Increment count for each DFS call.

### 🔧 Notes:

* Use a direction array for 4-way movement.
* Modifies the original grid.

### ⏱️ Time Complexity:

* `O(m * n)` — Every cell is visited once.

### 🗂️ Space Complexity:

* `O(m * n)` in worst case due to recursion stack.

---

## ✅ Approach 2: DFS with Visited Matrix

### 🔍 Difference:

* Keeps original grid intact.
* Uses a `visited[][]` array to track explored cells.

### 🔧 Notes:

* Useful when you **can't modify** the input grid.
* Functionally the same as approach 1, just with extra space.

### ⏱️ Space:

* Extra space for `visited[m][n]`.

---

## ✅ Approach 3: DFS (Iterative using Stack)

### 🔍 Idea:

* Use **explicit stack** to simulate recursion.
* Prevents stack overflow on large inputs.

### 🧠 Steps:

1. Loop through grid.
2. On `'1'`, push to stack and process connected lands.
3. Mark each visited cell as `'0'`.

---

## ✅ Approach 4: BFS (Queue)

### 🔍 Idea:

* Use a **queue** to perform level-order traversal of land.
* Similar to DFS, but processes neighbors breadth-first.

### 🧠 Steps:

1. For each `'1'`, enqueue it.
2. While queue isn't empty, dequeue and explore neighbors.
3. Mark visited cells as `'0'`.

---

## ✅ Approach 5: Union-Find (Disjoint Set)

### 🔍 Idea:

* Treat each `'1'` as a separate set.
* Union connected lands (right & down only to avoid repeats).
* The number of **unique parents** = number of islands.

### 🧠 Steps:

1. Assign a unique ID to every `'1'` as its own parent.
2. Traverse grid, and union adjacent land cells.
3. After unions, count the number of unique roots.

### 🔧 Notes:

* Efficient for dynamic island connectivity problems.
* Preserves input grid.

### ⏱️ Time Complexity:

* `O(m * n * α(n))` — `α` is the inverse Ackermann function (very slow-growing).

### 🗂️ Space Complexity:

* `O(m * n)` for parent array.

---

## 🔄 Summary of Approaches

| Approach         | Time Complexity | Space Complexity | Modifies Grid | Notes                           |
| ---------------- | --------------- | ---------------- | ------------- | ------------------------------- |
| DFS Recursive    | O(m×n)          | O(m×n) (stack)   | ✅ Yes         | Simple and clean                |
| DFS with Visited | O(m×n)          | O(m×n)           | ❌ No          | Preserves grid                  |
| DFS Iterative    | O(m×n)          | O(m×n)           | ✅ Yes         | Avoids recursion limits         |
| BFS (Queue)      | O(m×n)          | O(m×n)           | ✅ Yes         | Good for shortest path variants |
| Union-Find       | O(m×n × α(n))   | O(m×n)           | ❌ No          | Best for dynamic connectivity   |

---

**Explanation:**

* Island 1: Top-left 2×2 block
* Island 2: Single land at (2,2)
* Island 3: Two lands at bottom right

---

## 📝 Notes for Interviews

* Understand the difference between DFS, BFS, and Union-Find.
* Union-Find is great if asked to **merge** islands dynamically.
* DFS/BFS is easier to implement when input is small or one-time processing.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
695. Max Area of Island - https://leetcode.com/problems/max-area-of-island/description/
419. Battleships in a Board - https://leetcode.com/problems/battleships-in-a-board/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Image recognition, land-mass detection in satellite data. 