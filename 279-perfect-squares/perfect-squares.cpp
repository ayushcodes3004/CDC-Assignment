class Solution {
private:
    int rec(int n,vector<int>& dp){
        if(n==0)    return 0;
        if(dp[n]!=INT_MAX)  return dp[n];
        int mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ans=1+rec(n-i*i,dp);
            mini=min(mini,ans);
        }
        return dp[n]=mini;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        // return rec(n,dp);
        for(int i=1;i<=n;i++){
            for (int s = 1; s * s <= i; s++) {
                dp[i] = min(dp[i], 1 + dp[i - s * s]);
            }
        }

        return dp[n];

    }
};