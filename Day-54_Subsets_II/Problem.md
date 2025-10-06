> [Subsets II] - https://leetcode.com/problems/subsets-ii/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking + Duplicate Handling
--------------------------------------------------------------------------------------------------------------------------------------
## 1. 🐌 Naive Backtracking + `set` to Remove Duplicates

### **Explanation**

* Perform standard **include/exclude recursion** to explore all subsets.
* Use a `set<vector<int>>` to **automatically eliminate duplicates**.
* **Sort the input** so that duplicate elements are adjacent (important for correct deduplication).

### **Time Complexity**

* `O(2^n × n × log k)`

  * `2^n` subsets
  * `O(n)` to copy each subset
  * `log k` for set insertion (k = number of unique subsets)

### **Space Complexity**

* `O(k × n)` for storing all unique subsets in the set

### **Pros**

* Straightforward if you already know standard backtracking

### **Cons**

* Inefficient due to set overhead
* Duplicates are removed **after generation**, not prevented

---

## 2. ✅ Optimal Backtracking with Duplicate Skipping

### **Explanation**

* **Sort the input** to group duplicates together.
* While exploring subsets, skip adding the same element at the same recursive depth:

  ```cpp
  if (i > start && nums[i] == nums[i - 1]) continue;
  ```
* This ensures **only the first occurrence of a duplicate is included per depth**.

### **Time Complexity**

* `O(2^n × n)` — generates only unique subsets directly

### **Space Complexity**

* `O(n)` recursion + `O(2^n × n)` result storage

### **Pros**

* Most efficient and clean method
* No extra space for set needed
* Actively avoids duplicates during recursion

### **Cons**

* Requires careful implementation of the duplicate skip condition

---

## 3. ♻️ Iterative Approach with Tracking Previous Subsets

### **Explanation**

* Start with `res = [[]]` (the empty subset).
* For each number in `nums`:

  * If it's a **duplicate** of the previous number, only add it to **new subsets formed in the last iteration** (not all).
* Use two pointers:

  * `startIdx` → where to begin adding the current number
  * `endIdx` → index before the new subsets start

### **Time Complexity**

* `O(2^n × n)`

  * Each new subset takes `O(n)` to copy and append

### **Space Complexity**

* `O(2^n × n)` for storing all subsets

### **Pros**

* Clean and **non-recursive**
* Efficient and avoids duplicates directly

### **Cons**

* Requires tracking `startIdx` and `endIdx` carefully

---

## 4. 🔢 Bitmasking with `set` to Remove Duplicates

### **Explanation**

* Use integers from `0` to `2^n - 1` as bitmasks.
* For each mask:

  * Select elements where the bit is `1`.
  * Store the resulting subset in a `set` to **ensure uniqueness**.
* **Sort input** beforehand to ensure consistent duplicate handling.

### **Time Complexity**

* `O(2^n × n × log k)` — similar to naive with set

### **Space Complexity**

* `O(k × n)` for storing unique subsets

### **Pros**

* Iterative and easy to implement
* Clever use of bit manipulation

### **Cons**

* Still uses a `set`, which adds overhead
* Less efficient than skipping duplicates during generation

---

## 🔚 Summary & Comparison

| Approach                           | Time Complexity    | Space Complexity | Recursive? | Duplicate Handling | Pros                            | Cons                             |
| ---------------------------------- | ------------------ | ---------------- | ---------- | ------------------ | ------------------------------- | -------------------------------- |
| Naive + Set                        | O(2^n × n × log k) | O(k × n)         | ✅          | After generation   | Easy to write                   | Inefficient due to `set`         |
| Backtracking with Skip Duplicates  | O(2^n × n)         | O(2^n × n)       | ✅          | During generation  | Most optimal, avoids duplicates | Careful logic needed             |
| Iterative + Track Previous Subsets | O(2^n × n)         | O(2^n × n)       | ❌          | During generation  | Iterative, efficient            | Needs index tracking             |
| Bitmasking + Set                   | O(2^n × n × log k) | O(k × n)         | ❌          | After generation   | Compact and clean using bitmask | Set makes it slower than optimal |

---

## ✅ Recommendation

* Use **Backtracking with Duplicate Skipping** for:

  * Clean, recursive solutions
  * Efficient subset generation without post-processing

* Use **Iterative with Start/End Tracking** for:

  * Fast, non-recursive, and intuitive solutions
  * Great in interviews for clarity

* Avoid the `set`-based solutions in production unless you want quick prototypes.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
1982. Find Array Given Subset Sums - https://leetcode.com/problems/find-array-given-subset-sums/description/
2122. Recover the Original Array - https://leetcode.com/problems/recover-the-original-array/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Unique menu combinations or permissions list