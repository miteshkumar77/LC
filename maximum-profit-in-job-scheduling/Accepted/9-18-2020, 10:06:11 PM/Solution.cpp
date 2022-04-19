// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
    
    
private:
    struct Job {
        
        Job(int startTime, int endTime, int prof) {
            start = startTime; 
            end = endTime; 
            profit = prof; 
        }
        
        bool operator < (const Job& j) const {
            return this -> end < j.end; 
        }
        
        int start; 
        int end; 
        int profit; 
    };
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size(); 
        vector<Job> jobs; jobs.reserve(n);  
        for (int i = 0; i < profit.size(); ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i])); 
        }
        
        sort(jobs.begin(), jobs.end()); 
        
        vector<int> dp(n); 
        dp[0] = jobs[0].profit;
        
        for (int i = 1; i < n; ++i) {
            int j = i - 1; 
            int prevprof = 0; 
            while(j >= 0 && jobs[j].end > jobs[i].start) {
                --j; 
            }
            if (j >= 0) {
                prevprof = dp[j]; 
            }
            dp[i] = max(dp[i - 1], prevprof + jobs[i].profit);
        }
        
        return dp.back(); 
    }
};