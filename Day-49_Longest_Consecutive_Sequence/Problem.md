> [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/)
> **Level:** Medium

---

# Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in $O(n)$ time.

---

## Pattern
> Hashing

---

## Approaches

### 1. Brute Force Approach
**Intuition:**
Check every possible pair to see if a sequence can be formed starting from each number.

**Step-by-step:**
- For each number, try to build the longest consecutive sequence by checking if the next number exists in the array.
- Use `find` to check for the next consecutive number.
- Update the maximum length found.

**Time Complexity:** $O(N^2)$ (due to repeated searches with `find`)

**Space Complexity:** $O(1)$

---

### 2. Sorting Approach
**Intuition:**
Sorting brings consecutive numbers together, making it easy to count streaks.

**Step-by-step:**
- Sort the array.
- Iterate through, counting streaks of consecutive numbers (skip duplicates).
- Track the maximum streak.

**Time Complexity:** $O(N \log N)$ (for sorting)

**Space Complexity:** $O(1)$ (if sorting in-place)

---

### 3. Optimal Approach using HashSet
**Intuition:**
A set allows $O(1)$ lookups to quickly check for consecutive numbers.

**Step-by-step:**
- Insert all numbers into a set.
- For each number, if it's the start of a sequence (no `num-1`), count the streak by checking for `num+1`, `num+2`, etc.
- Track the maximum streak.

**Time Complexity:** $O(N)$

**Space Complexity:** $O(N)$

---

### 4. Optimal Approach using Union-Find
**Intuition:**
Union-Find groups consecutive numbers into sets, and the largest set size is the answer.

**Step-by-step:**
- For each number, make it its own parent.
- Union with neighbors (`num-1`, `num+1`) if they exist.
- The size of the largest set is the answer.

**Time Complexity:** $O(N \cdot \alpha(N))$ (almost linear, $\alpha$ is inverse Ackermann)

**Space Complexity:** $O(N)$

---

### 5. Optimal Approach using HashMap
**Intuition:**
A hash map tracks the length of sequences at their boundaries, allowing efficient merging.

**Step-by-step:**
- For each number, if not already seen, check the length of left and right sequences.
- Merge sequences and update boundaries.
- Track the maximum streak.

**Time Complexity:** $O(N)$

**Space Complexity:** $O(N)$

---

### 6. Another Optimal Approach using HashSet (Erasing)
**Intuition:**
By erasing numbers as you process them, you avoid redundant work and ensure each number is only processed once.

**Step-by-step:**
- Insert all numbers into a set.
- For each number, if still in the set, expand left and right, erasing as you go.
- Track the maximum streak.

**Time Complexity:** $O(N)$

**Space Complexity:** $O(N)$

---

# Other Problems Using this Approach
873. Length of Longest Fibonacci Subsequence - https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
446. Arithmetic Slices II - Subsequence - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
---

# CodeChef Equivalent
NA

---

# Real-World Use
Finding longest streak of user activity