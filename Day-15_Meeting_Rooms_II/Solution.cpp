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

//Optimized Approach - Priority Queue
class Solution {
public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;
        int n = start.size();
        for(int i = 0; i < n; ++i)
            meetings.push_back({start[i], end[i]});
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &m : meetings) {
            if(!pq.empty() && pq.top() <= m.first)
                pq.pop();
            pq.push(m.second);
        }
        return pq.size();
    }
};

//Optimized Approach - Sorting + Two Pointer
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n=start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int count =0,ans=0;
        int i=0,j=0;
        while(i<n && j<n){
            if(start[i] < end[j]){
                i++;
                count++;
            }else{
                j++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};

