//Brute Force Approach
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};
//Optimized Approach
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> St;
        for(int i=n-1;i>=0;i--){
            while(!St.empty() && St.top().first <= temperatures[i]){
                St.pop();
            }
            res[i] = St.size()>0?St.top().second-i:0;
            St.push({temperatures[i],i});
        }
        return res;
    }
};