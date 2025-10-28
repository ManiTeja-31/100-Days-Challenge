> [Minimum Window Substring] - https://leetcode.com/problems/minimum-window-substring/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Frequency match
--------------------------------------------------------------------------------------------------------------------------------------
## 🪜 Step 1: Brute Force Approach

### **Idea**

Try every possible substring of `s` and check if it contains all characters from `t`.
Keep track of the shortest valid window.

---

### **Steps**

1. Generate all substrings of `s` by fixing start (`i`) and end (`j`) indices.
2. For each substring `s[i…j]`, check if it contains all characters of `t`.
3. Update the smallest substring when a valid window is found.

---

### **How Checking Works**

Use a frequency count:

* For each character in the current window → increment its count.
* For each character in `t` → decrement count.
* If any count goes below zero, the window is invalid.

---

### **Complexity**

| Measure | Value                                               |
| ------- | --------------------------------------------------- |
| Time    | O(m² × n) (generating windows × checking all chars) |
| Space   | O(1) or O(128) (character frequency array)          |

✅ Simple and intuitive
❌ Extremely slow for large strings

---

## 🪜 Step 2: Optimized Sliding Window Approach

### **Idea**

Instead of checking every substring, use the **sliding window** technique:
Expand and shrink the window dynamically while keeping track of character frequencies.

---

### **Steps**

1. Create two frequency arrays:

   * `tMap`: frequency of each character in `t`.
   * `windowMap`: frequency of current window in `s`.
2. Move `right` pointer → expand window by including new characters.
3. Whenever the window satisfies all character frequencies (using `isValid()` check):

   * Try to shrink it from the left to minimize size.
4. Keep updating the smallest valid window.

---

### **How `isValid()` Works**

Compare frequency counts:
If for every character `c`, `windowMap[c] >= tMap[c]`, the window is valid.

---

### **Complexity**

| Measure | Value                                                         |
| ------- | ------------------------------------------------------------- |
| Time    | O(256 × m) ≈ O(m) (each window check iterates over all chars) |
| Space   | O(256)                                                        |

✅ Much faster than brute force
⚠️ Still not optimal — validity check takes extra time

---

## 🪜 Step 3: Fully Optimized Sliding Window (Efficient Validation)

### **Idea**

Avoid checking all 256 characters each time.
Use a **counter (`required`)** that tracks how many characters are still needed.

---

### **Steps**

1. Build `tMap` → store frequencies of all characters in `t`.
2. Use `windowMap` → track current window frequencies.
3. Use two pointers `left` and `right`:

   * Expand `right` → include new characters and decrease `required` count when a needed char is satisfied.
   * When `required == 0` → we have a valid window.
4. Shrink from `left` to find the smallest valid window while maintaining the constraint.
5. Update minimum window length and start index whenever a smaller valid substring is found.

---

### **Key Optimization**

* Instead of calling `isValid()` repeatedly, maintain `required` (number of chars still needed).
* Update it in **O(1)** time when adding/removing characters.

---

### **Complexity**

| Measure | Value                                      |
| ------- | ------------------------------------------ |
| Time    | O(m + n) (each pointer moves at most once) |
| Space   | O(128)                                     |

✅ Best possible solution
✅ Linear time complexity
✅ Widely used in interviews
⚡ Elegant sliding window pattern

---

## 🧾 Final Comparison

| Approach                       | Technique                                | Time       | Space  | Notes                         |
| ------------------------------ | ---------------------------------------- | ---------- | ------ | ----------------------------- |
| **Brute Force**                | Check all substrings                     | O(m² × n)  | O(128) | Very slow, just for intuition |
| **Sliding Window (Basic)**     | Expand–shrink with validity check        | O(256 × m) | O(256) | Improved but not optimal      |
| **Sliding Window (Optimized)** | Track counts dynamically with `required` | O(m + n)   | O(128) | Best approach for real use    |

---

## 💡 Key Insights

* The **sliding window** technique converts a brute-force substring search into a **linear-time** solution.
* Maintaining **character frequency counts** is crucial for handling duplicates.
* Tracking a **"required" counter** eliminates redundant validity checks.
* The **optimized sliding window** version is the one used in most competitive programming and interviews.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
430. Substring with Concatenation of All Words - https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
239. Sliding Window Maximum - https://leetcode.com/problems/sliding-window-maximum/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Minimal-length substring match (e.g., minimum DNA sequence with all genes)
