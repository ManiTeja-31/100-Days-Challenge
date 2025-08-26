> [Find All Anagrams In A String] - https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Frequency Array
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode
* Input: Two strings s and p.
* Output: Array of starting indices in s where anagrams of p are found.
1. Edge Cases:
- If the size of p is greater than s, return an empty array.
2. Initialize Variables:
- left = 0, right = 0 (pointers for the sliding window).
- Two frequency vectors of size 26: pHash (for p) and windowHash (for the current sliding window in s).
- result array to store starting indices of anagrams.
3. Pre-Processing:
- Populate pHash and windowHash with character frequencies from p and the first p.length() characters of s.
4. Sliding Window Logic:
- Compare pHash with windowHash. If they match, add left to result.
- Increment right to expand the window.
- Add the new character at right to windowHash.
- Remove the character at left from windowHash.
- Increment left to maintain the window size.
- Repeat until right reaches the end of s.
5. Return result array.
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### 🔹 Idea:

* Generate all substrings of length `|p|` from `s`.
* For each substring, check if it’s an anagram of `p`.
* Use a frequency array (`26` letters) to check equality.

### 🔹 Steps:

1. Loop over all substrings of length `m = |p|`.
2. Compare substring’s frequency with `p`’s frequency.
3. If equal, add index to result.

### 🔹 Complexity:

* Generating substrings: `O(n * m)`
* Checking anagram: `O(26)` (constant)
  👉 **Time:** `O(n * m)` (quadratic in worst case).
  👉 **Space:** `O(1)` extra.

### 🔹 Interview Note:

* Straightforward but inefficient for long strings.
* Good **first step** to show you understand the problem.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### 🔹 Idea:

Instead of recomputing for each substring, use a **sliding window** of size `m` over `s`:

* Maintain frequency count for current window.
* Compare it with `p`’s frequency in `O(26)` each time.
* Move window by **removing one char and adding the next**.

### 🔹 Steps:

1. Build frequency for `p` and first `m` chars of `s`.
2. Slide the window over `s`:

   * Update frequencies for entering & leaving characters.
   * Compare frequency arrays.
3. Store index when match is found.

### 🔹 Complexity:

* Initial setup: `O(m)`
* Sliding window: `O(n-m)`
* Each comparison: `O(26)`
  👉 **Time:** `O(n * 26)` ≈ `O(n)`
  👉 **Space:** `O(26)` (constant).

### 🔹 Interview Note:

* This is the **classic sliding window pattern**.
* Much faster than brute force.

---

## **Further Optimized Approach (Match Count Trick)**

### 🔹 Idea:

Instead of comparing full frequency arrays (`O(26)` each time), maintain a **match counter**:

* Track how many characters currently match between window and pattern.
* When adding/removing characters, update this counter.
* If `matchCount == 26` → it’s an anagram.

### 🔹 Steps:

1. Count frequencies for `p` and first window in `s`.
2. Initialize `matchCount` = number of chars that match.
3. Slide the window:

   * Update frequencies for add/remove char.
   * Adjust `matchCount`.
   * If `matchCount == 26`, record index.

### 🔹 Complexity:

* Each character processed once.
* No full array comparisons.
  👉 **Time:** `O(n)`
  👉 **Space:** `O(26)` constant.

### 🔹 Interview Note:

* This shows **deep optimization** beyond standard sliding window.
* Excellent for large input (`n` up to 20,000).
* Interviewers love when you mention: *“We can reduce comparison cost by keeping a live match counter.”*
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
49. Group Anagrams - https://leetcode.com/problems/group-anagrams/description/
2514. Count Anagrams - https://leetcode.com/problems/count-anagrams/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Think of `p` as a **shopping list of items**.

* The window on `s` is your **shopping basket**.
* As you slide across the aisle (`s`), you remove one item and add another.
* If your basket matches the list exactly → valid index.

Got it 👍 Let’s break down **Find All Anagrams in a String** into the same structured interview-notes style.

---


## **5. Tips for Interviews**

* Brute force is acceptable to start, but quickly move to sliding window.
* Always mention frequency array is better than sorting (`O(m log m)`).
* Stress **match count trick** if interviewer asks about further optimization.
* This problem is a **template** for other substring problems:

  * Minimum Window Substring
  * Permutation in String
  * Substring with Concatenation of All Words

---
