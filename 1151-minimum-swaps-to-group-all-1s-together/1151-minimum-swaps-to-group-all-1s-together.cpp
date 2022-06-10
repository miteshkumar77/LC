class Solution {
public:
    int minSwaps(vector<int>& data) {
        int no = accumulate(data.begin(), data.end(), 0);
        
        int nz = no - accumulate(data.begin(), data.begin() + no, 0);
        int ans = nz;
        for (int i = no; i < data.size(); ++i) {
            nz -= (data[i-no] == 0);
            nz += (data[i] == 0);
            ans = min(ans, nz);
        }
        return ans;
    }
};