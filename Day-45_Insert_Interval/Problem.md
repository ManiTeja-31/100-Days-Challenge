> [Insert Interval] - [LeetCode Problem Description](https://leetcode.com/problems/insert-interval/description/)  
> **Difficulty:** 🟠 Medium

---

## 📝 Problem Statement

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the ith interval and intervals is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

**Task:**  
Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

> **Note:** You don't need to modify intervals in-place. You can make a new array and return it.

---

## 🔍 Pattern

> **Interval Merging**

---

## 🛠️ Brute Force Approach

<details>
<summary><strong>Step-by-step Explanation</strong></summary>

1. **Add the New Interval:**  
   Append the new interval to the existing list. This ensures all intervals, including the new one, are considered for merging.

2. **Sort All Intervals:**  
   Sort the entire list of intervals based on their starting points. This is necessary because the new interval may not be in the correct position, and merging requires sorted intervals.

3. **Merge Overlapping Intervals:**  
   - Initialize an empty result list.
   - Iterate through the sorted intervals:
     - If the result list is empty or the current interval does not overlap with the last interval in the result, simply add it to the result.
     - If there is an overlap (i.e., the start of the current interval is less than or equal to the end of the last interval in the result), merge them by updating the end of the last interval in the result to be the maximum of both ends.

4. **Return the Result:**  
   After processing all intervals, the result list will contain the merged, non-overlapping intervals in sorted order.

</details>

---

## ⚡ Optimized Approach

<details>
<summary><strong>Approach 1: Using a Flag Variable</strong></summary>

1. **Iterate Through Intervals:**  
   Go through each interval in the list.

2. **Check Position of New Interval:**  
   - If the new interval ends before the current interval starts and hasn't been inserted yet, insert the new interval into the result and set a flag to indicate it has been inserted.
   - If the new interval overlaps with the current interval, merge them by updating the start to the minimum and the end to the maximum of both intervals.
   - If neither condition is met, add the current interval to the result.

3. **Insert New Interval if Not Added:**  
   After the loop, if the flag indicates the new interval hasn't been added, append it to the result.

4. **Return the Result:**  
   The result now contains all intervals in the correct order, with overlaps merged.

</details>

<details>
<summary><strong>Approach 2: Removing the Flag Variable</strong></summary>

1. **Iterate Through Intervals:**  
   Traverse each interval.

2. **Insert and Mark New Interval:**  
   - If the new interval ends before the current interval starts, insert it and set its value to a dummy interval (e.g., `{INT_MAX, INT_MAX}`) to mark it as inserted.
   - If the new interval overlaps with the current interval, merge them by updating the start and end.
   - Otherwise, add the current interval to the result.

3. **Final Check for New Interval:**  
   After the loop, if the new interval is not the dummy value, add it to the result.

4. **Return the Result:**  
   The result contains all intervals, merged and sorted.

</details>

<details>
<summary><strong>Approach 3: Single Pass with Direct Merging</strong></summary>

1. **Add Non-Overlapping Intervals Before New Interval:**  
   Add all intervals that end before the new interval starts directly to the result.

2. **Merge Overlapping Intervals:**  
   For intervals that overlap with the new interval, update the new interval's start and end to encompass all overlaps.

3. **Add the Merged Interval:**  
   After merging, add the new (possibly updated) interval to the result.

4. **Add Remaining Intervals:**  
   Add all intervals that start after the new interval ends.

5. **Return the Result:**  
   The result contains the correct merged intervals.

</details>

<details>
<summary><strong>Approach 4: Binary Search for Insertion Point</strong></summary>

1. **Find Insertion Point:**  
   Use binary search to find the first interval whose end is not less than the new interval's start.

2. **Add Intervals Before Insertion Point:**  
   Add all intervals before this point to the result.

3. **Merge Overlapping Intervals:**  
   Merge all intervals that overlap with the new interval by updating the new interval's start and end.

4. **Add the Merged Interval:**  
   Insert the merged interval into the result.

5. **Add Remaining Intervals:**  
   Add all intervals after the merged interval.

6. **Return the Result:**  
   The result contains all intervals, merged and sorted.

</details>

<details>
<summary><strong>Approach 5: In-place Modification</strong></summary>

1. **Append New Interval:**  
   Add the new interval to the intervals list.

2. **Sort the Intervals:**  
   Sort the intervals based on their starting points.

3. **Merge Overlapping Intervals:**  
   Iterate through the sorted intervals, merging any overlapping intervals into the result list.

4. **Return the Result:**  
   The result contains all intervals, merged and sorted.

</details>

---

## 🔗 Other Problems Using this Approach

- [2276. Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/description/)
- [986. Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/description/)
- [715. Range Module](https://leetcode.com/problems/range-module/description/)

---

## 🥘 CodeChef Equivalent

**N/A**

---

## 🌍 Real-World Use

> Insert time slot