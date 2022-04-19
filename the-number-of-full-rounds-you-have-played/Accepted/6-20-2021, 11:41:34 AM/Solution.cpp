// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played

#define P(name) cout << #name << "(" << name << ") "
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sH = stoi(startTime.substr(0,2));
        int sM = stoi(startTime.substr(3,2));
        int fH = stoi(finishTime.substr(0,2));
        int fM = stoi(finishTime.substr(3,2));
        int ans = 0;
        int counter = 0;
        int st = sH * 60 + sM;
        int ft = fH * 60 + fM;
        //P(st);P(ft); cout << endl;
        for (int t = sH * 60 + sM; t != fH * 60 + fM; t = (t + 1) % 1440) {
            if (t % 60 == 0 || t % 60 == 15 || t % 60 == 30 || t % 60 == 45) {
                counter = 0;
            }
            if (++counter == 15) {
                ++ans;
            }
        }
        
        return ans;
    }
};