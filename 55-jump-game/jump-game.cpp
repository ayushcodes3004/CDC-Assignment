class Solution {
    bool rec(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i>=n-1)  return 1;
        // if(i>=n) return 0;
        if(dp[i]!=-1)    return dp[i];
        int maxJumps=nums[i];
        bool ans=false;
        for(int j=1;j<=maxJumps;j++){
            if(ans==true)   break;
            ans=ans||rec(i+j,nums,n,dp);
        }
        return dp[i]=ans;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,0);
        // return rec(0,nums,n,dp);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int maxJumps=nums[i];
            for(int j=1;j<=maxJumps;j++){
                if(dp[i+j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};