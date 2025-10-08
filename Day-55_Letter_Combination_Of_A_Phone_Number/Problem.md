> [Letter Combinations of a Phone Number] - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking + Map Lookup
--------------------------------------------------------------------------------------------------------------------------------------
## 🔠 Digit to Letters Mapping

| Digit | Letters    |
| ----- | ---------- |
| 2     | a, b, c    |
| 3     | d, e, f    |
| 4     | g, h, i    |
| 5     | j, k, l    |
| 6     | m, n, o    |
| 7     | p, q, r, s |
| 8     | t, u, v    |
| 9     | w, x, y, z |

---

## ✅ Approach 1: Backtracking (DFS) + Map Lookup

### 🔍 Intuition:

* This is a classic **combinatorial search** problem.
* Use **backtracking** to explore all combinations character by character.

### 🧠 Steps:

1. Start with an empty string.
2. At each recursion level, pick the current digit and try all its letter mappings.
3. Append a letter, recurse to the next digit.
4. When the length of the current string equals the input length, add to results.

### 🔧 Implementation Details:

* Map digits to letters using either `map<char, vector<char>>` or `unordered_map<char, string>`.
* Backtrack once all digits are processed.

### ⏱️ Time Complexity:

* **O(4^n)** in the worst case (as 7 and 9 have 4 letters), where `n = digits.length()`

### 🗂️ Space Complexity:

* **O(n)** recursion stack depth + result storage

---

## ✅ Approach 2: Iterative (BFS using Queue)

### 🔍 Intuition:

* Instead of recursion, simulate level-by-level construction using a **queue**.
* Each level corresponds to a digit in the input string.

### 🧠 Steps:

1. Start with a queue containing `""`.
2. For each digit:

   * Dequeue all current combinations.
   * Append every possible character for the digit and enqueue the new string.

### ⏱️ Time Complexity:

* **O(4^n)** similar to backtracking

### 🗂️ Space Complexity:

* **O(4^n)** due to the result set being stored in the queue

---

## 🔄 Comparison of All Approaches

| Approach           | Time Complexity | Space Complexity | Characteristics                          |
| ------------------ | --------------- | ---------------- | ---------------------------------------- |
| Backtracking (Map) | O(4^n)          | O(n)             | Clean recursive DFS, easy to implement   |
| Backtracking (Alt) | O(4^n)          | O(n)             | Uses unordered_map for constant lookup   |
| Iterative (BFS)    | O(4^n)          | O(4^n)           | Level-wise, queue-based, iterative style |

---

## 💡 Notes for Interviews

* Emphasize **recursive decision tree** building.
* Highlight pruning is not required since all combinations are valid.
* Iterative version shows BFS style thinking — great for system design scenarios.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2266. Count Number of Texts - https://leetcode.com/problems/count-number-of-texts/description/
3016. Minimum Number of Pushes to Type Word II - https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Predictive text, keypad combinations