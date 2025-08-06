//Brute-force Approach
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int maxRooms = 0;
        for (int i = 0; i < n; ++i) {
            int rooms = 1;
            for (int j = 0; j < n; ++j) {
                // If the current interval overlaps with another interval, increment rooms
                // e.g. i = [1, 3], j = [2, 4], start < end && end > start => rooms++
                if (i != j && intervals[j].start < intervals[i].end && intervals[j].end > intervals[i].start) {
                    rooms++;
                }
            }
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};

//Optimized Approach
