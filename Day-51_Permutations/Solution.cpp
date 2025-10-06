//BackTracking with visited array (or) DFS
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        backTrack(visited,nums);
        return res;
    }
    void backTrack(vector<int> &visited,vector<int> &nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]){
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            backTrack(visited,nums);
            path.pop_back();
            visited[i]=false;
        }
    }
};

//BackTracking with In-place Swapping - Optimal
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(0,nums);
        return res;
    }
    void backTrack(int ind,vector<int> &nums){
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            backTrack(ind+1,nums);
            swap(nums[ind],nums[i]);
        }
    }
};

//using STL next_permutation function
vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    do {
        res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return res;
}
