// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        array<int, 3> arr{0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            swap(arr[0], arr[2]);
            swap(arr[0], arr[1]);
            arr[2] += arr[0] + arr[1];
        }
        return arr[min(n, 2)];
    }
};