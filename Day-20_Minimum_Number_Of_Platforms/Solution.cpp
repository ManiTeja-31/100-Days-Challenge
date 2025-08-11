// Brute force Approach
class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int count=1;
                for(int j=0;j<n;j++){
                    if( i!=j && (arr[i] >= arr[j] && arr[i] <=dep[j])){
                        count++;
                    }
                }
            ans=max(ans,count);
        }
        return ans;
    }
};


//Optimized Approach
class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int ans=1,count=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }else{
                j++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
