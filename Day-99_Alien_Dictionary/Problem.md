> [Alien Dictionary] - https://www.geeksforgeeks.org/problems/alien-dictionary/1
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Topological Sort
--------------------------------------------------------------------------------------------------------------------------------------
## 🧩 Core Idea: Topological Sorting

Both algorithms model the problem as a **Directed Graph**:

* Each unique character is a node.
* An edge `u → v` means `u` comes **before** `v` in the alien dictionary.

Then, we find a **topological order** of this graph using either:

* **Kahn’s Algorithm (BFS)**, or
* **DFS-based topological sorting**.

---

## 1️⃣ Kahn’s Algorithm (BFS Topological Sort)

### **Approach**

1. **Initialize Graph**

   * Use `unordered_map<char, unordered_set<char>>` for adjacency list.
   * Initialize all characters’ indegrees to `0`.

2. **Build Graph**

   * Compare each pair of adjacent words:

     * Find the **first differing character**.
     * Add an edge from `w1[j] → w2[j]` (i.e., `c1 → c2`).
     * Increment indegree of `c2`.
   * Handle invalid case: if `w1` is longer than `w2` but starts with `w2` (e.g., `"abc", "ab"`), return `""`.

3. **BFS Traversal**

   * Push all nodes with **indegree = 0** into a queue.
   * Repeatedly pop a node and:

     * Append it to the result string.
     * Decrease indegree of its neighbors.
     * If a neighbor’s indegree becomes `0`, push it to the queue.

4. **Cycle Detection**

   * If result length < number of unique characters → cycle detected → return `""`.

### **Example**

Input:

```
["wrt", "wrf", "er", "ett", "rftt"]
```

Edges:

```
w → e  
e → r  
r → t  
t → f
```

Output: `"wertf"`

### **Time & Space Complexity**

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(V + E)   |
| Space  | O(V + E)   |

### **Pros**

✅ Intuitive and easy to implement
✅ Naturally handles cycle detection via indegrees
✅ Works level-by-level (like BFS)

### **Cons**

❌ Slightly more bookkeeping (indegree array)
❌ Requires queue and indegree management

---

## 2️⃣ DFS Topological Sort

### **Approach**

1. **Build Graph**

   * Same as BFS: Compare adjacent words and build directed edges.
   * Use `unordered_map<char, unordered_set<char>>` to avoid duplicate edges.

2. **Topological Sorting with DFS**

   * Use a `state` map to track node status:

     * `0`: unvisited
     * `1`: visiting
     * `2`: visited
   * For each node:

     * Mark as visiting.
     * DFS into neighbors.
     * If a neighbor is `visiting` → **cycle** detected → return `""`.
     * After visiting all neighbors, mark node as `visited` and append it to the output.

3. **Reverse the Output**

   * Since DFS adds nodes post-order, reverse the final string to get correct order.

### **Time & Space Complexity**

| Metric | Complexity                   |
| ------ | ---------------------------- |
| Time   | O(V + E)                     |
| Space  | O(V + E) (recursion + graph) |

### **Pros**

✅ Elegant and direct implementation
✅ Easy cycle detection with DFS state tracking
✅ No need for explicit indegree tracking

### **Cons**

❌ Recursive depth could be large
❌ Harder to debug compared to Kahn’s

---

## ⚡ Comparison Summary

| Feature                 | **Kahn’s Algorithm (BFS)**            | **DFS Approach**                           |
| ----------------------- | ------------------------------------- | ------------------------------------------ |
| **Method**              | Level-by-level processing             | Post-order DFS traversal                   |
| **Cycle Detection**     | Indegree count                        | Visited-state tracking                     |
| **Data Structures**     | Queue + indegree map                  | Recursion + state map                      |
| **Result Construction** | During BFS                            | Reverse post-order                         |
| **Complexity**          | O(V + E)                              | O(V + E)                                   |
| **When to Use**         | Prefer iterative or level-based order | Prefer recursive/DFS-style graph traversal |

---

## 🧠 Key Observations

* Both methods are **topological sorts** of a **directed acyclic graph (DAG)**.
* Prefix violation check (`"abc"`, `"ab"`) is crucial to detect invalid lexicographic order.
* Both yield the same result — the main difference is **implementation style** (BFS vs DFS).

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
207. Course Schedule - https://leetcode.com/problems/course-schedule/description/
630. Course Schedule III - https://leetcode.com/problems/course-schedule-iii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Inferring language order, build-system dependency resolution 