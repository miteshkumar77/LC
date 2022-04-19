// https://leetcode.com/problems/find-the-most-competitive-subsequence

impl Solution {
    pub fn most_competitive(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut stk = Vec::new(); 
        for (index, val) in nums.iter().enumerate() {
            let remaining = nums.len() - index;
            // println!("stk.len()={} val={} remaining={} index={}", stk.len(), val, remaining, index); 
            while stk.len() != 0 && val < stk.last().unwrap() && (remaining as i32) > (k - (stk.len() as i32)){
                stk.pop();
                // println!("stk.len()={} val={} remaining={} index={}", stk.len(), val, remaining, index); 
            }
            
            if stk.len() < (k as usize) {
                stk.push(*val)
            }
        }
        
        return stk
    }
}