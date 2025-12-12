class Solution {
private:
    int rec(int i,int j,vector<int>& coins,int n,vector<vector<int>>& dp){
        if(j == 0) return 0;  
        if(j<0 || i>=n) return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];
        int op1=1+rec(i,j-coins[i],coins,n,dp);
        int op2=rec(i+1,j,coins,n,dp);
        return dp[i][j]=min({op1,op2});
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=rec(0,amount,coins,n,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};