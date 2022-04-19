// https://leetcode.com/problems/word-break


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict,int n ,int m,int idx,unordered_map<string,bool>& M,int* memo){
        //Base Case
        if(idx==n){
            return true;
        }
        if(memo[idx]!=-1){
            return memo[idx];
        }
        string str="";
        //First I have to check word in my dictionary
        bool ans=false;
        for(int i=idx;i<n;i++){
            str+=s[i];
            //If we found some word in map
            //Then we have 2 options
            //Option 1:- Use that word and move to next index
            if(M[str]){
                ans=ans||wordBreak(s,wordDict,n,m,i+1,M,memo);
            }
            //Option 2:- Find some other word
        }
        memo[idx]=ans;
        return memo[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),m=wordDict.size();
        //I will make an unordered map and put all words in it
        //Now I dont even need to sort my wordDict
        unordered_map<string,bool> M;
        for(int i=0;i<m;i++){
            M[wordDict[i]]=true;
        }
        int *memo=new int[n+1];
        for(int i=0;i<=n;i++){
            memo[i]=-1;
        }
        return wordBreak(s,wordDict,n,m,0,M,memo);
    }
};
