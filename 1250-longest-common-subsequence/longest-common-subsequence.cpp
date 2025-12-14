class Solution {
private:
    int rec(int i,int j,string text1, string text2,vector<vector<int>>& dp){
        int m=text1.size();
        int n=text2.size();
        if(i>=m || j>=n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+rec(i+1,j+1,text1,text2,dp);
        }else{
            ans=max(rec(i+1,j,text1,text2,dp),rec(i,j+1,text1,text2,dp));
        }
        return dp[i][j]=ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // return rec(0,0,text1,text2,dp);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};