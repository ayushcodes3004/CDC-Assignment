class Solution {
    bool rec(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i>=n-1)  return 1;
        // if(i>=n) return 0;
        if(dp[i]!=-1)    return dp[i];
        int maxJumps=nums[i];
        bool ans=false;
        for(int j=1;j<=maxJumps;j++){
            ans=ans||rec(i+j,nums,n,dp);
        }
        return dp[i]=ans;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return rec(0,nums,n,dp);
    }
};