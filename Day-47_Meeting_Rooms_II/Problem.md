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
## 🪜 Step 1: Brute Force Approach

### **Idea**

Simulate the assignment of meetings to rooms one by one:

* Sort meetings by start time.
* For each meeting, check if it can reuse any existing room (whose meeting has already ended).
* If not, allocate a new room.

---

### **Steps**

1. Sort all meetings by their start time.
2. Maintain a list `endTimes` — stores the end time of each room’s ongoing meeting.
3. For each meeting:

   * If its start time ≥ any room’s end time → reuse that room (update end time).
   * Else → allocate a new room (add new end time).
4. Finally, the number of rooms = `endTimes.size()`.

---

### **Complexity**

| Measure | Value                                              |
| ------- | -------------------------------------------------- |
| Time    | O(n²) (for each meeting, linear scan to find room) |
| Space   | O(n)                                               |

✅ Easy to understand and implement
❌ Inefficient for large input due to repeated scanning

---

## 🪜 Step 2: Min-Heap (Priority Queue) Approach

### **Idea**

Always keep track of the **earliest ending meeting** using a **min-heap**.
This way, we can efficiently decide whether to reuse a room or allocate a new one.

---

### **Steps**

1. Sort all intervals by start time.
2. Initialize a min-heap that stores end times of ongoing meetings.
3. For each meeting:

   * If current start ≥ earliest end (heap top), pop it → reuse that room.
   * Otherwise, need a new room.
   * Push the current meeting’s end time into heap.
4. The heap size = number of rooms needed at that point.
5. Return final heap size.

---

### **Complexity**

| Measure | Value                                  |
| ------- | -------------------------------------- |
| Time    | O(n log n) (sorting + heap operations) |
| Space   | O(n)                                   |

✅ Efficient and widely used solution
✅ Automatically manages room availability
⚠️ Requires understanding of heap behavior

---

## 🪜 Step 3: Two Pointer Approach

### **Idea**

Treat the problem as two sorted event lists — one for **start times** and one for **end times**.
Move pointers through them to track when rooms become available.

---

### **Steps**

1. Extract all `start` and `end` times into two arrays.
2. Sort both arrays.
3. Initialize:

   * `rooms = 0`
   * `endPtr = 0`
4. Traverse each meeting start time:

   * If current start < earliest end → new room needed (`rooms++`).
   * Else → one room freed (`endPtr++`).
5. The maximum `rooms` value observed = required number of rooms.

---

### **Complexity**

| Measure | Value                    |
| ------- | ------------------------ |
| Time    | O(n log n) (for sorting) |
| Space   | O(n)                     |

✅ Clean, elegant, and intuitive
✅ Slightly simpler than heap-based approach
⚠️ Requires careful pointer handling

---

## 🪜 Step 4: Sweep Line (Event Counting) Approach

### **Idea**

Transform start and end times into **events**.
Track the number of ongoing meetings dynamically while sweeping through the timeline.

---

### **Steps**

1. For each meeting:

   * Record `(start, +1)` → meeting begins.
   * Record `(end, -1)` → meeting ends.
2. Sort all events by time:

   * If same time → process end (`-1`) before start (`+1`) to avoid counting overlap incorrectly.
3. Traverse events sequentially:

   * Maintain a running count of active meetings (`rooms += ±1`).
   * Track the maximum count reached — that’s the minimum rooms required.

---

### **Complexity**

| Measure | Value      |
| ------- | ---------- |
| Time    | O(n log n) |
| Space   | O(n)       |

✅ Very intuitive and efficient
✅ Works great for visualizing overlaps
⚠️ Requires careful sorting logic when start == end

---

## 🧾 Final Comparison

| Approach         | Technique                         | Time       | Space | Notes                      |
| ---------------- | --------------------------------- | ---------- | ----- | -------------------------- |
| **Brute Force**  | Check room reuse linearly         | O(n²)      | O(n)  | Simple but slow            |
| **Min-Heap**     | Track earliest ending meeting     | O(n log n) | O(n)  | Fast + standard solution   |
| **Two Pointers** | Compare sorted start & end arrays | O(n log n) | O(n)  | Clean and efficient        |
| **Sweep Line**   | Process start/end events          | O(n log n) | O(n)  | Elegant event-based method |

---

## 💡 Key Takeaways

* **Sorting by start time** is common in all optimized approaches.
* The **Min-Heap approach** is most popular and interview-friendly.
* **Two Pointer** and **Sweep Line** methods are elegant alternatives with the same complexity.
* **Brute Force** is useful for intuition building but not practical for large input.

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
