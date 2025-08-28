//Brute Force Approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;
        for(int i = 0; i < n; ++i) {
            unordered_set<int> basket;
            int count = 0;
            for(int j = i; j < n; ++j) {
                basket.insert(fruits[j]);
                if(basket.size() > 2) break;
                count++;
            }
            maxFruits = max(maxFruits, count);
        }
        return maxFruits;
    }
};
//Optimized approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0,right=0, maxFruits = 0, currFruits = 0;
        unordered_map<int,int> bucket;
        while(right < n){
            if(bucket.size()==2 && bucket.find(fruits[right])==bucket.end()){
                int smallest_index=INT_MAX;
                int fruit_to_remove;
                for(auto fruitType:bucket){
                    if(fruitType.second < smallest_index){
                        smallest_index = fruitType.second;
                        fruit_to_remove = fruitType.first;
                    }
                }
                
                bucket.erase(fruit_to_remove);
                left = smallest_index + 1;
            }
             bucket[fruits[right]] = right;
             maxFruits = max(maxFruits, right-left+1);
            right++;
        }
        return maxFruits;
    }
};

//Further Optimized
int totalFruit(vector<int>& fruits) {
    int left = 0, right = 0, maxFruits = 0;
    pair<int, int> basket1 = {-1, 0}; // {fruitType, count}
    pair<int, int> basket2 = {-1, 0}; // {fruitType, count}

    while (right < fruits.size()) {
        int fruit = fruits[right];

        if (basket1.first == fruit || basket1.first == -1) {
            basket1 = {fruit, basket1.second + 1};
        } else if (basket2.first == fruit || basket2.first == -1) {
            basket2 = {fruit, basket2.second + 1};
        } else {
            // When a third type is encountered, reset one basket
            if (basket1.second < basket2.second) {
                left += basket1.second;
                basket1 = {fruit, 1};
            } else {
                left += basket2.second;
                basket2 = {fruit, 1};
            }
        }

        maxFruits = max(maxFruits, right - left + 1);
        right++;
    }

    return maxFruits;
}