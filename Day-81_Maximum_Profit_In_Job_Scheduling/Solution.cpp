//Recursive Approach
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> job;
        int n=profit.size();
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        return maxProfit(0,-1,job);
    }
    int maxProfit(int ind,int prevInd,vector<vector<int>> &job){
        if(ind>=job.size()){
            return 0;
        }
        int notPick = maxProfit(ind+1,prevInd,job);
        int pick=0;
        if(prevInd==-1 || job[prevInd][1]<=job[ind][0]){
            pick = job[ind][2] + maxProfit(ind+1,ind,job);
        }
        return max(pick,notPick);
    }
};

//Brute Force Approach - Alternative
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> job;
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        return schedule(0,job);

    }
    int schedule(int ind,vector<vector<int>> &job){
        if(ind==job.size()){
            return 0;
        }
        int nextInd = next(ind,job);
        int pick = job[ind][2] + schedule(nextInd,job);
        int skip = schedule(ind+1,job);
        return max(pick,skip);
    }
    int next(int ind,vector<vector<int>> &job){
        int n=job.size();
        for(int j=ind+1;j<n;j++){
            if(job[j][0]>=job[ind][1]){
                return j;
            }
        }
        return n;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> job;
        vector<int> memo(n,-1);
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        return schedule(0,job,memo);

    }
    int schedule(int ind,vector<vector<int>> &job,vector<int> &memo){
        if(ind==job.size()){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        int nextInd = next(ind,job);
        int pick = job[ind][2] + schedule(nextInd,job,memo);
        int skip = schedule(ind+1,job,memo);
        return memo[ind] = max(pick,skip);
    }
    int next(int ind,vector<vector<int>> &job){
        int n=job.size();
        for(int j=ind+1;j<n;j++){
            if(job[j][0]>=job[ind][1]){
                return j;
            }
        }
        return n;
    }
};

//Top-Down DP with Binary Search
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> job;
        vector<int> memo(n,-1);
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        return schedule(0,job,memo);

    }
    int schedule(int ind,vector<vector<int>> &job,vector<int> &memo){
        if(ind==job.size()){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        int end = job[ind][1];
        int nextInd = lower_bound(
            job.begin(),
            job.end(),
            vector<int> {end,0,0},
            [](const vector<int> &a,const vector<int> &b){
                return a[0] < b[0];
            })-job.begin();
        int pick = job[ind][2] + schedule(nextInd,job,memo);
        int skip = schedule(ind+1,job,memo);
        return memo[ind] = max(pick,skip);
    }
    
};

//Top-Down DP with Binary Search (Using cmp function)
class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b){
        return a[0] < b[0];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> job;
        vector<int> memo(n,-1);
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        return schedule(0,job,memo);

    }
    int schedule(int ind,vector<vector<int>> &job,vector<int> &memo){
        if(ind==job.size()){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        int end = job[ind][1];
        int nextInd = lower_bound(job.begin(),job.end(),vector<int> {end,0,0},
cmp)-job.begin();
        int pick = job[ind][2] + schedule(nextInd,job,memo);
        int skip = schedule(ind+1,job,memo);
        return memo[ind] = max(pick,skip);
    }
    
};

//Bottom-Up DP with Binary Search
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; ++i) {
            int include = jobs[i][2];
            int l = binarySearch(jobs, i); // last non-overlapping job
            if (l != -1) include += dp[l];
            dp[i] = max(include, dp[i - 1]);
        }
        return dp[n - 1];
    }

    int binarySearch(vector<vector<int>>& jobs, int i) {
        int lo = 0, hi = i - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (jobs[mid][1] <= jobs[i][0]) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};

//Bottom-Up DP with Binary Search (Using cmp function)
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end(), cmp);

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; ++i) {
            int include = jobs[i][2];
            // Find the last job whose endTime <= jobs[i][0] using lower_bound
            int idx = lower_bound(
                jobs.begin(), jobs.begin() + i,
                vector<int>{0, jobs[i][0], 0},
                cmp
            ) - jobs.begin();
            if (idx > 0) include += dp[idx - 1];
            dp[i] = max(include, dp[i - 1]);
        }
        return dp[n - 1];
    }
};
