> [Permutations] - https://leetcode.com/problems/permutations/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking
--------------------------------------------------------------------------------------------------------------------------------------
This is a classic **backtracking** problem where we explore all possible arrangements (factorial growth in possibilities).

---

## 1. 🔁 Backtracking with Visited Array (DFS Style)

### **Explanation**

* Use a **`visited[]` array** to keep track of which elements are already included in the current path.
* Build the current permutation (`path`) step by step.
* When `path.size() == nums.size()`, a valid permutation is found.
* Backtrack after each decision to explore other paths.

### **Time Complexity**

* `O(n × n!)`

  * `n!` permutations
  * Each copy to result takes `O(n)`

### **Space Complexity**

* `O(n)` for visited array + recursion stack + path

### **Pros**

* Easy to understand and debug.
* Good for teaching backtracking basics.

### **Cons**

* Uses extra space for the visited array.

---

## 2. 🔄 Backtracking with In-Place Swapping (Optimal)

### **Explanation**

* Instead of using a visited array, this approach swaps elements **in-place** to fix each position.
* At index `ind`, swap with all indices `i ≥ ind` and recursively fix the next index.
* Backtrack by swapping back after each recursion.

### **Time Complexity**

* `O(n × n!)`

### **Space Complexity**

* `O(n)` — for recursion stack (no extra visited array or path)

### **Pros**

* **Space-efficient** and faster due to reduced memory overhead.
* Preferred for interview solutions and large inputs.

### **Cons**

* Slightly harder to conceptualize at first compared to the visited-array approach.

---

## 3. ⚙️ Using STL `next_permutation` Function

### **Explanation**

* Uses C++ STL `next_permutation` to generate all permutations in lexicographic order.
* Start with a sorted version of the input array.
* Keep applying `next_permutation()` until all permutations are generated.

### **Time Complexity**

* `O(n × n!)`

### **Space Complexity**

* `O(1)` extra (ignoring the result storage)

### **Pros**

* Very **concise and clean**.
* Great if input is already sorted or order matters.

### **Cons**

* Only works with **unique elements**.
* Cannot easily control or customize the recursion/backtracking process.

---

# 🔚 Summary & Comparison

| Approach                        | Time Complexity | Space Complexity | Pros                            | Cons                          |
| ------------------------------- | --------------- | ---------------- | ------------------------------- | ----------------------------- |
| Backtracking with Visited Array | O(n × n!)       | O(n)             | Clear, intuitive backtracking   | Extra space for visited[]     |
| Backtracking with In-place Swap | O(n × n!)       | O(n)             | Optimal space, preferred method | Slightly harder to grasp      |
| STL `next_permutation`          | O(n × n!)       | O(1) extra       | Minimal code, very fast in C++  | Only works if input is unique |

---

## ✅ Recommendation

* For **interviews and optimal performance**, use **in-place swapping**.
* For **learning and clarity**, the **visited array** method is a great place to start.
* For **quick implementation**, use **`next_permutation()`** if applicable.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
31. Next Permutation - https://leetcode.com/problems/next-permutation/description/
77. Combinations - https://leetcode.com/problems/combinations/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Generating possible configurations (e.g. anagram generation, routing) 