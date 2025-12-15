class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int num: nums)  freq[num]++;
        for(auto [el,f]: freq){
            if(f>=2)    return el;
        }
        return -1;
    }
};