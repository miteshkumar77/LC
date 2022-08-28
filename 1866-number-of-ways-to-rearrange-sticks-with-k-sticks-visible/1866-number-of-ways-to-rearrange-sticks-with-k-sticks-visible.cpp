class Solution {
public:
    using ll = long long;
    
    /*
        A, B, M
        
        x % M
        x = M * d + r, 0 <= r < M, floor(M/x) = d
        x % M = r
        
        
        (A + B) % M
        
        (A + B) = M * d + r
        (A - ra) + (B - rb) = M * da + M * db
        A + B = (M * da + ra) + (M * db + + rb)
        
        (A + B) % M = (A % M + B % M) % M
    */
    
    ll M = 1e9 + 7;
    ll tbl(ll i, ll j, unordered_map<int, unordered_map<int,int>>& mp) {
        if (i == 0) { // 1 stick placed
            if (j == 1) { // 1 visible stick
                return 1;
            } else { // =/= 1 visible stick
                return 0;
            }
        }
        if (j > (i + 1)) { // visible sticks > number of sticks (impossible)
            return 0;
        }
        
        if (j == 0) return 0; // 0 visible sticks (impossible)
        
        
        if (!mp.count(i) || !mp[i].count(j))
            mp[i][j] = (tbl(i - 1, j - 1, mp) % M + (i * (tbl(i - 1, j, mp) % M)) % M) % M;
        return mp[i][j];
        
    }
    
    /*
    fib(n) = fib(n-1) + fib(n-2)
    
    fib(4) = fib(3) + fib(2) = fib(2) + fib(1) + fib(2)
    
    */
    
    
    int rearrangeSticks(int n, int k) {
        unordered_map<int, unordered_map<int, int>> mp;
        return tbl(n-1, k, mp);
    }
};



/*
    [ 
      -
      n    i = 0
      -
      n-1  i = 1
      -
      n-2 ] 3 sticks placed down in decreasing order and k visibile sticks
      ^ ^
      | |
      
    n-3
    
    4 sticks placed down and k+1 visible sticks in 1 way
    4 sticks placed down and k visible sticks in 3 ways
    
    tbl[n][k] = answer to the problem
    tbl[i][j] = the number of ways to arrange [i] sticks with [j] visible
    tbl[i][j] = tbl[i-1][j-1] + (i) * tbl[i-1][j]
    
    if (i == 0) {
        
    }
    
*/