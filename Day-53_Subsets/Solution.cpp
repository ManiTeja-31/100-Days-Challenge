//Backtracking (DFS) — Standard Approach
class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        backTrack(0,nums);
        return res;
    }
    void backTrack(int ind,vector<int> &nums){
        if(ind==nums.size()){
            res.push_back(subset);
            return;
        }
        backTrack(ind+1,nums);
        subset.push_back(nums[ind]);
        backTrack(ind+1,nums);
        subset.pop_back();
    }
};

//Backtracking (DFS) — Standard Approach Alternative
class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
    void dfs(int ind,vector<int> &nums){
        res.push_back(subset);

        for(int i=ind;i<nums.size();i++){
            subset.push_back(nums[i]);
            dfs(i+1,nums);
            subset.pop_back();
        }
    }
};

//Bitmasking (Iterative) - Optimal Approach
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n;
    vector<vector<int>> res;

    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        res.push_back(subset);
    }

    return res;
}

//Iterative Expansion
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res = {{}};

    for (int num : nums) {
        int size = res.size();
        for (int i = 0; i < size; ++i) {
            vector<int> subset = res[i];
            subset.push_back(num);
            res.push_back(subset);
        }
    }

    return res;
}
