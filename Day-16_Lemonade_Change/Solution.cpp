//Brute Force
class Solution {
public:
    bool dfs(vector<int>& bills, int idx, int five, int ten) {
        if (idx == bills.size()) return true;
        if (bills[idx] == 5) return dfs(bills, idx+1, five+1, ten);
        if (bills[idx] == 10) {
            if (five == 0) return false;
            return dfs(bills, idx+1, five-1, ten+1);
        }
        // bills[idx] == 20
        bool way1 = (five >= 1 && ten >= 1) && dfs(bills, idx+1, five-1, ten-1);
        bool way2 = (five >= 3) && dfs(bills, idx+1, five-3, ten);
        return way1 || way2;
    }
    bool lemonadeChange(vector<int>& bills) {
        return dfs(bills, 0, 0, 0);
    }
};

//Optimized Approach
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        map<int,int> change;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                change[5]++;
            }else if(bills[i]==10){
                if(change[5]>0){
                    change[5]--;
                    change[10]++;
                }else{
                    return false;
                }
            }else{
                if(change[10]>0 && change[5]>0){
                    change[10]--;
                    change[5]--;
                    change[20]++;
                }else if(change[5]>=3){
                    change[5]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

//Optimized Approach - using two Variables
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            else if (bill == 10) {
                if (five == 0) return false;
                five--; ten++;
            } else {
                if (ten > 0 && five > 0) { ten--; five--; }
                else if (five >= 3) { five -= 3; }
                else return false;
            }
        }
        return true;
    }
};