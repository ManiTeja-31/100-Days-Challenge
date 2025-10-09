
> [Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)
> **Level:** Medium

---

# Problem Statement

Given an array of intervals where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

---

# Pattern

**Sorting + Greedy**

---

# Brute Force Approach

**Step-by-step Explanation:**

```
1. Iterate through each interval in the list.
2. For every interval, compare it with all other intervals to check if they overlap.
3. If two intervals overlap, merge them into a single interval covering both ranges.
4. Mark intervals that have been merged to avoid processing them again.
5. After all comparisons, collect all merged intervals into a result list.
6. Sort the result list for consistency before returning.
```

---

# Optimized Approach

**Step-by-step Explanation:**

```
1. Sort all intervals based on their starting times.
2. Initialize an empty list to store merged intervals.
3. Traverse the sorted intervals one by one:
   - If the current interval overlaps with the last interval in the result list, merge them by updating the end time.
   - If there is no overlap, add the current interval to the result list.
4. Repeat until all intervals are processed.
5. Return the result list containing all merged intervals.
```

---

# Stack Approach

**Step-by-step Explanation:**

```
1. Sort all intervals based on their starting times.
2. Initialize a stack and push the first interval onto it.
3. For each subsequent interval:
   - If the interval overlaps with the interval on top of the stack, merge them and update the top.
   - If not, push the interval onto the stack.
4. After processing all intervals, pop all intervals from the stack to form the result list.
5. Return the result list containing merged intervals.
```

---

# In-place Merge Approach

**Step-by-step Explanation:**

```
1. Sort all intervals based on their starting times.
2. Use a pointer (index) to keep track of the position for merged intervals.
3. Traverse the intervals:
   - If the current interval overlaps with the interval at the pointer, merge them in-place.
   - If not, move the pointer forward and copy the current interval to that position.
4. After processing, resize the intervals list to contain only the merged intervals.
5. Return the resized list as the result.
```

---

# Other Problems Using this Approach

- [759. Employee Free Time](https://leetcode.com/problems/employee-free-time/description/)
- [2213. Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/)

---

# CodeChef Equivalent

NA

---

# Real-World Use

Insert time slot into calendar schedule