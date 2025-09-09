// All Approaches for Merge Intervals
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class SolutionBruteForce {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> merged(n, false);
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (merged[i]) continue;
            int start = intervals[i][0], end = intervals[i][1];
            for (int j = i + 1; j < n; ++j) {
                if (!merged[j] && !(intervals[j][1] < start || intervals[j][0] > end)) {
                    start = min(start, intervals[j][0]);
                    end = max(end, intervals[j][1]);
                    merged[j] = true;
                }
            }
            res.push_back({start, end});
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// Stack Approach
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class SolutionStack {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> top = st.top();
            if (top[1] >= intervals[i][0]) {
                st.pop();
                top[1] = max(top[1], intervals[i][1]);
                st.push(top);
            } else {
                st.push(intervals[i]);
            }
        }
        vector<vector<int>> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// In-place Merge Approach (Space Optimized)
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding output)
class SolutionInPlace {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[idx][1] >= intervals[i][0]) {
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            } else {
                ++idx;
                intervals[idx] = intervals[i];
            }
        }
        intervals.resize(idx + 1);
        return intervals;
    }
};

// Optimal Approach (Sorting + Merging)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(!res.empty() && intervals[i][0] <=res.back()[1] ){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};