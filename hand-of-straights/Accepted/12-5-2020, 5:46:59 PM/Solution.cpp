// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        
        if (hand.size() % W != 0) return false;

        map<int,int> ct;
        for (int i : hand) {
            ++ct[i];
        }
        
        function<void(int)> dec = [&](int val) -> void {
            --ct[val];
            if (ct[val] == 0) {
                ct.erase(val);
            }
        };
        while(ct.size() != 0) {
            int val = ct.begin() -> first;
            for (int i = 0; i < W; ++i) {
                if (ct.find(val) == ct.end()) {
                    return false;
                }
                dec(val++);
            }
        }
        return true;
//         if (hand.size() % W != 0) return false;
        
//         unordered_map<int,int> ct;
        
//         for (int i : hand) {
//             ++ct[i];
//         }
        

        
//         while(ct.size() != 0) {
//             int center = ct.begin() -> first;
//             dec(center);
//             int len = 1;
//             int left = center - 1;
//             int right = center + 1;
//             cout << center << endl;
//             cout << "Left: ";
//             while(ct.find(left) != ct.end()) {
//                 cout << left << ' ';
//                 dec(left--);
//                 ++len;
//             }
//             cout << endl << "Right: ";
//             while(ct.find(right) != ct.end()) {
//                 cout << right << ' ';
//                 dec(right++);
//                 ++len;
//             }
            
//             cout << endl;
//             if (len % W != 0) {
//                 return false;
//             }
//         }
        
//         return true;
        
        
        
    }
};