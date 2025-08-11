> [Minimum Number of Platforms required for a railway] - https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy with sorted arrays
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* For each train, check how many trains are at the station **at the same time**.
* Keep track of the maximum overlap.
---

### **Step-by-Step**
1. Loop through each train `i`.
2. For each train `j`, check if:
   * `arr[i]` is between `arr[j]` and `dep[j]` (inclusive) → means overlap.
3. Count overlaps for each train.
4. Keep the maximum count — that’s the answer.
---

### **Complexity**
* **Time:** O(N²) → Nested loops for checking overlaps.
* **Space:** O(1) → No extra data structure.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach  –  (Sorting + Two Pointers)**

### **Idea**
* If arrival is before or equal to a departure → need **another platform**.
* If arrival is after a departure → a platform is freed.
* Sort arrivals and departures separately, then process in time order.
---

### **Step-by-Step**
1. Sort `arr[]` and `dep[]`.
2. Initialize:
   * `count = 0` (current trains at station)
   * `ans = 1` (max platforms so far)
3. Use two pointers:
   * If `arr[i] <= dep[j]` → `count++`, move `i` forward.
   * Else → `count--`, move `j` forward.
4. Update `ans` as the max of itself and `count`.
5. Return `ans`.
---

### **Complexity**
* **Time:** O(N log N) → Sorting dominates.
* **Space:** O(1) → Constant extra space.
---

### **Why Optimized Works**
By sorting arrivals and departures:
* We simulate the **timeline** of events.
* Always know when a platform is occupied or freed.
* Avoids unnecessary comparisons from brute force.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
759. Employee Free Time - https://leetcode.com/problems/employee-free-time/description/
1094. Car Pooling - https://leetcode.com/problems/car-pooling/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Airport runway allocation, traffic scheduling.