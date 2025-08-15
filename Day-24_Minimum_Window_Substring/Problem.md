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
# PsuedoCode
Minimum Window Substring – Pseudocode
- Create frequency map for all characters in t.
* Initialize:
- left and right pointers at 0.
- minLen as infinity, startIndex as 0.
- required as the count of characters needed from t.
- A window frequency map for s.
- Expand window by moving right:
- Add s[right] to window map.
- If s[right] is needed and count is not exceeded, decrement required.
- When required is 0 (window is valid):
- If window size is smaller than minLen, update minLen and startIndex.
- Remove s[left] from window map and move left forward.
- If a needed character is removed, increment required.
- Repeat until right reaches end of s.
- Return substring from startIndex of length minLen if found, else "".
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**

* Try every possible substring of `s`.
* Check if it contains all characters of `t`.

---

### **Step-by-Step**

1. Loop over every possible starting index `i`.
2. For each start, try every possible end index `j`.
3. Extract substring `s[i...j]`.
4. Check if it contains all characters of `t` (frequency check).
5. Keep track of the smallest valid substring.

---

### **Complexity**

* **Time:** O(m²·n) — m² substrings × O(n) check each.
* **Space:** O(1) — Frequency arrays of fixed size.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach 1 – Sliding Window + Full Validity Check (O(256·m))**

### **Idea**

* Use two frequency arrays:

  * `tMap` for `t`.
  * `windowMap` for current substring in `s`.
* Expand the right pointer until all characters are covered.
* Shrink the left pointer to minimize the window while still valid.

---

### **Step-by-Step**

1. Initialize `tMap` with frequencies of `t`.
2. Move `right` pointer, adding characters to `windowMap`.
3. While `windowMap` covers all `tMap`:

   * Update minimum length.
   * Remove `left` character from `windowMap` and move `left`.
4. Repeat until `right` reaches the end.

---

### **Complexity**

* **Time:** O(256·m) — Each validity check scans full alphabet (256).
* **Space:** O(256) — Frequency arrays.

---

## **Approach 2 – Sliding Window + Count of Required Characters (O(m))** ✅ *Optimal*

### **Idea**

* Instead of checking full frequency array every time,
  keep a `required` count of how many characters are still missing.
* Only shrink when `required == 0`.

---

### **Step-by-Step**

1. Build `tMap` with frequencies of `t`.
2. Initialize `left = 0`, `right = 0`, `required = length of t`.
3. Expand `right`:

   * If adding a needed character reduces `required`, decrement `required`.
4. When `required == 0`:

   * Try shrinking from the left while keeping all characters.
   * Update minimum length whenever a smaller valid window is found.
5. Continue until `right` reaches end.

---

### **Complexity**

* **Time:** O(m) — Each character processed at most twice.
* **Space:** O(128) — Frequency arrays for ASCII.

---

## **Comparison Table**

| Approach                                   | Time Complexity | Space Complexity | Notes                                        |
| ------------------------------------------ | --------------- | ---------------- | -------------------------------------------- |
| Brute Force (Check every substring)        | O(m²·n)         | O(1)             | Too slow for large strings                   |
| Sliding Window + Full Validity Check       | O(256·m)        | O(256)           | Faster but still checks all chars every time |
| Sliding Window + Required Count (**Best**) | O(m)            | O(128)           | Optimal for large inputs                     |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
480. Sliding Window Median - https://leetcode.com/problems/sliding-window-median/description/
239. Sliding Window Maximum - https://leetcode.com/problems/sliding-window-maximum/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Minimal-length substring match (e.g., minimum DNA sequence with all genes)
