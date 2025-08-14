> [Longest substring Without repeating Characters] - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s, find the length of the longest substring without duplicate characters.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Hashmap
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* For each starting position, expand the substring until a repeated character is found.
* Track the maximum length seen.
---

### **Step-by-Step**
1. Loop `i` from `0` to `n-1`:
   * Create a `set` to store visited characters in the current substring.
   * Add characters one by one until a duplicate is found.
   * Update `maxLen` if needed.
2. Return `maxLen`.
---

### **Complexity**
* **Time:** O(n²) — For each start, we may check all following characters.
* **Space:** O(min(n, charset)) — Set to store unique characters.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### **Idea**
* Use a **sliding window** to keep track of the current substring without duplicates.
* Store the **last seen index** of each character in a hash map.
* Move the left pointer `l` only when a duplicate is found.
---

### **Step-by-Step**
1. Maintain two pointers `l` (left) and `r` (right).
2. Keep an `unordered_map<char, int>` storing **last index** where each character appeared.
3. For each character `s[r]`:
   * If it exists in map **and** `pos[s[r]] >= l`,
     → Move `l` to `pos[s[r]] + 1` to skip past the previous occurrence.
   * Update `pos[s[r]] = r`.
   * Update `maxLen = max(maxLen, r - l + 1)`.
4. Return `maxLen`.
---

### **Complexity**
* **Time:** O(n) — Each character visited at most twice (once by `r`, once by `l`).
* **Space:** O(min(n, charset)) — Map to store character positions.
---

## **Why `unordered_map` instead of `map`?**

* `map` → **Balanced BST** → Insertion/lookup = O(log n).
* `unordered_map` → **Hash Table** → Insertion/lookup = O(1) average case.
* Since we do **frequent lookups and updates** for characters,
  `unordered_map` makes the solution **O(n)** instead of **O(n log n)**.
* This is important for **large strings**, where the difference is significant.
---

## **Comparison Table**

| Approach                        | Time Complexity | Space Complexity   | Notes                                          |
| ------------------------------- | --------------- | ------------------ | ---------------------------------------------- |
| Brute Force                     | O(n²)           | O(min(n, charset)) | Simple but slow for large `n`                  |
| Sliding Window + map            | O(n log n)      | O(min(n, charset)) | Faster than brute force, but extra log factor  |
| Sliding Window + unordered\_map | O(n)            | O(min(n, charset)) | Optimal for large input, constant time lookups |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
567. Permutation in String - https://leetcode.com/problems/permutation-in-string/description/
438. Find All Anagrams in a String - https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Track longest unique token sequence or user activity