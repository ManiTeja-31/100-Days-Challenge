//Brute Force Appraoch
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            // Create a copy of nums without element at index i
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                if (j != i) temp.push_back(nums[j]);
            }

            // Count max sequence of 1s in temp
            int curr = 0, localMax = 0;
            for (int val : temp) {
                if (val == 1) {
                    curr++;
                    localMax = max(localMax, curr);
                } else {
                    curr = 0;
                }
            }

            maxLen = max(maxLen, localMax);
        }

        return maxLen;
    }
};

//Sliding Window Approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        int ind=-1,count=0;
        int longest=0;
        while(right<n){
            if(nums[right]==0){
                if(ind!=-1){
                    left=ind+1;
                }
                ind=right;
            }
            longest = max(longest, right-left);
            right++;
        }
        return longest;
    }
};