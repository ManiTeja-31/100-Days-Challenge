//Naive (Flatten and Sort)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};

//Max-Heap Approach
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxheap;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxheap.push(matrix[i][j]);
                if(maxheap.size()>k)
                {
                    maxheap.pop();
                }
            }
        }
        return maxheap.top();
    }
};

//min-Heap Approach
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            minHeap.push({matrix[i][0],i,0});
        }
        int ans=0;
        while(k--){
            auto curr = minHeap.top();
            int val=curr[0],row=curr[1],col=curr[2];
            minHeap.pop();
            ans=val;
            if(col+1<n){
                minHeap.push({matrix[row][col+1],row,col+1});
            }
        }
        return ans;
    }
};

//Binary Search Approach
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int count = countVal(mid,matrix);
            if(count<k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
    int countVal(int mid,vector<vector<int>> &matrix){
        int count=0,n=matrix.size();
        int row=n-1,col=0;
        while(row>=0 && col<n){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col++;
            }else{
                row--;
            }
        }
        return count;
    }
};