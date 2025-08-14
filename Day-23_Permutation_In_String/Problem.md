> [Permutation in String] - https://leetcode.com/problems/permutation-in-string/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Frequency Match 
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

* Input: Two strings `s1` and `s2`.
* Output: Return `true` if `s2` contains a permutation of `s1`, otherwise `false`.

Steps:
1. Handle edge cases:
   - If `s1.length > s2.length`, return `false`.

2. Initialize frequency arrays:
   - Create `freqS1` to store character frequencies of `s1` (size 26 for lowercase letters).
   - Create `freqWindow` to store character frequencies of the first `s1.length` characters of `s2`.

3. Check the first window:
   - If `freqS1` matches `freqWindow`, return `true`.

4. Slide the window across `s2`:
   - Use two pointers `l` and `r` to define the window.
   - For each step:
     - Remove the character at index `l` (left of the window) from `freqWindow`.
     - Add the character at index `r` (right of the window) to `freqWindow`.
     - If `freqS1` matches `freqWindow`, return `true`.

5. If no match is found after sliding the window, return `false`.
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**

* Generate every substring of `s2` of length `k = len(s1)`.
* Sort it and compare with the sorted `s1`.

---

### **Step-by-Step**

1. Sort `s1` once.
2. For every window of length `k` in `s2`:

   * Extract substring.
   * Sort substring.
   * Compare with sorted `s1`.
3. If a match is found → return true.

---

### **Complexity**

* **Time:** O(n·k log k) — For each of `n` substrings, sorting takes `O(k log k)`.
* **Space:** O(k) — To store substring.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### **Idea**

* Instead of sorting each window, compare **character frequency counts**.
* Use a fixed-size sliding window of length `k` and update counts in O(1) time.

---

### **Step-by-Step**

1. Create two frequency arrays `freqS1` and `freqWindow` of size 26 (for lowercase letters).
2. Fill both arrays for the first `k` characters (`s1` and first window in `s2`).
3. If they match → return true.
4. Slide the window:

   * Remove left character from `freqWindow`.
   * Add new right character to `freqWindow`.
   * Compare arrays.
5. If any match → return true, else false.

---

### **Complexity**

* **Time:** O(n) — Each character is processed once when entering and leaving the window.
* **Space:** O(1) — Frequency arrays have fixed size 26.

---

## **Why Frequency Array Works Instead of Sorting?**

* Sorting → compares permutations by ordering characters.
* Frequency array → compares **character counts**, which is exactly what defines a permutation.
* Avoids `O(k log k)` sort cost → becomes `O(1)` update and comparison.

---

## **Comparison Table**

| Approach                          | Time Complexity | Space Complexity | Notes                   |
| --------------------------------- | --------------- | ---------------- | ----------------------- |
| Brute Force (Sort each substring) | O(n·k log k)    | O(k)             | Simple but slow         |
| Sliding Window + Frequency Array  | O(n)            | O(1)             | Optimal for large input |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2514. Count Anagrams - https://leetcode.com/problems/count-anagrams/description/
438. Find All Anagrams in a String - https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Detecting if request contains credentials in any order

