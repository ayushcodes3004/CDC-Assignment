class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int num: nums)  freq[num]++;
        for(auto& [el, cnt]: freq)   if(cnt>(n/2))  return el;
        return -1;
    }
};