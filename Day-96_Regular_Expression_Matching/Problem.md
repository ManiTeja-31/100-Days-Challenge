> [10. Regular Expression Matching] - https://leetcode.com/problems/regular-expression-matching/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp/Recursion
--------------------------------------------------------------------------------------------------------------------------------------
# 🔹 Regex Matching (`.` and `*`) Approaches

The goal: Implement `isMatch(s, p)` where:

* `.` matches any single character.
* `*` matches zero or more of the preceding element.

---

## 1️⃣ Naive / Recursive Approach

### **Idea**

* Recursively try all possibilities.
* For each position `(i, j)` in `(s, p)`:

1. Check if the first characters match (or `.`).
2. If `p[j+1] == '*'`:

   * Match **zero occurrence** → skip 2 chars in pattern.
   * OR **one/more occurrence** → move in string if first character matches.
3. Otherwise → match current char and move both pointers.

```cpp
bool match(const string &s, const string &p, int i, int j) {
    if (j == p.size()) return i == s.size();
    bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
    if (j+1 < p.size() && p[j+1] == '*')
        return match(s,p,i,j+2) || (first_match && match(s,p,i+1,j));
    else
        return first_match && match(s,p,i+1,j+1);
}
```

### **Pros**

* Simple and intuitive.

### **Cons**

* Exponential time in worst case → **TLE for long strings**.
* Many overlapping subproblems.

---

## 2️⃣ Top-Down DP with Memoization

### **Idea**

* Memoize `(i, j)` results to avoid recomputation.
* Use `vector<vector<int>> memo` initialized to `-1`.

```cpp
vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
memo[i][j] = ans; // store result
```

* Recursion logic remains the same.
* Check memo before computing.

### **Time Complexity**

* `O(m * n)` — each `(i,j)` computed at most once.
* Space: `O(m * n)` + recursion stack.

### **Pros**

* Avoids repeated work → efficient.
* Still easy to understand recursively.

---

## 3️⃣ Bottom-Up DP (Tabulation)

### **Idea**

* Build a 2D DP table `dp[i][j]` where:

```
dp[i][j] = true if s[i:] matches p[j:]
```

* Iterate from **end of string** to start:

```cpp
for i = m..0:
    for j = n-1..0:
        first_match = (s[i]==p[j] || p[j]=='.')
        if p[j+1]=='*':
            dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j])
        else:
            dp[i][j] = first_match && dp[i+1][j+1]
```

* `dp[0][0]` → final answer.

### **Pros**

* Iterative → no recursion stack overhead.
* `O(m*n)` time and space.

---

## 4️⃣ Space-Optimized Bottom-Up DP

### **Idea**

* Only need **current row and next row** at each iteration.
* Use two 1D arrays:

```cpp
vector<bool> dp_next(n+1, false), dp_curr(n+1, false);
dp_next[n] = true; // empty string matches empty pattern
```

* Update `dp_curr` using `dp_next` from previous iteration.
* Move `dp_curr` → `dp_next` for next iteration.

### **Time & Space Complexity**

* Time: `O(m*n)`
* Space: `O(n)` instead of `O(m*n)`

### **Pros**

* Very memory-efficient.
* Ideal for long strings.

---

## ⚡ Summary Table

| Approach           | Time Complexity | Space Complexity | Notes                                  |
| ------------------ | --------------- | ---------------- | -------------------------------------- |
| Recursive / Naive  | O(2^(m+n))      | O(m+n) stack     | Exponential, TLE for large inputs      |
| Top-Down DP        | O(m*n)          | O(m*n)           | Memoization saves recomputation        |
| Bottom-Up DP       | O(m*n)          | O(m*n)           | Iterative, avoids recursion stack      |
| Space-Optimized DP | O(m*n)          | O(n)             | Only keeps two rows, best memory usage |

---

💡 **Key Takeaways**

1. `*` introduces branching → recursion needs memoization for efficiency.
2. Bottom-up DP is usually faster in practice than top-down recursion.
3. Space optimization is possible because DP only depends on the **next row**.
4. Always consider **edge cases** like empty string or pattern with `*` at the end.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
44. Wildcard Matching - https://leetcode.com/problems/wildcard-matching/description/
3407. Substring Matching Pattern - https://leetcode.com/problems/substring-matching-pattern/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
 Regex engines, flexible input validation