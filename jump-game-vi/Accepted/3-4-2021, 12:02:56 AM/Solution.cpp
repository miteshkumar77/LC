// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int num_elements = 1;
        deque<pair<int,int>> q;
        int gans = nums[0];
        q.push_back({nums[0], 1});
        
        for (int i = 1; i < n; ++i) {
            if(num_elements > k) {
                --num_elements;
                --q.back().second;
                if (q.back().second == 0) {
                    q.pop_back(); 
                }
            }
            
            
            gans = q.back().first + nums[i];
            pair<int,int> t = {gans, 1};
            ++num_elements;
            while(!q.empty() && q.front().first <= gans) {
                t.second += q.front().second;
                q.pop_front();
            }
            q.push_front(t);
        }
        
        return gans;
    }
};


/**

    [1, -1, -2, 4, -7, 3]
              
    0    1   
    1    1

*/