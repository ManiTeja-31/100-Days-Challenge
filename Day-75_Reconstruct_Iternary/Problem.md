> [332. Reconstruct Itinerary] - https://leetcode.com/problems/reconstruct-itinerary/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> DFS + Eulerian Path
--------------------------------------------------------------------------------------------------------------------------------------
## 1️⃣ DFS (Recursive) Approach

### **Idea**

Use **Hierholzer’s Algorithm** to find an **Eulerian Path** — a path that visits every edge exactly once.

We represent the flight connections as a **directed graph**, and perform a **post-order DFS traversal**:

* Always take the **lexicographically smallest destination** first.
* Once a node has no further destinations, add it to the result list (post-order).

### **Steps**

1. Build graph using `map<string, multiset<string>>`

   * `map` → keeps keys sorted (airports).
   * `multiset` → keeps destinations in lexicographical order.
2. Start DFS from `"JFK"`.
3. Recursively explore destinations:

   * While current airport has outgoing flights:

     * Pick the **smallest** destination (from multiset).
     * Remove the edge and recurse.
4. Once no more outgoing edges, add airport to the result (backtracking phase).
5. Reverse result to get correct itinerary order.

### **Pseudocode**

```cpp
dfs("JFK"):
    while graph[src] not empty:
        next = smallest destination
        remove edge(src, next)
        dfs(next)
    add src to result
```

### **Complexity**

| Measure | Cost                                                   |
| ------- | ------------------------------------------------------ |
| Time    | O(E log E) → `log E` due to multiset insertion/removal |
| Space   | O(V + E) for recursion and graph                       |

### **Pros**

✅ Simple, elegant recursive logic
✅ Automatically ensures lexicographical order
✅ Matches Hierholzer’s algorithm perfectly

### **Cons**

❌ Recursion depth can be large for big graphs

---

## 2️⃣ Stack (Iterative) Approach

### **Idea**

Iterative version of **Hierholzer’s algorithm** — avoids recursion.
Use a **stack** to simulate DFS and a **priority queue** to pick the smallest destination.

### **Steps**

1. Build graph using
   `unordered_map<string, priority_queue<string, vector<string>, greater<string>>>`
   → ensures smallest destination is chosen first.
2. Push `"JFK"` to stack.
3. While stack not empty:

   * Look at top of stack → `curr`.
   * If `curr` has available destinations:

     * Push next smallest destination to stack.
   * Else:

     * Pop it and add to itinerary result.
4. Reverse the result at the end.

### **Pseudocode**

```cpp
st.push("JFK")
while st not empty:
    if graph[st.top()] not empty:
        next = smallest destination
        remove edge
        st.push(next)
    else:
        result.push_back(st.top())
        st.pop()
reverse(result)
```

### **Complexity**

| Measure | Cost                                               |
| ------- | -------------------------------------------------- |
| Time    | O(E log E) → `log E` for priority queue operations |
| Space   | O(V + E) (stack + graph storage)                   |

### **Pros**

✅ No recursion (stack-based simulation)
✅ Efficient and avoids recursion limits
✅ Same output and order as DFS

### **Cons**

❌ Slightly more verbose due to manual stack management

---

## ⚡ Comparison Summary

| Feature                     | DFS (Recursive)             | Stack (Iterative)           |
| --------------------------- | --------------------------- | --------------------------- |
| **Traversal Type**          | Recursive DFS               | Iterative DFS               |
| **Data Structure**          | `map + multiset`            | `unordered_map + min-heap`  |
| **Lexicographical Control** | via `multiset`              | via `priority_queue`        |
| **Time Complexity**         | O(E log E)                  | O(E log E)                  |
| **Space Complexity**        | O(V + E)                    | O(V + E)                    |
| **Recursion Depth**         | Can be deep                 | Avoided                     |
| **Order**                   | Post-order (reverse at end) | Post-order (reverse at end) |

---

## 💡 Key Insights

* Both solutions are based on **Hierholzer’s algorithm** for finding an **Eulerian path**.
* The itinerary is built **in reverse order** — add airport after exploring all edges from it.
* Using `multiset` or `priority_queue` ensures **lexicographically smallest path**.
* The **Stack-based** method is just a non-recursive version of the same DFS idea.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
1923. Longest Common Subpath - https://leetcode.com/problems/longest-common-subpath/description/
2097. Valid Arrangement of Pairs - https://leetcode.com/problems/valid-arrangement-of-pairs/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Flight routing, delivery paths, or logistic optimizations.