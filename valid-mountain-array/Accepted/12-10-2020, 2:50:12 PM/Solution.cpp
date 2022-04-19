// https://leetcode.com/problems/valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool increased = false;
        bool decreased = false;
        
        int prev = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > prev && !decreased) {
                increased = true;
            } else if (arr[i] < prev && increased) {
                decreased = true;
            } else {
                return false;
            }
            prev = arr[i];
        }
        return increased && decreased;
    }
};