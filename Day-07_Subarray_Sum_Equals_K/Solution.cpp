//Brute force approach
class Solution {
public:
int count=0;
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum==k)count++;
            }
        }
        return count;
    }
};

//Optimized approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int count=0;
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(prefix[i]==k){
                count++;
            }
            if(mp.find(prefix[i]-k)!=mp.end()){
                count+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};
// Optimized Approach using Hash Map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Step 1: Initialize variables
        int n = nums.size(), count = 0, sum = 0;
        // Step 2: Create a hash map to store prefix sums
        unordered_map<int, int> mp;
        mp[0] = 1;  // Initial prefix sum 0 with one occurrence
        
        // Step 3: Traverse through the array
        for (int i = 0; i < n; i++) {
            // Step 4: Update the running sum
            sum += nums[i];
            
            // Step 5: Check if there's a prefix sum that matches (sum-k)
            if (mp.find(sum - k) != mp.end()) {
                // Step 6: If found, add its occurrences to count
                count += mp[sum - k];
            }
            
            // Step 7: Update the prefix sum map with the current sum
            mp[sum]++;
        }
        // Step 8: Return the count of subarrays that sum to k
        return count;
    }
};

/*
Explanation:
- The problem is to find the number of subarrays with a sum equal to k.
- A prefix sum approach helps by calculating the sum of elements up to the current index.
- For a subarray sum to equal k, the difference between the current prefix sum and a previous prefix sum must be k.
- We use a hash map to store the number of occurrences of each prefix sum.
- By checking the map for (sum-k), we determine if a subarray ending at the current index sums to k.
- This approach efficiently handles the problem in O(n) time complexity with O(n) space complexity for the hash map.
*/
