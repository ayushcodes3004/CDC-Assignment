class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]==nums[i]){
                    arr[i]++;
                }
            }
        }
        int maxi=INT_MIN;
        for(int el:arr) maxi=max(maxi,el);
        int ans=0;
        for(int el:arr){
            if(el==maxi)    ans+=el;
        }
        return ans;
    }
};