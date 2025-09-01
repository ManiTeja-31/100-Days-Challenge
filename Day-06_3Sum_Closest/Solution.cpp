//Brute force Approach
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(target - sum) < abs(target - closest))
                        closest = sum;
                }
            }
        }
        return closest;
    }
};

//Optimized Approach
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int close=INT_MAX, ans;
        for(int i=0;i<n;i++)
        {
            int l=i+1,r=n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(close > abs(sum-target)){
                    close = abs(sum-target);
                    ans=sum;
                }
                if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};