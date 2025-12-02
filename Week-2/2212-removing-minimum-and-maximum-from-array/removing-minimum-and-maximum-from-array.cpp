class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1)  return 1;
        int maxi=INT_MIN;
        int maxIdx=0;
        int mini=INT_MAX;
        int minIdx=0;
        // for(int num: nums){
        //     maxi=max(maxi,el);
        //     mini=min(mini,el);
        // }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxIdx=i;
            }    
            if(nums[i]<mini){
                mini=nums[i];
                minIdx=i;
            }
        }
        int ans=0;
        int op1=max(maxIdx,minIdx)+1;
        int op2=nums.size()-min(maxIdx,minIdx);
        int op3=min(maxIdx,minIdx)+1+(nums.size()-max(maxIdx,minIdx));
        ans=min({op1,op2,op3});
        return ans;
    }
};