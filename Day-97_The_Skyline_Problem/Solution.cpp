//Brute Force Approach
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int maxX = 0;
        for (auto& b : buildings)
            maxX = max(maxX, b[1]);
        vector<int> height(maxX + 1, 0);

        // fill height map
        for (auto& b : buildings) {
            for (int x = b[0]; x < b[1]; x++) {
                height[x] = max(height[x], b[2]);
            }
        }

        // find skyline key points
        vector<vector<int>> res;
        int prev = 0;
        for (int x = 0; x <= maxX; x++) {
            if (height[x] != prev) {
                res.push_back({x, height[x]});
                prev = height[x];
            }
        }

        return res;
    }
};

//Divide and Conquer Approach(Similar to Merge Sort)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return divide(buildings, 0, buildings.size() - 1);
    }

    vector<vector<int>> divide(vector<vector<int>>& b, int l, int r) {
        if (l > r) return {};
        if (l == r) return {{b[l][0], b[l][2]}, {b[l][1], 0}};
        int mid = (l + r) / 2;
        auto left  = divide(b, l, mid);
        auto right = divide(b, mid + 1, r);
        return merge(left, right);
    }

    vector<vector<int>> merge(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int h1 = 0, h2 = 0, i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int x;
            if (A[i][0] < B[j][0]) {
                x = A[i][0];
                h1 = A[i][1];
                i++;
            } else if (B[j][0] < A[i][0]) {
                x = B[j][0];
                h2 = B[j][1];
                j++;
            } else {
                x = A[i][0];
                h1 = A[i][1];
                h2 = B[j][1];
                i++; j++;
            }
            int maxH = max(h1, h2);
            if (res.empty() || res.back()[1] != maxH)
                res.push_back({x, maxH});
        }
        // Append leftovers
        while (i < A.size()) res.push_back(A[i++]);
        while (j < B.size()) res.push_back(B[j++]);
        return res;
    }
};


//Sweep Line with Multiset
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int,int>> events;
        for(auto b:buildings){
            int x=b[0],y=b[1],h=b[2];
            events.push_back({x,h});
            events.push_back({y,-h});
        }
        sort(events.begin(),events.end(),
        [](const pair<int,int> &a,const pair<int,int> &b){
            if(a.first!=b.first){
                return a.first<b.first;
            }else{
                return a.second>b.second;
            }
        });
        multiset<int> heights;
        heights.insert(0);
        int prevMax=0;
        for(auto e:events){
            int x=e.first;
            int h=e.second;
            if(h>0){
                heights.insert(h);
            }else{
                heights.erase(heights.find(-h));
            }
            int currMax = *heights.rbegin();
            if(currMax!=prevMax){
                res.push_back({x,currMax});
                prevMax=currMax;
            }
        }
        return res;
    }
};

//Sweep Line with Priority Queue
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;
        for (auto &b : buildings) {
            events.push_back({b[0],  b[2]});
            events.push_back({b[1], -b[2]});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        priority_queue<int> pq;
        pq.push(0);
        unordered_map<int,int> toRemove;
        int prevMax = 0;
        vector<vector<int>> res;

        for (auto &[x, h] : events) {
            if (h > 0) pq.push(h);
            else toRemove[-h]++;  // mark for lazy removal

            while (!pq.empty() && toRemove[pq.top()]) {
                toRemove[pq.top()]--;
                pq.pop();
            }

            int curMax = pq.top();
            if (curMax != prevMax) {
                res.push_back({x, curMax});
                prevMax = curMax;
            }
        }
        return res;
    }
};
