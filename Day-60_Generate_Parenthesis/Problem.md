> [Generate Parentheses] - https://leetcode.com/problems/generate-parentheses/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Backtracking with Constraints
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ Approach: Backtracking

### 🔍 Core Idea

Use backtracking to build a string of parentheses step by step.
We ensure the current string is **always valid** by maintaining two counters:

* `open`: Number of `(` used
* `close`: Number of `)` used

### 🔑 Constraints to Maintain Validity

1. Only add `(` if `open < n`
2. Only add `)` if `close < open`
   → Ensures we never close more parentheses than we've opened.

---

## 🔄 Step-by-Step Flow

```text
backTrack(curr = "", open = 0, close = 0)

- At each step:
  - If curr.size() == 2 * n:
      → We have a valid combination → push to result
  - If open < n:
      → Add '(' and recurse
  - If close < open:
      → Add ')' and recurse
```

For `n = 3`, the generated combinations are:

```
["((()))", "(()())", "(())()", "()(())", "()()()"]
```

---

## 🧮 Time and Space Complexity

| Metric    | Complexity                             |
| --------- | -------------------------------------- |
| **Time**  | `O(2^2n)` (Exponential in worst case)  |
| **Space** | `O(2n)` for recursion + result storage |

* You generate **Catalan Number** of valid strings:
  ( C_n = \frac{1}{n+1} \binom{2n}{n} )

* For `n = 3`, output has 5 strings

* For `n = 4`, output has 14 strings

* So while not strictly exponential, it's still fast-growing

---

## 📌 Tips for Interviews

* Always track how many `(` and `)` you’ve used.
* Use pruning: avoid exploring invalid branches early.
* This is a classic example of **DFS + constraints**.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2116. Check if a Parentheses String Can Be Valid - https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/
2267. Check if There Is a Valid Parentheses String Path - https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Valid expression generation, compiler parsing tools