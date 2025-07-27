// Brute Force Approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                int len = j-i;
                int bre = min(height[i],height[j]);
                area = max(area,len*bre);
            }
        }
        return area;
    }
};

// Optimized Solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int area = INT_MIN;
        while(l<r)
        {
            int len = r-l;
            int bre = min(height[l],height[r]);
            area = max(area,len*bre);
            if(height[l]==height[r]){
                l++;
                r--;
            }
            else if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        return area;
        
    }
};