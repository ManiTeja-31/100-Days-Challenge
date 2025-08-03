//Brute Force Approach
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            int tank=0;
            for(int j=i;j<n;j++){
                tank += gas[j] - cost[j];
                if(tank<0){
                    break;
                }
            }
            if(tank>=0){
                return i;
            }
        }
        return -1;
    }
};

//OR

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int start = 0; start < n; ++start) {
            int tank = 0;
            int i = 0;
            for (; i < n; ++i) {
                int idx = (start + i) % n;
                tank += gas[idx] - cost[idx];
                if (tank < 0) break;
            }
            if (i == n) return start;
        }
        return -1;
    }
};

//Optimized Approach
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0,totalCost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost > totalGas){
            return -1;
        }
        int start=0,tank=0;
        for(int i=0;i<n;i++){
            tank += (gas[i] - cost[i]);
            if(tank<0){
                tank=0;
                start = i+1;
            }
        }
        return start;
    }
};