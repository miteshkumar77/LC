// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        array<int, 10> ct; fill(ct.begin(), ct.end(), 0); 
//         for (int i = 1; i <= 7; ++i) {
//             for (int j = 1; j <= 7; ++j) {
//                 ++ct[(i + j - 1) % 10];
//             }
//         }
//         int xi = -1; 
//         int xj = -1; 
//         for (int i = 7; i >= 1; --i) {
//             for (int j = 7; j >= 1; --j) {
//                 // bool valid = true; 
//                 if (i == 6 && j == 5) {
//                     for (int i : ct) cout << i << ' '; 
//                     return 0; 
//                 }
// //                 for (int x = 0; x < 10; ++x) {
// //                     if (ct[x] != ct[0]) {
// //                         valid = false; 
// //                         break; 
// //                     }
// //                 }
                
// //                 if (valid) {
// //                     xi = i; 
// //                     xj = j; 
// //                     cout << xi << ' ' << xj << endl; 
// //                     break; 
// //                 }
//                 --ct[(i + j - 1) % 10]; 
                
//             }
//         }
        
        int i = 7; 
        int j = 7; 
        
        while((i - 1) * 7 + j >= 36) {
            i = rand7(); 
            j = rand7(); 
        }
        
        return (i * j - 1) % 10 + 1; 
        // return 0; 
    }
    
};