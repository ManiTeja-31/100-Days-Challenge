> [Meeting Rooms II] - https://neetcode.io/problems/meeting-schedule-ii
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of days required to schedule all meetings without any conflicts.
Note: (0,8),(8,10) is not considered a conflict at 8.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy + Min Heap or Two Pointer
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* For each meeting, check how many other meetings **overlap** with it.
* Keep track of the maximum overlaps across all meetings.
---

### **Step-by-Step**
1. For each meeting `i`:
   * Count overlaps with all other meetings `j`.
   * Overlap condition:
     ```
     start[j] < end[i] && end[j] > start[i]
     ```
2. Track the max overlap count — this is the minimum number of rooms needed.
---

### **Complexity**
* **Time:** O(n²) — Compare every pair of meetings.
* **Space:** O(1) — No extra data structure used.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach 1 – Priority Queue (O(n log n))**

### **Idea**
* Sort meetings by **start time**.
* Use a **min-heap** to store **end times** of ongoing meetings.
* The heap size at any point = number of rooms in use.
---

### **Step-by-Step**
1. Sort meetings by start time.
2. Iterate over meetings:
   * If the earliest ending meeting (heap top) finishes before current meeting starts → reuse that room (pop from heap).
   * Otherwise → need a new room.
   * Push current meeting’s end time into heap.
3. The **maximum heap size** during process = answer.
---

### **Complexity**
* **Time:** O(n log n) — Sorting + heap operations.
* **Space:** O(n) — Heap for ongoing meetings.
---

## **Approach 2 – Sorting + Two Pointers (O(n log n))**

### **Idea**
* Instead of tracking rooms in a heap, use **two sorted arrays**:
  * One for start times
  * One for end times
* Use two pointers to simulate meeting starts and ends.
---

### **Step-by-Step**
1. Sort both start and end arrays.
2. Use two pointers `i` (start) and `j` (end).
3. Iterate:
   * If `start[i] < end[j]` → New meeting starts before earliest meeting ends → Need a new room (`count++`).
   * Else → Meeting ended before new one starts → Free a room (`count--`, move `j`).
4. Keep track of max `count` during iteration.
---

### **Complexity**
* **Time:** O(n log n) — Sorting.
* **Space:** O(1) — No extra DS except variables.
---

## **Why Multiple Approaches?**
* **Brute force** is simple to understand but too slow for large inputs.
* **Priority queue** is intuitive and efficient.
* **Two-pointer method** is the most space-efficient optimal approach.
---
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
435. Non-overlapping Intervals - https://leetcode.com/problems/non-overlapping-intervals/description/
986. Interval List Intersections - https://leetcode.com/problems/interval-list-intersections/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Room booking systems, CPU scheduling
