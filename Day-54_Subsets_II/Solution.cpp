//Naive Backtracking + set to Remove Duplicates
class Solution {
public:
    set<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return vector<vector<int>> (res.begin(),res.end());
    }
    void dfs(int ind,vector<int> &nums){
        if(ind==nums.size()){
            res.insert(path);
            return;
        }
        dfs(ind+1,nums);
        path.push_back(nums[ind]);
        dfs(ind+1,nums);
        path.pop_back();
    }
};

//Optimal Backtracking with Duplicate Skipping
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return res;
    }
    void dfs(int start,vector<int> &nums){
        res.push_back(path);

        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1])continue;
            path.push_back(nums[i]);
            dfs(i+1,nums);
            path.pop_back();
        }
    }
};

//IIterative Approach — Expand Subsets and Track Last Size
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int startIdx = 0, endIdx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            startIdx = 0;

            if (i > 0 && nums[i] == nums[i - 1]) {
                // Only add to subsets generated in the previous step
                startIdx = endIdx + 1;
            }

            endIdx = res.size() - 1;
            int sz = res.size();

            for (int j = startIdx; j < sz; ++j) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};


//Bitmasking (Iterative) - Optimal Approach
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int total = 1 << n;
    vector<vector<int>> res;
    set<vector<int>> unique;

    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        unique.insert(subset);
    }

    return vector<vector<int>>(unique.begin(), unique.end());
}