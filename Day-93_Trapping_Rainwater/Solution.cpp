//Brute-Force Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            int left = leftHeight(i-1,height);
            int right = rightHeight(i+1,height);
            int water = min(left,right) - height[i];
            if(water>0){
                ans+=water;
            }
        }
        return ans;
        
    }
    int leftHeight(int i, vector<int> &height){
        int maxHeight=0;
        while(i>=0){
            maxHeight = max(maxHeight, height[i]);
            i--;
        }
        return maxHeight;
    }
    int rightHeight(int i, vector<int> &height){
        int maxHeight=0;
        while(i<height.size()){
            maxHeight=max(maxHeight,height[i]);
            i++;
        }
        return maxHeight;
    }
};

//Optimal Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        vector<int> maxLeft(n,0), maxRight(n,0);
        int currLeftMax=0, currRightMax=0;
        for(int i=0;i<n;i++){
            maxLeft[i]=currLeftMax;
            currLeftMax=max(currLeftMax,height[i]);
        }
        for(int i=n-1;i>=0;i--){
            maxRight[i]=currRightMax;
            currRightMax=max(currRightMax,height[i]);
        }
        for(int i=0;i<n;i++){
            int water = min(maxLeft[i],maxRight[i]) - height[i];
            if(water>0){
                ans+=water;
            }
        }
        return ans;
        
    }
    
};

//Optimal Approach (Space Optimized)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int left=0,right=n-1;
        int maxLeft=0,maxRight=0;
        while(left < right){
            if(height[left] < height[right]){
                if(maxLeft > height[left]){
                    ans+=maxLeft-height[left];
                }else{
                    maxLeft=height[left];
                }
                left++;
            }else{
                if(maxRight > height[right]){
                    ans+=maxRight-height[right];
                }else{
                    maxRight=height[right];
                }
                right--;
            }
        }
        return ans;
        
    }
    
};

//Using Stack
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(i);
        }
        return ans;
    }
};

