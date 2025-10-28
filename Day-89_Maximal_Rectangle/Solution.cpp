//Brute Force Approach (Check every possible rectangle)
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;

    for (int r1 = 0; r1 < m; r1++) {
        for (int c1 = 0; c1 < n; c1++) {
            if (matrix[r1][c1] == '0') continue;
            for (int r2 = r1; r2 < m; r2++) {
                for (int c2 = c1; c2 < n; c2++) {
                    bool allOnes = true;
                    for (int i = r1; i <= r2; i++) {
                        for (int j = c1; j <= c2; j++) {
                            if (matrix[i][j] == '0') {
                                allOnes = false;
                                break;
                            }
                        }
                        if (!allOnes) break;
                    }
                    if (allOnes)
                        maxArea = max(maxArea, (r2 - r1 + 1) * (c2 - c1 + 1));
                }
            }
        }
    }
    return maxArea;
}
//Brute Force Approach - Optimized (Using heights)
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
    vector<int> height(n, 0);

    for (int top = 0; top < m; top++) {
        fill(height.begin(), height.end(), 0);
        for (int bottom = top; bottom < m; bottom++) {
            for (int j = 0; j < n; j++)
                if (matrix[bottom][j] == '1') height[j]++;
                else height[j] = 0;

            // find max rectangle of 1s (width × height)
            int width = 0;
            for (int j = 0; j < n; j++) {
                if (height[j] == (bottom - top + 1)) width++;
                else width = 0;
                maxArea = max(maxArea, width * (bottom - top + 1));
            }
        }
    }
    return maxArea;
}


//Dp with Left, Right, Height arrays
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size();
        vector<int> right(n,n),left(n,0),height(n,0);
        int res=0;
        for(int i=0;i<m;i++){
            int currLeft=0,currRight=n;
            for(int j=0;j<n;j++){
                height[j]=matrix[i][j]=='1'?height[j]+1:0;
            }
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    left[j]=max(left[j],currLeft);
                }else{
                    left[j]=0;
                    currLeft=j+1;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    right[j]=min(right[j],currRight);
                }else{
                    right[j]=n;
                    currRight=j;
                }
            }
            for(int j=0;j<n;j++){
                res=max(res,height[j]*(right[j]-left[j]));
            }
        }
        return res;
    }
};

//Using Largest Rectangle in Histogram as a subroutine
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size(),res=0;
        vector<int> heights(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                heights[j]=matrix[i][j]=='1'?heights[j]+1:0;
            }
            res=max(res,helper(heights));
        }
        return res;
    }
    int helper(vector<int> &heights){
        stack<int> St;
        int n=heights.size(),largest=0;
        for(int i=0;i<n;i++){
            while(!St.empty() && heights[St.top()] > heights[i]){
                int h=heights[St.top()];
                St.pop();
                int w=St.empty()?i:i-St.top()-1;
                largest = max(largest,h*w);
            }
            St.push(i);
        }
        return largest;
    }
};
