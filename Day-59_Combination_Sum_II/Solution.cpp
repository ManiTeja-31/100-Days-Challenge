//Backtracking + Sorting + Duplicate Skipping
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backTrack(0,candidates,target);
        return res;
    }
    void backTrack(int start,vector<int> &candidates,int target){
        if(target==0){
            res.push_back(combination);
            return;
        }
        if(target<0 || start >= candidates.size()){
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            combination.push_back(candidates[i]);
            backTrack(i+1,candidates,target-candidates[i]);
            combination.pop_back();
        }
    }
};