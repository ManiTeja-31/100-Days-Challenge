//Naive Approach (Merge and Find Median)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int m=nums1.size(),n=nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i++]);
            }else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i<m){
            merged.push_back(nums1[i++]);
        }
        while(j<n){
            merged.push_back(nums2[j++]);
        }
        int k=m+n;
        if(k % 2 == 1){
            return (double)merged[k/2];
        }
        return double(merged[k/2]+merged[k/2-1])/2;
    }
};

//Merge until median found
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int total = m+n;
        int mid1=total/2-1,mid2=total/2;
        int a=-1,b=-1;
        int count=0;
        int i=0,j=0;
        while(count<=mid2){
            int val=0;
            if(i<m && (j>=n || nums1[i]<nums2[j])){
                val=nums1[i++];
            }else{
                val=nums2[j++];
            }
            if(count==mid1){
                a=val;
            }
            if(count==mid2){
                b=val;
            }
            count++;
        }
        if(total%2!=0){
            return (double)b;
        }
        return (double)(a+b)/2;
    }
};

//Optimal Approach (Binary Search)
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    int m = nums1.size(), n = nums2.size();
    
    int low = 0, high = m;
    while (low <= high) {
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;
        
        int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRightA = (i == m) ? INT_MAX : nums1[i];
        int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRightB = (j == n) ? INT_MAX : nums2[j];
        
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 == 0)
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            else
                return max(maxLeftA, maxLeftB);
        } 
        else if (maxLeftA > minRightB)
            high = i - 1;
        else
            low = i + 1;
    }
    return 0.0; // should never reach here
}
