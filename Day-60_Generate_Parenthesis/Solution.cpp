class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backTrack("",0,0,n);
        return res;
    }
    void backTrack(string curr,int open,int close,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            backTrack(curr+"(",open+1,close,n);
        }
        if(close<open){
            backTrack(curr+")",open,close+1,n);
        }
    }
};