// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        
        unordered_set<int> visited;
        queue<int> bfsq;
        bfsq.push(start);
        while(!bfsq.empty()) {
            int curIdx = bfsq.front();
            bfsq.pop();
            
            if (curIdx >= arr.size() || curIdx < 0 || visited.find(curIdx) != visited.end()) {
                continue;
            }
            
            if (arr[curIdx] == 0) {
                return true;
            }
            visited.insert(curIdx);
            
            bfsq.push(curIdx - arr[curIdx]);
            bfsq.push(curIdx + arr[curIdx]);
        }
        return false;
    }
};