//Brute Force Approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};


//Optimized Approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> Hash;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(Hash.find(target-nums[i])!=Hash.end())
            {
                ans.push_back(Hash[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            Hash[nums[i]] = i;
        }
        return ans;
    }
};
