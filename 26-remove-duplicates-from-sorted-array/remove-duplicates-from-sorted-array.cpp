class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(int num: nums){
            s.insert(num);
        }
        int i=0;
        for(int el: s){
            nums[i++]=el;
        }
        return s.size();
    }
};