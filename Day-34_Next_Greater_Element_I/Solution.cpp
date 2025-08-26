//Brute Force Approach
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int m=nums1.size(), n=nums2.size();
    for(int i=0;i<m;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(nums1[i]==nums2[j]){
                flag=1;
                for(int k=j+1;k<n;k++){
                    if(nums2[k]>nums2[j]){
                        res.push_back(nums2[k]);
                        break;
                    }
                }
                if(flag==0)
                    res.push_back(-1);
            }
        }
    }
    return res;
}

//Optimized Approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> Hash;
        stack<int> St;
        int m=nums1.size(), n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!St.empty() && St.top()<=nums2[i]){
                St.pop();
            }
            if(St.empty()){
                Hash[nums2[i]]=-1;
            }else{
                Hash[nums2[i]]=St.top();
            }
            St.push(nums2[i]);
        }
        for(int j=0;j<m;j++){
            res.push_back(Hash[nums1[j]]);
        }
        return res;
    }
};