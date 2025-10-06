> [Subsets] - https://leetcode.com/problems/subsets/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Recursion + Bit Manipulation 
--------------------------------------------------------------------------------------------------------------------------------------
## 1. 🌲 Backtracking (DFS) – Include / Exclude Method

### **Explanation**

* Recursively decide whether to **include or exclude** each element.
* Think of it like a decision tree where each node branches into two:

  * One branch **includes** the current element.
  * One branch **excludes** it.
* When you reach the end (`ind == nums.size()`), store the current subset.

### **Time Complexity**

* `O(2^n × n)`

  * `2^n` subsets
  * Each subset takes `O(n)` to copy

### **Space Complexity**

* `O(n)` for recursion + path tracking

### **Pros**

* Very intuitive and clear.
* Easy to apply for **subset sum**, **target sum**, etc.

### **Cons**

* Slightly more recursive overhead compared to iterative methods.

---

## 2. 🧭 Backtracking (DFS with For-Loop) – Expansion Method

### **Explanation**

* Instead of include/exclude, loop through the array starting from `ind`.
* For each index:

  * Include the current element.
  * Recurse to explore further subsets.
  * Backtrack to explore other combinations.
* This builds up all combinations by expanding forward.

### **Time Complexity**

* `O(2^n × n)`

### **Space Complexity**

* `O(n)` — recursion + temporary subset

### **Pros**

* Easy to adapt for **subset with conditions** (e.g., no duplicates, target sum).
* Clean structure.

### **Cons**

* Still uses recursion, not tail-optimized.

---

## 3. 🔢 Bitmasking (Iterative) – Optimal & Clever

### **Explanation**

* Each number from `0` to `2^n - 1` can represent a subset.
* Interpret the binary representation of a number as a decision:

  * If bit `i` is set (`1`), include `nums[i]` in the subset.
* Efficient and elegant.

### **Time Complexity**

* `O(2^n × n)` — loop over `2^n` masks, up to `n` operations per subset

### **Space Complexity**

* `O(2^n × n)` for storing all subsets

### **Pros**

* **Iterative**, avoids recursion.
* Very efficient and often used in **competitive programming**.
* Easy to generate lexicographically sorted subsets (if input is sorted).

### **Cons**

* Less intuitive for beginners.
* Bit manipulation can be tricky to debug.

---

## 4. ➕ Iterative Subset Expansion

### **Explanation**

* Start with the empty set.
* For each element in `nums`:

  * Copy all existing subsets.
  * Add the current element to each of the copies.
  * Append them to the result list.
* Doubles the number of subsets at each step.

### **Time Complexity**

* `O(2^n × n)`

### **Space Complexity**

* `O(2^n × n)` — for all subsets

### **Pros**

* **Very clean and iterative**.
* No recursion needed.
* Easy to implement and understand.

### **Cons**

* Slightly more memory intensive due to repeated copying.

---

## 🔚 Summary & Comparison

| Approach                       | Time Complexity | Space Complexity | Recursive? | Pros                           | Cons                       |
| ------------------------------ | --------------- | ---------------- | ---------- | ------------------------------ | -------------------------- |
| Backtracking (Include/Exclude) | O(2^n × n)      | O(n)             | ✅          | Simple, good for modifications | Recursive overhead         |
| Backtracking (Loop DFS)        | O(2^n × n)      | O(n)             | ✅          | Cleaner structure, expandable  | Recursive                  |
| Bitmasking (Binary Mask)       | O(2^n × n)      | O(2^n × n)       | ❌          | Efficient, clever              | Less intuitive             |
| Iterative Subset Expansion     | O(2^n × n)      | O(2^n × n)       | ❌          | Clean, readable, no recursion  | Extra space due to copying |

---

## ✅ Recommendation

* Use **Backtracking with For-Loop DFS** if:

  * You plan to modify the logic (e.g. constraints, target sum).
* Use **Bitmasking or Iterative Expansion** if:

  * You want clean, efficient **non-recursive** solutions.
  * Great for large inputs or competitive programming.
--------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
784. Letter Case Permutation - https://leetcode.com/problems/letter-case-permutation/description/
1982. Find Array Given Subset Sums - https://leetcode.com/problems/find-array-given-subset-sums/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Power set generation for testing, A/B options