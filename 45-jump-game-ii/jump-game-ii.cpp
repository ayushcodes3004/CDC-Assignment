class Solution {
private:
    int rec(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i >= n-1) return 0;      

        if (dp[i] != -1) return dp[i];

        int maxJumps = nums[i];
        int ans=n-1;
        for (int j = 1; j <= maxJumps; j++) {
            ans = min(ans,1+rec(i + j, nums, n, dp));             
        }

        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // return rec(0, nums, n, dp);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int maxJumps = nums[i];
            int mini=1e9;
            for(int j=1;j<=maxJumps && i+j<n;j++){
                mini=min(mini,dp[i+j]);
            }
            dp[i]=1+mini;
        }
        return dp[0];
    }
};