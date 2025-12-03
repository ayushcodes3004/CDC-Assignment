class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num: nums)  freq[num]++;
        vector<int>arr;
        for(auto el: freq){
            if(el.second==2)    arr.push_back(el.first);
        }
        return arr;
    }
};