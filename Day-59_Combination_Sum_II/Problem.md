> [Combination Sum II] - https://leetcode.com/problems/combination-sum-ii/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking + Duplicate Handling 
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Approach: Backtracking + Sorting + Duplicate Skipping

### 🔑 Key Observations:

* Unlike **Combination Sum I**, elements **cannot** be reused.
* Input may contain **duplicates**, so we need to **avoid duplicate combinations** in the result.
* We use **sorting** + **a skipping condition** to skip repeated values at the same recursion level.

---

### ✅ Step-by-Step Breakdown

1. **Sort the input array**:

   * This helps in:

     * Skipping duplicates easily.
     * Early stopping when the current number > target.

2. **Backtracking Function**:

   * Parameters: current index `start`, remaining `target`, current `combination`.
   * If `target == 0`: valid combination → add to result.
   * If `target < 0` or index exceeds bounds: invalid → backtrack.

3. **For-loop Exploration**:

   * Iterate from `start` to `end`.
   * **Duplicate Skipping**: If `i > start` and `candidates[i] == candidates[i-1]`, skip to avoid duplicate combinations.
   * **Prune search**: If `candidates[i] > target`, break early (since array is sorted).
   * Include `candidates[i]`, recurse with `i + 1` (because no reuse).
   * Backtrack by removing the last element after recursive call.

---

## ⏱️ Time and Space Complexity

| Metric    | Complexity                       |
| --------- | -------------------------------- |
| **Time**  | `O(2^n)` worst-case              |
| **Space** | `O(k)` per path + result storage |

* In worst-case, you explore most of the power set.
* Sorting takes `O(n log n)`, but the backtracking dominates the time.

---

## 📌 Final Notes

* This problem is a classic **variant of Combination Sum I**.
* Mastering **duplicate skipping in backtracking** is key to solving many advanced recursive problems.
* The sorted input combined with `i > start && nums[i] == nums[i-1]` is the standard trick.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Combinations from limited frequency options (e.g. 1 use per item) 