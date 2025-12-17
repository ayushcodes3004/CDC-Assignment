class Solution {
private:
    void rec(int i,vector<int>& nums,vector<int>sub,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }  
        rec(i+1,nums,sub,ans);
        sub.push_back(nums[i]);
        rec(i+1,nums,sub,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        rec(0,nums,sub,ans);
        return ans;
    }
};