//Brute-Force Approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet); // set avoids duplicates
                    }
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};

//Optimized Approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            if(nums[i]>0) break; // if nums[i]>0, sum will always be > 0
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                     left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
           
        }
        return res;
    }
};