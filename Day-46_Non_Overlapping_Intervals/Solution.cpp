// Brute Force Approach (DP)
// Time: O(N^2), Space: O(N)
class SolutionBruteForce {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, 1);
        int maxNonOverlap = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxNonOverlap = max(maxNonOverlap, dp[i]);
        }
        return n - maxNonOverlap;
    }
};

// Greedy Approach (Optimal)
bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int prev=0,count=1;
        for(int i=1;i<n;i++){
            if(intervals[prev][1] <= intervals[i][0]){
                count++;
                prev=i;
            }
        }
        return n-count;
    }
};

// Alternative Greedy Approach (using lambda)
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int end = intervals[0][1], count = 0;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < end) {
                count++;
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }
};