> [Partition Labels] - https://leetcode.com/problems/partition-labels/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
Greedy + Last occurences Tracking
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Brute Force Thought Process**
1. Start from the first character.
2. Track all unique characters in the current segment.
3. Keep extending the segment until **none** of these characters appear later in the string.
4. Once found, cut the segment and move to the next.
5. Repeat until the end of the string.


### **Step-by-Step Walkthrough**
Let’s take `s = "ababcbacadefegdehijhklij"`.
#### 1. Initialize
* `res` = empty list to store segment sizes.
* `start` = 0 → pointer for the start of the current segment.
#### 2. Outer Loop (segment building)
* While `start < n`, create a new segment.
#### 3. Add first char to `seen`
* Example: At start = 0, `seen = {a}`.
#### 4. Inner Loop (extend segment)
* For each index `i` from `start` to end:
  * Add `s[i]` to `seen`.
  * Check every character in `seen`:
    * If any character appears again **later in the string** → this segment isn’t finished.
    * If **none** appear later → we found the end of the segment.
#### 5. Cut the segment
* Calculate size: `end - start + 1`.
* Push size to `res`.
* Move `start` to `end + 1`.
#### 6. Repeat until full string is processed.

### **Why This Works**

* We ensure that no character crosses segments.
* By checking all characters in the current segment, we guarantee correctness.


### **Example Dry Run**
`s = "ababcbacadefegdehijhklij"`
1. Segment 1: `ababcbaca` → size 9
2. Segment 2: `defegde` → size 7
3. Segment 3: `hijhklij` → size 8

Output: `[9, 7, 8]`


### **Complexity Analysis**

* **Time Complexity:**
  * Outer loop runs O(N).
  * Inner loop checks `seen` and uses `find()` (O(N)) for each char.
  * Worst case: **O(N²)**.

* **Space Complexity:**
  * `seen` stores unique characters → at most 26 letters.
  * **O(1)** extra space (constant alphabet size).

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

🧠 Time & Space Complexity:
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
56. Merge Intervals - https://leetcode.com/problems/merge-intervals/description/
2405. Optimal Partition of String - https://leetcode.com/problems/optimal-partition-of-string/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
File chunking where dependencies are in local partitions.