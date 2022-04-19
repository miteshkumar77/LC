// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0); 
        
        for (int i = 1, j = 0; candies > 0; ++j,candies -= i, ++i) {
            j = j % num_people; 
            cout << j << endl; 
            ans[j] += min(candies, i); 
        }
        return ans; 
        
        
    }
};