class Solution {
  private:
    void rec(int idx,vector<int>& arr,vector<int>&sub,vector<vector<int>>&ans){
        // if(i==arr.size()){
        //     ans.push_back(sub);
        //     return;
        // }
        // sub.push_back(arr[i]);
        // rec(i+1,arr,sub,ans);
        // sub.pop_back();
        // i=i+1;
        // while(i<arr.size() && arr[i-1]==arr[i]) i++;
        // rec(i,arr,sub,ans);
        ans.push_back(sub);  

        for (int i = idx; i < arr.size(); i++) {

            if (i > idx && arr[i] == arr[i - 1]) continue;

            sub.push_back(arr[i]);
            rec(i + 1, arr, sub, ans);
            sub.pop_back();
        }
    }
  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>sub;
        rec(0,arr,sub,ans);
        return ans;
    }
};