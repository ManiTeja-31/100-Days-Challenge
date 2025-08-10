> [Minimum Number Of Arrows To Burst Balloons] - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
> level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy + Interval Merge
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* Go through each balloon.
* If it’s already burst, skip it.
* Otherwise, shoot an arrow at its end coordinate.
* Then check **all balloons** to see if this arrow bursts them.
* Mark burst balloons so they’re skipped in future.
---
### **Step-by-Step**
1. Keep a `burst[]` array to mark whether a balloon is already burst.
2. Loop through each balloon:
   * If not burst:
     * Increment arrow count.
     * Shoot at the end of this balloon.
     * Mark all overlapping balloons as burst.
3. Continue until all balloons are burst.
---

### **Example**

```
points = [[10,16],[2,8],[1,6],[7,12]]

Shoot at balloon [10,16] end → bursts [10,16] & [7,12]
Shoot at balloon [2,8] end → bursts [2,8] & [1,6]

Total = 2 arrows
```

---
### **Complexity**
* **Time:** O(N²) → For each balloon, we may check all others.
* **Space:** O(N) → `burst[]` array.
---
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### **Idea**
* If balloons overlap, **one arrow** can burst them all.
* The optimal point to shoot is at the **end** of the first balloon in sorted order.
* If the next balloon starts after this end, it can’t be burst by the same arrow → need a new arrow.
---
### **Step-by-Step**
1. Sort balloons by **end coordinate**.
2. Place first arrow at the end of the first balloon.
3. For each balloon:
   * If `start > end` (current arrow’s reach), shoot a new arrow at this balloon’s end.
   * Otherwise, the current arrow already bursts it.
4. Count total arrows.
---
### **Example**

```
points = [[10,16],[2,8],[1,6],[7,12]]
Sort by end → [[1,6],[2,8],[7,12],[10,16]]

Arrow at 6 → bursts [1,6] & [2,8]
Arrow at 12 → bursts [7,12] & [10,16]

Total = 2 arrows
```

---
### **Complexity**
* **Time:** O(N log N) → Sorting dominates.
* **Space:** O(1) extra (if we sort in place).
---
### **Why This Works**
This is a **classic interval scheduling problem**.
By always shooting at the earliest finishing balloon, we maximize overlap and minimize arrows.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
56. Merge Intervals - https://leetcode.com/problems/merge-intervals/description/
435. Non-overlapping Intervals - https://leetcode.com/problems/non-overlapping-intervals/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Grouping overlapping requests (e.g., bulletproof windows).






### **Idea**

* Go through each balloon.
* If it’s already burst, skip it.
* Otherwise, shoot an arrow at its end coordinate.
* Then check **all balloons** to see if this arrow bursts them.
* Mark burst balloons so they’re skipped in future.

---

### **Step-by-Step**

1. Keep a `burst[]` array to mark whether a balloon is already burst.
2. Loop through each balloon:

   * If not burst:

     * Increment arrow count.
     * Shoot at the end of this balloon.
     * Mark all overlapping balloons as burst.
3. Continue until all balloons are burst.

---

### **Example**

```
points = [[10,16],[2,8],[1,6],[7,12]]

Shoot at balloon [10,16] end → bursts [10,16] & [7,12]
Shoot at balloon [2,8] end → bursts [2,8] & [1,6]

Total = 2 arrows
```

---

### **Complexity**

* **Time:** O(N²) → For each balloon, we may check all others.
* **Space:** O(N) → `burst[]` array.

---




