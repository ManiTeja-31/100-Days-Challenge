> [139. Word Break] - https://leetcode.com/problems/word-break/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp/Trie
--------------------------------------------------------------------------------------------------------------------------------------
## 🪜 Step 1: Pure Recursion (Brute Force)

### **Idea**

Try every possible prefix of the string and recursively check if the remaining substring can also be segmented using dictionary words.

---

### **Steps**

1. Base case: If `s` is empty → return `true`.
2. For every prefix `s[0...i]`:

   * If it exists in the dictionary and the remaining substring `s[i:]` can also be segmented → return `true`.
3. If no valid segmentation is found → return `false`.

---

### **Complexity**

| Measure | Value                  |
| ------- | ---------------------- |
| Time    | Exponential — O(2ⁿ)    |
| Space   | O(n) (recursion depth) |

✅ Simple recursive intuition
❌ Highly inefficient due to repeated recomputation

---

## 🪜 Step 2: Recursion + Memoization (Top-Down DP)

### **Idea**

Same recursive logic, but **cache** results for each starting index to avoid recomputation.

---

### **Steps**

1. Use a helper `canBreak(start)` that checks if substring `s[start:]` can be segmented.
2. Memoize results in an array/vector:

   * `-1` = unvisited
   * `0` = false
   * `1` = true
3. For each index `start`, try extending to every `end`:

   * If `s[start:end]` is in the dictionary and `canBreak(end)` is true → return true.
4. Store result in memo before returning.

---

### **Complexity**

| Measure | Value                               |
| ------- | ----------------------------------- |
| Time    | O(n²) (each substring checked once) |
| Space   | O(n) (recursion + memo)             |

✅ Much faster than brute force
✅ Avoids redundant checks
⚠️ Still recursive, may hit stack limits for very large input

---

## 🪜 Step 3: Bottom-Up Dynamic Programming

### **Idea**

Iteratively build up the solution using a boolean DP array,
where `dp[i]` means:
→ *the substring `s[0..i-1]` can be segmented into words in the dictionary.*

---

### **Steps**

1. Initialize `dp[0] = true` (empty string can always be segmented).
2. For each `i` from 1 → n:

   * Check every partition `j` (0 ≤ j < i):

     * If `dp[j]` is true and `s[j..i-1]` is in dictionary → set `dp[i] = true`.
3. The result is stored in `dp[n]`.

---

### **Complexity**

| Measure | Value |
| ------- | ----- |
| Time    | O(n²) |
| Space   | O(n)  |

✅ Iterative and easy to trace
✅ Optimal time complexity for most cases
⚠️ Checking substrings repeatedly may cause slight overhead

---

## 🪜 Step 4: Trie + DP Approach

### **Idea**

Instead of repeatedly searching the dictionary,
store all words in a **Trie** for faster prefix-based lookups,
and use dynamic programming to track reachable positions.

---

### **Steps**

1. Build a Trie from all words in the dictionary.
2. Use `dp[i]` = true if substring `s[0..i-1]` can be segmented.
3. For every `i` where `dp[i]` is true:

   * Traverse the Trie starting from `s[i]` to extend valid words.
   * Whenever a complete word ends in the Trie, mark `dp[j+1] = true`.
4. The final answer is `dp[n]`.

---

### **Complexity**

| Measure | Value                              |
| ------- | ---------------------------------- |
| Time    | O(n × L) (L = average word length) |
| Space   | O(total characters in Trie)        |

✅ Efficient lookups using Trie structure
✅ Avoids repetitive substring checks
✅ Great for large dictionaries
⚠️ Slightly more complex implementation

---

## 🧾 Final Comparison

| Approach               | Technique           | Time   | Space            | Notes                        |
| ---------------------- | ------------------- | ------ | ---------------- | ---------------------------- |
| **Pure Recursion**     | Try all partitions  | O(2ⁿ)  | O(n)             | Easiest but slowest          |
| **Memoized Recursion** | Top-down DP         | O(n²)  | O(n)             | Optimal recursive solution   |
| **Bottom-Up DP**       | Iterative DP        | O(n²)  | O(n)             | Most common and clean        |
| **Trie + DP**          | Trie + prefix check | O(n×L) | O(n + Trie size) | Fastest with large word sets |

---

## 💡 Key Takeaways

* All solutions rely on **checking valid prefixes** and recursively or iteratively validating the suffix.
* **Memoization** and **DP** eliminate redundant computations.
* **Trie-based optimization** speeds up prefix search when the dictionary is large.
* The **Bottom-Up DP** version is most widely used in interviews for its balance between simplicity and efficiency.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2707. Extra Characters in a String - https://leetcode.com/problems/extra-characters-in-a-string/description/
745. Prefix and Suffix Search - https://leetcode.com/problems/prefix-and-suffix-search/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Sentence tokenization, auto-complete acceptance