> [127. Word Ladder] - https://leetcode.com/problems/word-ladder/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> BFS + Graph Construction
--------------------------------------------------------------------------------------------------------------------------------------
### ✅ BFS Approach (Unidirectional)

**Problem Summary:**
Transform `beginWord` to `endWord` by changing one character at a time. Each intermediate word must exist in `wordList`. Return the minimum number of transformations (word count in the path), or `0` if not possible.

---

**🔍 Intuition:**
This is a **shortest path** problem in an unweighted graph where:

* Each word is a node.
* An edge exists between two words if they differ by one character.

**✅ Approach:**

* Use **Breadth-First Search (BFS)** starting from `beginWord`.
* Try all possible one-letter transformations.
* If the transformed word is in the dictionary (`wordList`), add it to the queue and continue.
* Mark visited words by removing them from the set to prevent cycles.

---

**🧠 Steps:**

1. Convert `wordList` to a hash set (`unordered_set`) for **O(1)** lookup.
2. If `endWord` is not in the set, return `0` immediately.
3. Initialize a queue for BFS: each entry contains a `(word, depth)` pair.
4. While the queue is not empty:

   * Dequeue a word and its transformation depth.
   * For each position in the word, replace it with all 26 lowercase letters.
   * If the new word is in the set:

     * Add it to the queue with `depth + 1`.
     * Remove it from the set to avoid revisiting.
5. If `endWord` is reached, return the current depth.
6. If the queue is exhausted without finding the end word, return `0`.

---

**🕒 Time Complexity:**

* Let `L` = length of each word, `N` = number of words in `wordList`.
* For each word in the queue, we try `L × 26` transformations.
* In worst case, we process all `N` words.
* **Total: O(N × L × 26) → O(N × L)**

**💾 Space Complexity:**

* Word set: O(N)
* Queue: O(N)
* **Total: O(N × L)** for storing all possible transformations.

---

### ✅ Bidirectional BFS Approach (Optimized)

**🔍 Intuition:**
Instead of searching from just the **beginWord**, we search **both from beginWord and endWord** simultaneously. This reduces the number of levels explored and greatly improves performance in dense graphs.

---

**✅ Approach:**

* Initialize two sets: `beginSet` (from `beginWord`) and `endSet` (from `endWord`).
* Always expand the **smaller** set to reduce operations.
* Use a `visited` set to avoid revisiting words.
* For each word in the current set:

  * Try all possible one-letter changes.
  * If the transformed word is in the opposite set, return the current level + 1.
  * If the transformed word is in `wordList` and not visited, add to the next level’s set.

---

**🧠 Steps:**

1. Create a set from `wordList` for O(1) lookup.
2. Initialize `beginSet`, `endSet`, and `visited`.
3. While both sets are not empty:

   * Always expand the smaller set (optimization).
   * For each word in current set:

     * Change each character from `'a'` to `'z'`.
     * If result is in `endSet`, return `level + 1`.
     * If result is valid and not visited, add to next level set and mark visited.
   * Update current set to next level’s set.
4. If no connection found, return 0.

---

**🕒 Time Complexity:**

* In worst case, it's still **O(N × L)**.
* But because the search space is effectively halved, **actual performance is much better**.

**💾 Space Complexity:**

* Sets and visited tracking use O(N)
* **Total: O(N × L)**

---

### 🔁 Summary of Time & Space Complexities:

| Approach             | Time Complexity | Space Complexity | Notes                       |
| -------------------- | --------------- | ---------------- | --------------------------- |
| BFS (Unidirectional) | O(N × L)        | O(N × L)         | Slower for large word lists |
| Bidirectional BFS    | O(N × L)        | O(N × L)         | Much faster in practice     |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
126. Word Ladder II - https://leetcode.com/problems/word-ladder-ii/description/
2157. Groups of Strings - https://leetcode.com/problems/groups-of-strings/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Spell checkers, autocorrect systems, linguistic AI. 