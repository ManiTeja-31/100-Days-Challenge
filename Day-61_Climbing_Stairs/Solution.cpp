//Naive Recursion (Brute Force)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

//Recursion with Memoization (Top-Down DP)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(1,n,dp) + helper(2,n,dp);
    }
    int helper(int ind,int n,vector<int> &dp){
        if(ind==n){
            return 1;
        }
        else if(ind>n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        return dp[ind] = helper(ind+1,n,dp) + helper(ind+2,n,dp);
    }
};

//Recursion with Memoization (Top-Down DP) - Alternative
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return climb(n,memo);
    }
    int climb(int ind,vector<int> &memo){
        if(ind<=1){
            return 1;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        return memo[ind] = climb(ind-1,memo) + climb(ind-2,memo);
    }
};

//Bottom-Up DP (Tabulation)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

//Optimized DP (Constant Space)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        int a=1,b=1;
        for(int i=2;i<=n;i++){
            int temp=a+b;
            a=b;
            b=temp;
        }
        return b;
    }
};

//Matrix Exponentiation (Logarithmic Time)
typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix& a, const Matrix& b) {
    Matrix result(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}

Matrix matrixPower(Matrix base, int n) {
    Matrix result = {{1, 0}, {0, 1}}; // Identity matrix
    while (n > 0) {
        if (n % 2 == 1)
            result = multiply(result, base);
        base = multiply(base, base);
        n /= 2;
    }
    return result;
}

int climbStairs(int n) {
    if (n <= 1) return 1;
    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = matrixPower(base, n);
    return result[0][0];
}

//Binet’s Formula (Closed-form Fibonacci)
#include <cmath>

int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    return round(pow(phi, n + 1) / sqrt5);
}

