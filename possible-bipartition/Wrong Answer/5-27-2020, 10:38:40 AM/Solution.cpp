// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<bool> left_part (N + 1, false); 
        vector<bool> right_part (N + 1, false); 
        for (vector<int> rel : dislikes) {
            if (left_part[rel[0]] && left_part[rel[1]] || right_part[rel[0]] && right_part[rel[1]]) {
                return false; 
            }
            
            if (left_part[rel[0]]) {
                right_part[rel[1]] = true; 
            } else if (left_part[rel[1]]) {
                right_part[rel[0]] = true; 
            } else if (right_part[rel[0]]) {
                left_part[rel[1]] = true; 
            } else if (right_part[rel[1]]) {
                left_part[rel[0]] = true; 
            } else {
                left_part[rel[0]] = true; 
                right_part[rel[1]] = true; 
            }
        }
        
        return true; 
    }
};