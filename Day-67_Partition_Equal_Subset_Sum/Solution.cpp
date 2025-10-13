//Recursive Approach
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int targetSum=sum/2;
        return backTrack(0,nums,targetSum);
    }
    bool backTrack(int ind,vector<int> &nums,int target){
        if(target==0){
            return true;
        }
        if(target<0 || ind>=nums.size()){
            return false;
        }
        bool notPick = backTrack(ind+1,nums,target);
        bool pick = backTrack(ind+1,nums,target-nums[ind]);
        return pick | notPick;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int targetSum=sum/2;
        vector<vector<int>> memo(n,vector<int> (targetSum+1,-1));
        return backTrack(0,nums,targetSum,memo);
    }
    bool backTrack(int ind,vector<int> &nums,int target,vector<vector<int>> &memo){
        if(target==0){
            return true;
        }
        if(target<0 || ind>=nums.size()){
            return false;
        }
        if(memo[ind][target]!=-1){
            return memo[ind][target];
        }

        bool notPick = backTrack(ind+1,nums,target,memo);
        bool pick = backTrack(ind+1,nums,target-nums[ind],memo);
        return memo[ind][target] = pick | notPick;
    }
};

//Bottom-Up DP with Tabulation (using 1D array)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int targetSum=sum/2;
        vector<bool> dp(targetSum+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            for(int j=targetSum;j>=nums[i];j--){
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        return dp[targetSum];
    }
};

//Bottom-Up DP with Tabulation (using 2D array)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int n = nums.size();
        int target = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Build the dp table
        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                if (sum >= nums[i - 1]) {
                    // pick or not pick the current number
                    dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - nums[i - 1]];
                } else {
                    // can't pick, just carry forward
                    dp[i][sum] = dp[i - 1][sum];
                }
            }
        }

        return dp[n][target];
    }
};

