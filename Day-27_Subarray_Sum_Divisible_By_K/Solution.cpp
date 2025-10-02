//Brute Force Approach
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum%k==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//Optimal Approach
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0, result = 0;

        // There are k mod groups 0...k-1.
        vector<int> modGroups(k);
        modGroups[0] = 1;

        for (int num : nums) {
            // Take modulo twice to avoid negative remainders.
            prefixMod = (prefixMod + num % k + k) % k;
            // Add the count of subarrays that have the same remainder as the current
            // one to cancel out the remainders.
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }

        return result;
    }
};

//Optimized Approach using HashMap
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, prefixMod=0;
        int n=nums.size();
        unordered_map<int,int> Hash;
        for(int i=0;i<n;i++){
            prefixMod= (prefixMod + nums[i] % k + k) % k;
            if(prefixMod==0){
                ans++;
            }
            if(Hash.find(prefixMod)!=Hash.end()){
                ans+=Hash[prefixMod];
            }
            Hash[prefixMod]++;
        }
        return ans;
    }
};