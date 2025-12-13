class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int maxi=0;
        for(int num:nums){
            //start only if num is the beginning of a sequence
            if(!s.count(num-1)){
                int streak=1;
                while(s.count(num+1)){
                    s.erase(num);
                    num++;
                    streak++;
                }
                maxi=max(streak,maxi);
            }
        }
        return maxi;
    }
};