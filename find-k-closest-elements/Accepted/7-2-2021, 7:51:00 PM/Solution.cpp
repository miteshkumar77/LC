// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        ans.reserve(k);
        int l = 0;
        int r = (int)arr.size() - 1;
        int next;
        int al, ar;
        while(l <= r) {
            al = abs(arr[l] - x);
            ar = abs(arr[r] - x);
            if (r - l + 1 == k) break;
            if (al > ar || (al == ar && arr[l] > arr[r])) {
                next = arr[l++];   
            } else {
                next = arr[r--];
            }
        }    
        
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};