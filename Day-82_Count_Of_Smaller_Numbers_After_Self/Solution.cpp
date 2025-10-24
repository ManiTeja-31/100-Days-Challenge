//Brute Force Approach
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int count=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]<curr){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

//Merge Sort Approach
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int> count(n,0);
        mergeSort(0,n-1,arr,count);
        return count;
    }
    void mergeSort(int left,int right,vector<pair<int,int>> &arr,vector<int> &count){
        if(left>=right){
            return;
        }
        int mid = left+(right-left)/2;
        mergeSort(left,mid,arr,count);
        mergeSort(mid+1,right,arr,count);
        merge(left,right,arr,count);
    }
    void merge(int left,int right,vector<pair<int,int>> &arr,vector<int> &count){
        int mid=left+(right-left)/2;
        int rightCount=0;
        int i=left,j=mid+1;
        vector<pair<int,int>> temp;
        while(i<=mid && j<=right){
            if(arr[i].first <= arr[j].first){
                count[arr[i].second]+=rightCount;
                temp.push_back(arr[i]);
                i++;
            }else{
                rightCount++;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            count[arr[i].second]+=rightCount;
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=right){
            temp.push_back(arr[j]);
            j++;
        }

        for(int k=left;k<=right;k++){
            arr[k] = temp[k-left];
        }
    }
};

//Binary Indexed Tree (Fenwick Tree) Approach
class BIT {
public:
    vector<int> bit;
    int n;
    BIT(int size) : n(size) {
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        BIT tree(sorted.size());
        vector<int> result(n);

        // process from right to left
        for (int i = n - 1; i >= 0; --i) {
            int rank = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            result[i] = tree.query(rank - 1); // count of smaller elements
            tree.update(rank, 1);
        }
        return result;
    }
};
