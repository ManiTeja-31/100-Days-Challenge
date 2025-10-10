> [Decode String] - https://leetcode.com/problems/decode-string/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stack + Nested parsing
--------------------------------------------------------------------------------------------------------------------------------------

## ✅ **Approach 1: Iterative Using Two Stacks**

### 🧠 Idea

Use:

* `countStack`: to keep track of repeat counts (`k`)
* `strStack`: to keep track of string parts before entering `[...]`

### 🔄 Logic

1. Traverse character by character.
2. When you hit a digit, build the number (`num = num*10 + (c - '0')`)
3. On `[`, push `num` and `curr` string, and reset.
4. On `]`, pop count and previous string, then repeat `curr` and append.
5. On characters, append to `curr`.

### ✅ Code Summary

```cpp
if (isdigit(c)) → build the number
else if (c == '[') → push curr + num
else if (c == ']') → pop count, repeat current string, combine with prev
else → append to curr
```

### ⏱ Time: O(n), 🗂 Space: O(n)

### 🧪 Example

```cpp
Input: "3[a2[c]]"
Steps:
- c = '3' → num = 3
- c = '[' → push "", 3
- c = 'a' → curr = "a"
- c = '2' → num = 2
- c = '[' → push "a", 2
- c = 'c' → curr = "c"
- c = ']' → repeat "c" x2 = "cc", curr = "a" + "cc" = "acc"
- c = ']' → repeat "acc" x3 = "accaccacc"
```

---

## ✅ **Approach 2: Recursive (Top-Down DFS)**

### 🧠 Idea

Use **recursion** to dive into nested brackets like a parser. Use a global `i` to track the index.

### 🔄 Logic

1. If digit, build `num`
2. If `[`, call `decode()` recursively
3. If `]`, return the built string
4. Else, just add character to result

### 🔁 Code Flow

```cpp
while (i < s.size())
    if digit → build num
    if '[' → recursive call
    if ']' → return result
    else → add char to result
```

### ⏱ Time: O(n), 🗂 Space: O(n) (due to recursion stack)

---


## 📝 Summary Table

| Approach           | Time | Space | Notes                           |
| ------------------ | ---- | ----- | ------------------------------- |
| Iterative + Stacks | O(n) | O(n)  | Clean, iterative, easy to debug |
| Recursive (DFS)    | O(n) | O(n)  | Elegant, better for nesting     |

---

## ✅ Recommendation

* For deeply nested inputs: **Recursive DFS** is intuitive.
* For performance with controlled memory: **Iterative with stacks** is optimal.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
443. String Compression - https://leetcode.com/problems/string-compression/description/
726. Number of Atoms - https://leetcode.com/problems/number-of-atoms/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Text compression decoding, HTML template rendering.