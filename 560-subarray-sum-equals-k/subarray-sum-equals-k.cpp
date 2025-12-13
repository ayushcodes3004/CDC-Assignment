class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[0]=1; //very important
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remove=sum-k;
            if(mp.find(remove)!=mp.end()){
                cnt+=mp[remove];
            }
            mp[sum]++;
        }
        return cnt;
    }
};