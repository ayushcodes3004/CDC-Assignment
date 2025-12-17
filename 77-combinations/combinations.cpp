class Solution {
private:
    void rec(int s,int e,int k,vector<int>& path, vector<vector<int>>& ans){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i=s;i<=e;i++){
            path.push_back(i);
            rec(i+1,e,k,path,ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;
        rec(1,n,k,path,ans);
        return ans;
    }
};