// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> m;
        int sum = 0;
        for (int i = 0; i < pieces.size(); ++i) {
            m[pieces[i][0]] = i;
            sum += pieces[i].size();
        }
        
        if (sum != arr.size()) {
            return false;
        }
        
        int i = 0;
        while(i < arr.size()) {
            if (m.find(arr[i]) == m.end()) {
                return false;
            }
            for (int j : pieces[m[arr[i]]]) {
                if (j == arr[i]) {
                    ++i;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};