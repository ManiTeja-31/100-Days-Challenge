> [Permutations II] - https://leetcode.com/problems/permutations-ii/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking + Set for Duplicate Check
--------------------------------------------------------------------------------------------------------------------------------------
## 1. 🐌 Naive: Generate All Permutations + Use Set

### **Explanation**

* Generate **all permutations**, even duplicates.
* Use a **`set<vector<int>>`** to track unique permutations.
* Before adding a permutation to result, check if it's in the set.

### **Time Complexity**

* `O(n × n! + k log k)`

  * `n!` permutations
  * Copying vector and set insert/check adds overhead

### **Space Complexity**

* `O(n! × n)` — storing all permutations in result + set

### **Pros**

* Easy to implement using standard backtracking.

### **Cons**

* **Inefficient** due to duplicate work and set overhead.
* Not optimal for larger input sizes.

---

## 2. 🧠 Optimal Backtracking with Duplicate Skipping (Sorted + Used Array)

### **Explanation**

* **Sort the array** first to bring duplicates together.
* Use a **`used[]` boolean array** to track which elements are included.
* **Skip duplicates** by checking:

  ```cpp
  if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
  ```

  This ensures we don't pick the same number again at the same tree level.

### **Time Complexity**

* `O(n × n!)` — worst case, but avoids duplicates early via pruning

### **Space Complexity**

* `O(n)` — recursion stack + used array

### **Pros**

* Efficient and avoids generating duplicates.
* Very common and accepted solution in interviews.

### **Cons**

* Requires careful implementation of the duplicate-skip condition.

---

## 3. 💡 In-place Swapping + HashSet per Level

### **Explanation**

* Similar to regular backtracking with **in-place swapping**, but adds a **hash set per recursion level**.
* The `unordered_set<int> seen` ensures we **don’t place the same value at the same fixed index** more than once.

### **Time Complexity**

* `O(n × n!)` — same as optimal backtracking, avoids duplicate branches

### **Space Complexity**

* `O(n)` — for recursion + temporary `seen` set at each level

### **Pros**

* Efficient and uses **in-place swaps**, saving space.
* HashSet avoids the need for `used[]` array.

### **Cons**

* Slightly more logic than standard backtracking.
* Repeated creation of `unordered_set` per level.

---

## 4. ⚙️ STL `next_permutation` (Sorted Array)

### **Explanation**

* Sort the input array to start with the **lexicographically smallest permutation**.
* Use `std::next_permutation()` to generate all **unique permutations**.

### **Time Complexity**

* `O(n × n!)` — each call is `O(n)`, and there are at most `n!` unique permutations

### **Space Complexity**

* `O(1)` extra — aside from result storage

### **Pros**

* **Concise and clean** implementation.
* Leverages STL for correctness and speed.

### **Cons**

* Requires sorted input.
* Less control over the permutation generation process.
* Doesn’t allow customization (e.g., constraints within permutations).

---

## 🔚 Summary & Comparison

| Approach                              | Time Complexity | Space Complexity | Pros                               | Cons                                |
| ------------------------------------- | --------------- | ---------------- | ---------------------------------- | ----------------------------------- |
| Naive + Set                           | O(n × n!)       | O(n! × n)        | Easy to implement                  | Inefficient, slow due to set usage  |
| Backtracking with Duplicate Skipping  | O(n × n!)       | O(n)             | Efficient pruning, interview-ready | Needs sorted input and care         |
| In-place Swapping + HashSet per Level | O(n × n!)       | O(n)             | Optimal, space-efficient           | Slightly more logic overhead        |
| STL `next_permutation`                | O(n × n!)       | O(1) extra       | Short, clean, fast in C++          | Requires sorted input, less control |

---

## ✅ Recommendation

* For **interviews** and **custom logic**, go with:

  * **Backtracking with Duplicate Skipping** (sorted + used array)
  * OR **In-place Swapping + HashSet**

* Use **`next_permutation()`** for:

  * Quick implementation when input is already sorted
  * Lexicographical permutations needed

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
996. Number of Squareful Arrays - https://leetcode.com/problems/number-of-squareful-arrays/description/
60. Permutation Sequence - https://leetcode.com/problems/permutation-sequence/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Unique combinations in password generation or layout planning 