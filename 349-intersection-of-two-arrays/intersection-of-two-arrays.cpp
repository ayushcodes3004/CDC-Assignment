class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for(int el: nums1)  s1.insert(el);
        for(int el: nums2)  s2.insert(el);
        unordered_map<int,int>mp;
        for(int num: s1)  mp[num]++;
        for(int num: s2)  mp[num]++;
        vector<int>ans;
        for(auto& [el,f]:mp){
            if(f==2)    ans.push_back(el);
        }
        return ans;
    }

};