class Solution {
    int rec(int i, vector<int>& cost, vector<int>& dp){
        if(i>=cost.size())    return 0;
        if(dp[i]!=-1)   return dp[i];
        return dp[i]=cost[i]+min(rec(i+1,cost,dp),rec(i+2,cost,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(rec(0,cost,dp),rec(1,cost,dp));
    }
};