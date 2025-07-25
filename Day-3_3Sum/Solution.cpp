//Brute Force Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> Myset;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        Myset.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        for (auto triplet : Myset) {
            ans.push_back(triplet);
        }
        return ans;
    }
};


// Optimized Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;
                    while(l<r && nums[r]==nums[r-1])r--;
                    l++,r--;
                }else if(sum<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};

// Hashset Approach 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            for(int j = i+1; j < n; ++j) {
                int target = -nums[i] - nums[j];
                if(seen.count(target)) {
                    vector<int> triplet = {nums[i], nums[j], target};
                    sort(triplet.begin(), triplet.end());
                    res.insert(triplet);
                }
                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
