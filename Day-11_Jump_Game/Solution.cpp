//Brute Force Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(0,nums);
    }
    bool dfs(int ind, vector<int> &nums){
        if(ind==nums.size()-1){
            return true;
        }else if(ind>=nums.size()){
            return false;
        }
        int steps = nums[ind];
        bool flag=false;
        for(int i=1;i<=steps;i++){
           flag |= bfs(ind+i,nums);
        }
        return flag;
    }
};

//Using Memoziation Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return dfs(0,nums,dp);
    }
    bool dfs(int ind, vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1){
            return true;
        }
        if(dp[ind]!=-1) 
           return dp[ind];
        int steps = nums[ind];
        for(int i=1;i<=steps;i++){
            if(dfs(ind+i,nums,dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
};
//Optimized Approach - Greedy Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthestStep = nums[0];
        for(int i=1;i<n;i++){
            if(i > farthestStep){
                return false;
            }
            farthestStep = max(farthestStep, i+nums[i]);
        }
        return true;
    }
};

//Optimized Approach - Greedy Approach (Second Method)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
        return last==0;
    }
};