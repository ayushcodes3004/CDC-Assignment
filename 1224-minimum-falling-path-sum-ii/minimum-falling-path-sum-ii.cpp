class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==m-1)  dp[i][j]=grid[i][j];
                else{
                    int ans = INT_MAX;
                    // choose any column k in the next row except j
                    for (int k = 0; k < n; k++) {
                        if (k == j) continue;
                        ans = min(ans, dp[i + 1][k]);
                    }

                    dp[i][j] = grid[i][j] + ans;
                }
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int ans=dp[0][j];
            mini=min(ans,mini);
        }
        return mini;
    }
};