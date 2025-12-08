class Solution {
private:
    int rec(int i,int target,vector<int>& nums, int n,int offset,vector<vector<int>>& dp){
        if(i>n || target+offset<0 || target+offset>2*offset)    return 0;
        if(i==n)    return (target==0);

        if(dp[i][target+offset]!=-1)    return dp[i][target+offset];

        int pos=rec(i+1,target-nums[i],nums,n,offset,dp);
        int neg=rec(i+1,target+nums[i],nums,n,offset,dp);
        return dp[i][target+offset]=(pos+neg);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int el: nums)   sum+=el;
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return rec(0,target,nums,n,sum,dp);
    }
};