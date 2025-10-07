// Bactracking Approach
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack(0,0,candidates,target);
        return res;
    }
    void backTrack(int ind,int sum,vector<int> &candidates,int target){
        if(sum==target){
            res.push_back(combination);
            return;
        }
        if(sum>target || ind>=candidates.size()){
            return;
        }
        
        backTrack(ind+1,sum,candidates,target);
        combination.push_back(candidates[ind]);
        backTrack(ind,sum+candidates[ind],candidates,target);
        combination.pop_back();
    }
};

//Bactracking Approach - Alternative
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack(0,candidates,target);
        return res;
    }
    void backTrack(int ind,vector<int> &candidates,int target){
        if(target==0){
            res.push_back(combination);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            combination.push_back(candidates[i]);
            backTrack(i,candidates,target-candidates[i]);
            combination.pop_back();
        }
    }
};
