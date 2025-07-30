//Insertion Sort Approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int key = nums[i];
            int j=i-1;
            while(j>=0 && nums[j]>key){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
    }
};

//Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low++],nums[mid++]);
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high--]);
            }
        }
    }
};