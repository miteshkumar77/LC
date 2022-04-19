// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // [4,2,7,6,9,14,12] bricks = 5, ladders = 1
        //    j b j l 
        //      5
        
        int n = heights.size();
        if (bricks == 0 && ladders == 0) {
            return 0;
        }
        if (n == 0) {
            return 0;
        }
        deque<pair<int,int>> minq;
        for (int i = 0; i + 1 < n; ++i) {
            if (heights[i] < heights[i + 1]) {
                pair<int,int> ins = {heights[i + 1] - heights[i], 1};
                while(!minq.empty() && ins.first <= minq.back().first) {
                    ins.second += minq.back().second;
                    minq.pop_back();
                }
                
                minq.push_back(ins);
                if (ladders) {
                    --ladders;
                } else {
              
                    bricks -= minq.front().first;
                    if (bricks < 0) {
                        return i;
                    }
                    if (ins.first != minq.front().first) {
                        ++ladders;
                    }
                    --minq.front().second;
                    if (minq.front().second == 0) {
                        minq.pop_front();
                    }
                }
            }
        }
        return n - 1;
    }
};