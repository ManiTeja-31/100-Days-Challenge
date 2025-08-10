//Brute Force Approach
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> burst(n, false);
        int arrows = 0;
        for (int i = 0; i < n; ++i) {
            if (burst[i]) { // If already burst, 
                continue;
            }
            arrows++;
            // Shoot an arrow at every possible x in the current balloon
            int x = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (!burst[j] && points[j][0] <= x && x <= points[j][1]) {
                    burst[j] = true; // Mark as burst if arrow hits
                }
            }
        }
        return arrows;
    }
};

//Optimized Approach - With Explanation

// Custom comparator to sort balloons by their end point
bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        // Sort balloons by their end coordinate
        sort(points.begin(), points.end(), cmp);

        int arrow = 1; // At least one arrow needed
        int end = points[0][1]; // Track where the last arrow was shot

        for (int i = 1; i < n; i++) {
            // If current balloon starts after the last arrow's end, it can't be burst
            if (points[i][0] > end) {
                arrow++; // Need a new arrow
                end = points[i][1]; // Move arrow position to the end of the current balloon
            }
            // If current balloon starts before or at 'end', it overlaps and is burst by the same arrow
            // No action needed in this case
        }
        return arrow;
    }
};

/*
Why compare start and end?

If a balloon's start is after our last arrow’s end, it means the previous arrow can’t burst this balloon.
So, we need a new arrow and update end to this balloon’s end point.
*/