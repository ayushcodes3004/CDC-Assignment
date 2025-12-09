class Solution {
private:
    int rec(int i,int j,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i>=m || j>=n || j<0 ||i>=m)    return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];
        // If we are at the last row, just return the cell value
        if (i == m - 1) return matrix[i][j];
        int ans=1e9;
        int op1=matrix[i][j]+rec(i+1,j-1,m,n,matrix,dp);
        ans=min(ans,op1);
        int op2=matrix[i][j]+rec(i+1,j,m,n,matrix,dp);
        ans=min(ans,op2);
        int op3=matrix[i][j]+rec(i+1,j+1,m,n,matrix,dp);
        ans=min(ans,op3);

        return dp[i][j]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        // int mini=1e9;
        // for(int j=0;j<n;j++){
        //     int ans=rec(0,j,m,n,matrix,dp);
        //     mini=min(ans,mini);
        // }
        // return mini;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==m-1)  dp[i][j]=matrix[i][j];
                else{
                    int ans=INT_MAX;
                    ans=matrix[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                    if(j-1>=0){
                        ans=min(ans,matrix[i][j]+dp[i+1][j-1]);
                    }
                    dp[i][j]=ans;
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