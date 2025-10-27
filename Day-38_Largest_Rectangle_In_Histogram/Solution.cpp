//Brute Force Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int minHeight = heights[i];
            for(int j=i;j<n;j++){
                minHeight = min(minHeight,heights[j]);
                area = max(area, (j-i+1)*minHeight);
            }
        }
        return area;
    }
};

//Optimized Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> rightindex,leftindex;
        stack<int> St;
        for(int i=0;i<n;i++)
        {
            while(!St.empty() and heights[i]<=heights[St.top()])
            {
                St.pop();
            }
            if(St.empty())
            {
                leftindex.push_back(-1);
            }
            else
            {
                leftindex.push_back(St.top());
            }
            St.push(i);
        }
        while(!St.empty())
            St.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!St.empty() and heights[i]<=heights[St.top()])
            {
                St.pop();
            }
            if(St.empty())
            {
                rightindex.push_back(n);
            }
            else
            {
                rightindex.push_back(St.top());
            }
            St.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            int w=rightindex[n-i-1]-leftindex[i]-1;
            maxi=max(maxi,l*w);
        }
        return maxi;
    }
};

//Optimized Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int maxArea=0;
        stack<int> St;
        for(int i=0;i<heights.size();i++){
            while(!St.empty() && heights[i] < heights[St.top()]){
                int h = heights[St.top()];
                St.pop();
                int w = St.empty() ? i : i-St.top()-1;
                maxArea = max(maxArea, h*w);
            }
            St.push(i);
        }
        return maxArea;
    }
};
