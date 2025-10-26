> [472. Concatenated Words] - https://leetcode.com/problems/concatenated-words/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Trie + DFS + Memoization
--------------------------------------------------------------------------------------------------------------------------------------
## 🧩 Intuition

This is a variation of the **Word Break** problem.
We need to check whether each word can be broken down into smaller valid words present in the dictionary.

---

## 🪜 Step 1: Brute Force / Word Break (Dynamic Programming)

### **Idea**

For every word:

1. Temporarily remove it from the dictionary to avoid using itself.
2. Check if it can be formed by concatenating smaller words from the dictionary using **Word Break DP**.

---

### **Word Break Logic**

* Let `dp[i] = true` if substring `word[0...i-1]` can be formed.
* For each position `i`, check all previous positions `j < i`:

  * If `dp[j] == true` and `word[j...i-1]` exists in the dictionary → mark `dp[i] = true`.

If `dp[n]` is true (where `n` = word length), the word is concatenated.

---

### **Complexity**

| Measure | Value     |
| ------- | --------- |
| Time    | O(N × L²) |
| Space   | O(L)      |

✅ Easy to understand
❌ Recomputes results for many smaller words multiple times

---

## 🪜 Step 2: DP + Sort by Word Length (Optimized)

### **Idea**

We can reduce redundant work by sorting words **by increasing length**.
Then, build up the dictionary **gradually**:

* Shorter words are processed first.
* Longer words can reuse previously seen smaller ones.

---

### **Steps**

1. Sort all words by length.
2. Keep a running dictionary of smaller words.
3. For each word:

   * Try to form it using known smaller words (via DP).
   * If it can be formed → add to result.
   * Otherwise → add to dictionary for future words.

---

### **Why This Works**

Because a concatenated word can only be built from **shorter words**, sorting ensures that when we test a word, all possible components already exist in the dictionary.

---

### **Complexity**

| Measure  | Value          |
| -------- | -------------- |
| Sorting  | O(N log N)     |
| DP Check | O(L²) per word |
| Total    | O(N × L²)      |
| Space    | O(L)           |

✅ Efficient for large input lists
✅ Avoids re-checking unnecessary long words
✅ Commonly used in interviews

---

## 🪜 Step 3: Trie + DFS (Highly Optimized)

### **Idea**

Use a **Trie** (prefix tree) to efficiently check if a word can be built by combining smaller words.

---

### **Steps**

1. Sort words by length (smallest → largest).
2. For each word:

   * Check if it can be formed by traversing the Trie recursively.
   * If yes → add it to result.
   * If not → insert it into the Trie.

---

### **How the Trie Helps**

* Allows quick prefix checking without rebuilding substrings.
* Reduces time spent on substring creation (`word.substr()` in DP).
* Supports recursion efficiently for prefix-based word checking.

---

### **DFS Logic**

* Start from index `0` of the word.
* Move along the Trie matching characters.
* If you hit a valid word end:

  * Recursively check the **remaining suffix** of the word.
* If you reach the end and have used **2 or more words**, return true.

---

### **Complexity**

| Measure     | Value         |
| ----------- | ------------- |
| Insert Word | O(L)          |
| Check Word  | O(L²) (worst) |
| Total       | O(N × L²)     |
| Space       | O(26 × N × L) |

✅ Fast prefix lookups
✅ Avoids substring slicing overhead
✅ Ideal for very large inputs
⚠️ More complex to implement

---

## 🧾 Final Comparison

| Approach                | Technique                      | Time      | Space         | Notes                  |
| ----------------------- | ------------------------------ | --------- | ------------- | ---------------------- |
| **Brute Force**         | Word Break DP                  | O(N × L²) | O(L)          | Simple, but repetitive |
| **DP + Sort by Length** | DP with incremental dictionary | O(N × L²) | O(L)          | Clean and efficient    |
| **Trie + DFS**          | Prefix tree + recursion        | O(N × L²) | O(26 × N × L) | Fastest, but complex   |

---

## 💡 Key Takeaways

* The **core** is a *Word Break* check for each word.
* Sorting by length allows **progressive dictionary building**.
* A **Trie** further improves performance using prefix matching.
* This problem tests **DP understanding**, **string manipulation**, and **data structure usage** (Trie).

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
139. Word Break - https://leetcode.com/problems/word-break/description/
140. Word Break II - https://leetcode.com/problems/word-break-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Dictionary validation, autocomplete, compound word detection.