//Brute Force Approach
int longestConsecutive(vector<int>& nums) {
    int longest = 0;
    for (int num : nums) {
        int current = num;
        int count = 1;
        while (find(nums.begin(), nums.end(), current + 1) != nums.end()) {
            current++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}


//Sorting Approach
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int longest = 1, currentStreak = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) { // Skip duplicates
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            } else {
                longest = max(longest, currentStreak);
                currentStreak = 1;
            }
        }
    }
    return max(longest, currentStreak);
}

//Optimal Approach using HashSet
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) { // Iterate through unique elements not nums because of duplicates and to optimize
        if (numSet.find(num - 1) == numSet.end()) { // Start of a sequence
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }
            longest = max(longest, currentStreak);
        }
    }
    return longest;
}

//Optimal Approach using Union-Find
class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
};

int longestConsecutive(vector<int>& nums) {
    UnionFind uf;
    for (int num : nums) {
        if (uf.parent.count(num)) continue;
        uf.parent[num] = num;
        uf.size[num] = 1;
        if (uf.parent.count(num - 1)) uf.unite(num, num - 1);
        if (uf.parent.count(num + 1)) uf.unite(num, num + 1);
    }
    int longest = 0;
    for (auto& [num, sz] : uf.size) {
        if (uf.find(num) == num)
            longest = max(longest, sz);
    }
    return longest;
}

// Another Optimal Approach using HashMap
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> numMap;
    int longest = 0;

    for (int num : nums) {
        if (numMap.count(num)) continue; // Skip duplicates
        int left = numMap.count(num - 1) ? numMap[num - 1] : 0;
        int right = numMap.count(num + 1) ? numMap[num + 1] : 0;
        int currentStreak = left + right + 1;

        numMap[num] = currentStreak;
        longest = max(longest, currentStreak);

        // Update the boundaries of the streak
        if (left > 0) numMap[num - left] = currentStreak;
        if (right > 0) numMap[num + right] = currentStreak;
    }
    return longest;
}

// Another Optimal Approach using HashSet
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : nums) {
        if (numSet.erase(num)) { // Only process if num is still in the set
            int currentStreak = 1;
            int lower = num - 1, upper = num + 1;

            while (numSet.erase(lower)) {
                currentStreak++;
                lower--;
            }
            while (numSet.erase(upper)) {
                currentStreak++;
                upper++;
            }
            longest = max(longest, currentStreak);
        }
    }
    return longest;
}
