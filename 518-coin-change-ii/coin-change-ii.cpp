class Solution {
private:
    int rec(int i,int amt,vector<int>& coins, int n,vector<vector<int>>&dp){
        if(amt==0)  return 1;
        if(i>=n||amt<0)  return 0;
        if(dp[i][amt]!=-1)  return dp[i][amt];

        int take=rec(i,amt-coins[i],coins,n,dp);
        int leave=rec(i+1,amt,coins,n,dp);

        return dp[i][amt]=take+leave;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        const int INF = 1e9;

        // dp[i][j] = min coins to make amount j using coins[i..n-1]
        vector<vector<unsigned  long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        for (int i = 0; i <= n; ++i) dp[i][0] = 1;

        // fill bottom-up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= amount; ++j) {
                unsigned long long leave = dp[i + 1][j];
                unsigned long long take = 0;
                if (j - coins[i] >= 0) take =dp[i][j - coins[i]]; 
                dp[i][j] =leave+take;
            }
        }

        return dp[0][amount];
    }
};