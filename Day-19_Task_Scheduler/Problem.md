> [Task Schediler] - https://leetcode.com/problems/task-scheduler/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
Return the minimum number of CPU intervals required to complete all tasks.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy + Frequency Bucket
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* At each unit of time, scan all tasks to see which is **available** (not on cooldown) and has the **highest remaining frequency**.
* If no task is available → idle.
* Keep doing this until all tasks are completed.
---

### **Step-by-Step**
1. Count frequency of each task.
2. Keep a cooldown map storing the next available time for each task.
3. For each time step:
   * Find the available task with **highest remaining count**.
   * Execute it, reduce count, and set its cooldown.
   * If none → idle (time still increases).
4. Stop when all tasks are done.
---

### **Complexity**
* **Time:** O(T²) in worst case → For each time step, scanning all tasks.
* **Space:** O(U) → Where U is number of unique tasks.

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach 1 – Optimal with Priority Queue**

### **Idea**
* Always execute the task with **highest remaining frequency** first (Greedy).
* Use a **max heap** to track frequencies.
* Work in **cycles** of length `n+1` (one execution + cooldown period).
---

### **Step-by-Step**
1. Count frequency of tasks, push into a max heap.
2. While heap not empty:
   * For a cycle of `n+1` steps:
     * Pick highest frequency task from heap, execute it, store remaining count in temp list.
     * If heap empty before cycle ends → idle for remaining cycle.
   * Push remaining tasks back into heap.
3. Repeat until heap empty.
---

### **Complexity**
* **Time:** O(T log U) → Heap operations for each task execution.
* **Space:** O(U) → Heap + temporary storage.

---
## **Approach 2 – Mathematical Formula**

### **Idea**
The bottleneck is determined by the **most frequent task**:
* Arrange them first, then fill gaps with other tasks.
* Formula:
  $$
  \text{time} = \max(\text{total tasks}, (maxFreq - 1) \times (n+1) + numMaxFreq)
  $$
Where:
* `maxFreq` = frequency of most frequent task.
* `numMaxFreq` = number of tasks having frequency equal to `maxFreq`.
---

### **Step-by-Step**
1. Count frequencies and find `maxFreq` and `numMaxFreq`.
2. Compute:
   * `(maxFreq - 1) * (n+1) + numMaxFreq`
   * Compare with total number of tasks (because when `n` is small, tasks might be packed without idle time).
3. Return the max.
---

### **Complexity**
* **Time:** O(T) → Just counting frequencies.
* **Space:** O(U) → Frequency map.
---

## **Why Multiple Approaches?**
* **Brute force** is easy to implement and explain, but slow.
* **Priority queue** is much faster and follows a greedy strategy.
* **Formula** is optimal when you can derive relationships directly — fastest in both time and space.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
767. Reorganize String - https://leetcode.com/problems/reorganize-string/description/
2365. Task Scheduler II - https://leetcode.com/problems/task-scheduler-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
 OS-level job scheduling, cooling period logic.
