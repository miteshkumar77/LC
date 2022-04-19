// https://leetcode.com/problems/n-queens

class Solution {
public:
    bool isvalid(vector<string> &curr,int row,int col,int n)
    {
         for(int i=row-1;i>=0;i--)
         {
             if(curr[i][col]=='Q')
                 return false;
         }
         //diagonal right
        int i=row-1,j=col+1;
        while(i>=0 && j<n){
            if(curr[i][j]=='Q')
                return false;
            i-=1;j+=1;
        }
        //diagonal left
        i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(curr[i][j]=='Q')
                return false;
            i-=1;j-=1;
        }
        //cell is valid to place the queen 
        return true;
        
    }
    bool placequeen(vector<vector<string>> &ans,vector<string> &curr,int i,int n)
    {
        if(i==n)//if successfully traversed all rows
        {
            ans.push_back(curr);
            return false;
        }
        //placing queens for ith row and jth column
        for(int j=0;j<n;j++)
        {
            if(isvalid(curr,i,j,n))
            {
                curr[i][j]='Q';
                if(!placequeen(ans,curr,i+1,n))
                    curr[i][j]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> >ans;
        string temp="";
        for(int i=0;i<n;i++)
            temp+='.';
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(temp);
        }
        bool val=placequeen(ans,v,0,n);
        return ans;
    }
};