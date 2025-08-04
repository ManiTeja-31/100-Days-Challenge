//Brute-Force Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(profit < prices[j]-prices[i]){
                    profit = prices[j]-prices[i];
                }
            }
        }
        return profit;
    }
};

//Optimized Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minPrice=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            minPrice = min(minPrice,prices[i]);
            profit = max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};