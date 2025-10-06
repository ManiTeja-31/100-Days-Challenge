//Naive: Generate All Permutations + Use Set
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> unique;
        vector<int> visited(nums.size(),0);
        backTrack(visited,nums,unique);
        return res;

    }
    void backTrack(vector<int> &visited, vector<int> &nums, set<vector<int>> &unique){
        if(path.size()==nums.size() && unique.find(path)==unique.end()){
            res.push_back(path);
            unique.insert(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i])continue;
            visited[i] = true;
            path.push_back(nums[i]);
            backTrack(visited,nums,unique);
            path.pop_back();
            visited[i] = false;
        }
    }
};

//Optimal Backtracking with Duplicate Skipping
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // Skip duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, used);

            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};

//In-place Swapping with HashSet to Avoid Repeats Per Level
class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int start, vector<int>& nums) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for (int i = start; i < nums.size(); ++i) {
            if (seen.count(nums[i])) continue;

            seen.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums);
            swap(nums[start], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};

//Using STL next_permutation function
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    do {
        res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return res;
}