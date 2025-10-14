//Recursive Approach
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(0,0,nums,target);
    }
    int helper(int ind,int sum,vector<int> &nums,int target){
        if(sum==target && ind==nums.size()){
            return 1;
        }
        if(ind>=nums.size()){
            return 0;
        }
        int plus = helper(ind+1,sum+nums[ind],nums,target);
        int minus = helper(ind+1,sum-nums[ind],nums,target);
        return plus + minus;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // Maximum sum can be 1000 (each element ≤ 1000, n ≤ 20)
        int sumOffset = 1000;
        vector<vector<int>> memo(n, vector<int>(2 * sumOffset + 1, -1));
        return helper(0, 0, nums, target, memo, sumOffset);
    }

    int helper(int ind, int sum, vector<int>& nums, int target,
               vector<vector<int>>& memo, int offset) {
        if (ind == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if (memo[ind][sum + offset] != -1) {
            return memo[ind][sum + offset];
        }

        int plus = helper(ind + 1, sum + nums[ind], nums, target, memo, offset);
        int minus = helper(ind + 1, sum - nums[ind], nums, target, memo, offset);

        memo[ind][sum + offset] = plus + minus;
        return memo[ind][sum + offset];
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        // Check for impossible case
        if (total < abs(target) || (total + target) % 2 != 0) return 0;

        int newTarget = (total + target) / 2;
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = newTarget; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[newTarget];
    }
};
