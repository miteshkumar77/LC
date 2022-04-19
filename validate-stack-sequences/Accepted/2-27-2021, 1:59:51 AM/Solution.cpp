// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sim;
        int n = popped.size();
        int j = 0;
        for (const int& i : pushed) {
            sim.push(i);
            while(!sim.empty() && popped[j] == sim.top()) {
                ++j;
                sim.pop();
            }
        }
        return j == n;
    }
};