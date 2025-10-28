//Brute Force Approach 
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<int> endTimes;

    for (auto& meeting : intervals) {
        bool placed = false;
        for (int& end : endTimes) {
            if (meeting[0] >= end) { // room is free
                end = meeting[1];
                placed = true;
                break;
            }
        }
        if (!placed) endTimes.push_back(meeting[1]);
    }
    return endTimes.size();
}


//Optimized Approach using Min-Heap
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Min-heap to track earliest ending meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 3: Add first meeting
        minHeap.push(intervals[0][1]);

        // Step 4: Process remaining meetings
        for (int i = 1; i < intervals.size(); i++) {
            // If current meeting starts after earliest one ends → reuse room
            if (intervals[i][0] >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(intervals[i][1]);
        }

        // Step 5: Heap size = number of rooms used
        return minHeap.size();
    }
};


//Optimized Approach using Two Pointers
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> start, end;
        for (auto& i : intervals) {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0, endPtr = 0;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] < end[endPtr]) {
                rooms++;  // need new room
            } else {
                endPtr++; // room freed
            }
        }

        return rooms;
    }
};

//Sweep Line Approach
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;

        // Mark each start time as +1, and end time as -1
        for (auto& it : intervals) {
            events.push_back({it[0], +1}); // meeting starts
            events.push_back({it[1], -1}); // meeting ends
        }

        // Sort events by time
        // If same time → process end (-1) before start (+1)
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second; // end before start if same time
            return a.first < b.first;
        });

        int rooms = 0, maxRooms = 0;
        for (auto& e : events) {
            rooms += e.second;          // +1 start, -1 end
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};
