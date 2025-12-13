class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int num: nums){
            mp[num]++;
        }
        for(int i=0;i<=n;i++){
            if(mp.find(i)==mp.end())    return i;
        }
        return -1;
    }
};