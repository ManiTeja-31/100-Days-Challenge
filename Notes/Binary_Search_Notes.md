# 📌 `lower_bound` & `upper_bound` in C++

## 1️⃣ Introduction

Both `lower_bound` and `upper_bound` are **binary search** based functions in C++ STL that work on **sorted** ranges (arrays, vectors, etc.).

They are defined in:
```cpp
#include <algorithm>
````


## 2️⃣ Function Signatures

```cpp
iterator lower_bound(iterator first, iterator last, const T& value);
iterator upper_bound(iterator first, iterator last, const T& value);
```

* **Time Complexity:** `O(log n)` (binary search)
* **Requirement:** Container must be **sorted in non-decreasing order**.

---

## 3️⃣ Core Difference

| Function      | What it Returns                        | Example in `[1, 2, 4, 4, 5, 7]` (search for `4`) |
| ------------- | -------------------------------------- | ------------------------------------------------ |
| `lower_bound` | Iterator to **first element >= value** | Points to **first 4**                            |
| `upper_bound` | Iterator to **first element > value**  | Points to **5**                                  |

---

## 4️⃣ Examples

### Example 1: Using `lower_bound`

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 2, 4, 4, 5, 7};
    auto it = lower_bound(v.begin(), v.end(), 4);
    cout << (it - v.begin()); // Output: 2 (index of first 4)
}
```

### Example 2: Using `upper_bound`

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 2, 4, 4, 5, 7};
    auto it = upper_bound(v.begin(), v.end(), 4);
    cout << (it - v.begin()); // Output: 4 (index of first > 4 i.e., 5)
}
```

---

## 5️⃣ Common Use Cases

### 1. **Finding the first occurrence of a value**

```cpp
int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
if (idx < v.size() && v[idx] == x) {
    // Found at idx
}
```

### 2. **Finding the last occurrence of a value**

```cpp
int idx = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
if (idx >= 0 && v[idx] == x) {
    // Found at idx
}
```

### 3. **Counting occurrences of a value**

```cpp
int count = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
```

### 4. **Finding insertion position**

* `lower_bound` → Position where `x` should be inserted to keep array sorted **before any equal elements**.
* `upper_bound` → Position where `x` should be inserted **after all equal elements**.

### 5. **Range queries (Number of elements in \[L, R])**

```cpp
int cnt = upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L);
```

---

## 6️⃣ Tips & Tricks

✅ **Use only on sorted ranges.**
Using them on unsorted data gives **undefined results**.

✅ Works with:

* `vector`, `array`, `deque` → `O(log n)` time
* `set`, `multiset` → `O(log n)` time
* `map`, `multimap` (using key iterators) → `O(log n)` time

✅ **For custom sorting** → Pass comparator:

```cpp
auto it = lower_bound(v.begin(), v.end(), val, comp);
```

✅ **Edge case handling:**

```cpp
auto it = lower_bound(v.begin(), v.end(), val);
if (it == v.end()) {
    // All elements < val
}
```

✅ **Binary search without writing logic yourself**

* Prefer `lower_bound`/`upper_bound` over manual binary search to avoid bugs.

---

## 7️⃣ Common Mistakes

❌ Forgetting to sort before using → Wrong results.
❌ Accessing `it - 1` when `it == v.begin()` → Out of bounds.
❌ Using them on **descending order** without custom comparator.

---

## 8️⃣ Suggested Usage Patterns

### **Find if element exists**

```cpp
bool exists = binary_search(v.begin(), v.end(), x);
```

### **Find range of same values**

```cpp
auto range = equal_range(v.begin(), v.end(), x);
// range.first = lower_bound
// range.second = upper_bound
```

---

## 9️⃣ Pro Suggestions

* **When to choose which:**

  * **`lower_bound`** → "First position where element ≥ value"
  * **`upper_bound`** → "First position where element > value"

* For **competitive programming**, memorize:

```cpp
lower_bound → ≥  
upper_bound → >
```

* To **find both first and last occurrence quickly**, use:

```cpp
firstIdx = lower_bound(v.begin(), v.end(), x) - v.begin();
lastIdx = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
```

* To **find number of elements in a range \[a, b]**:

```cpp
count = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
```

---

## 🔹 Quick Summary Table

| Function      | Condition  | Returns position of   |
| ------------- | ---------- | --------------------- |
| `lower_bound` | `>= value` | First element ≥ value |
| `upper_bound` | `> value`  | First element > value |

---

## 📚 Related Functions

* `binary_search()` → Checks if element exists (`O(log n)`)
* `equal_range()` → Returns both lower & upper bound iterators in one call

---

Here’s the **color-coded Mermaid diagram** for `lower_bound` vs `upper_bound` in C++.

---

````markdown
## 🎯 Visual Difference — `lower_bound` vs `upper_bound`

```mermaid

graph LR
    A[Array: 1 | 2 | 4 | 4 | 5 | 7]:::arr
    LB[lower_bound(4) → First ≥ 4]:::lb
    UB[upper_bound(4) → First > 4]:::ub

    A --> LB
    A --> UB

    style A fill:#e8f1f8,stroke:#333,stroke-width:2px
    style LB fill:#b0f2c2,stroke:#0a6,stroke-width:2px
    style UB fill:#ffb3b3,stroke:#a00,stroke-width:2px
    
````

### Color Meaning:

* 🟩 **Green (`lower_bound`)** → First element **≥ value**
* 🟥 **Red (`upper_bound`)** → First element **> value**
* 🟦 **Blue array** → Sorted container

---

### Example Walkthrough

For array: `[1, 2, 4, 4, 5, 7]` and `value = 4`:

* **`lower_bound(4)`** → index **2** (first 4)
* **`upper_bound(4)`** → index **4** (first > 4 → 5)

---


