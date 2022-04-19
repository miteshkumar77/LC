// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {        
        stack<int> nge;
        unordered_map<int,int> mp;
        
        for (int i = 0; i < nums2.size(); ++i) {
            while(!nge.empty() && nums2[nge.top()] < nums2[i]) {
                mp[nums2[nge.top()]] = nums2[i];
                nge.pop();
            }
            nge.push(i);
        }
        
        for (int& i : nums1) {
            if (mp.find(i) == mp.end()) {
                i = -1;
            } else {
                i = mp[i];
            }
        }
        return nums1;
    }
};