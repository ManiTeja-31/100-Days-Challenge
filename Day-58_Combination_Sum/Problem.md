> [Combination Sum] - https://leetcode.com/problems/combination-sum/description/
> Level - edium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Approach: Backtracking

The key idea is to explore **all possible combinations** recursively and **backtrack** if the sum exceeds the target.

---

### ✅ Version 1: Backtracking with Explicit Include/Exclude

#### **How It Works**

* For each index `ind`, you have two choices:

  1. **Exclude** the current element and move to the next index.
  2. **Include** the current element and stay at the same index (since repetition is allowed).

* Maintain a running `sum`. If:

  * `sum == target`: store the current combination.
  * `sum > target` or index exceeds size → backtrack.

#### **Pros**

* Clean logical flow using decision tree (include/exclude).
* Good for understanding the backtracking paradigm.

#### **Cons**

* May generate more function calls than necessary.

---

### ✅ Version 2: Backtracking with For-Loop (Preferred)

#### **How It Works**

* Iterate through the `candidates` starting from current index `i`.

* Add `candidates[i]` to the combination and recursively call with:

  * `target - candidates[i]` (updated target)
  * same index `i` (because repetition is allowed)

* If target becomes `0`, we found a valid combination.

* If target becomes `< 0`, it's invalid → backtrack.

#### **Pros**

* More concise and efficient.
* Standard template for most combination-style problems.

#### **Cons**

* Requires understanding of index management to avoid duplicates.

---

## ⏱️ Time and Space Complexity

| Metric    | Complexity                                  |
| --------- | ------------------------------------------- |
| **Time**  | `O(2^T)` or exponential                     |
| **Space** | `O(T)` recursion stack + `O(A)` result size |

* `T` = target value
* `A` = number of valid combinations
* Exponential because at each level, we can either include or exclude elements repeatedly.

---

## 📌 Key Points

* Backtracking explores all combinations using a **DFS-style** search.
* Since elements can repeat, we **don’t increment the index** when including an element.
* **Base cases:**

  * `target == 0` → Valid path
  * `target < 0` → Invalid path
* The result list accumulates only valid combinations.

---

## 📋 Summary

| Feature                  | Version 1                       | Version 2                            |
| ------------------------ | ------------------------------- | ------------------------------------ |
| Approach                 | Include/Exclude                 | For-loop based recursive exploration |
| Repeats allowed?         | Yes (stay on same index)        | Yes (don’t increment after include)  |
| Base Conditions          | `sum == target`, `sum > target` | `target == 0`, `target < 0`          |
| Code Readability         | Easier to visualize tree        | Cleaner and widely used              |
| Preferred in Interviews? | ❌ Slightly verbose              | ✅ Commonly preferred                 |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
216. Combination Sum III - https://leetcode.com/problems/combination-sum-iii/description/
377. Combination Sum IV - https://leetcode.com/problems/combination-sum-iv/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Find combinations of coins to make target amount 