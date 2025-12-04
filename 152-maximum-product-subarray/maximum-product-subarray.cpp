class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int currMaxi=nums[0];
        int currMini=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)   swap(currMaxi,currMini);
            currMaxi=max(nums[i],currMaxi*nums[i]);
            currMini=min(nums[i],currMini*nums[i]);
            maxi=max(maxi,currMaxi);
        }
        return maxi;

    }
};