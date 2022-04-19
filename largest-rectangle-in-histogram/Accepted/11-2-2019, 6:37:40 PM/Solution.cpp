// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int max_area = 0;
    int curr_area = 0;
    int largestRectangleArea(vector<int>& heights) {
        bool flag = false;
        for (int k = 0; k < heights.size(); k++) {
            if (heights[k] != heights[0]) {
                flag = true;
                break;
            }
        }
        
        if (!flag && heights.size() > 0) {
            return heights[0] * heights.size(); 
        }
        for (int i = 0; i < heights.size(); i++) {
            int j = i; 
            while (j < heights.size() && heights[j] >= heights[i]) {
                curr_area+= heights[i];
                j++;
            }
            j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                curr_area+= heights[i];
                j--;
            }
            
            if (curr_area > max_area) {
                max_area = curr_area;
            }
            
            curr_area = 0;
        }
        
        return max_area;
    }
};