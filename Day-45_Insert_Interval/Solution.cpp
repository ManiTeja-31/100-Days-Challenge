//Optimized Approach
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        int flag = true;
        for(int i=0;i<n;i++){
            if(flag && newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                flag=false;
            }else if(flag && newInterval[0] <= intervals[i][1]){
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        if(flag){
            res.push_back(newInterval);
        }
        return res;
    }
};

//Optimized Approach - remove flag variable
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                newInterval = {INT_MAX,INT_MAX};
            }else if(newInterval[0] <= intervals[i][1]){
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        if(newInterval[0]!=INT_MAX){
            res.push_back(newInterval);
        }
        return res;
    }
};


// Approach 3: Single pass with direct merging
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};

// Approach 4: Using binary search to find insertion point
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[0];
        };
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, comp);
        vector<vector<int>> res(intervals.begin(), it);
        while (it != intervals.end() && it->at(0) <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], it->at(0));
            newInterval[1] = max(newInterval[1], it->at(1));
            ++it;
        }
        res.push_back(newInterval);
        res.insert(res.end(), it, intervals.end());
        return res;
    }
};

// Approach 5: In-place modification (if allowed)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
}