class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>ans;
        for(int i=0;i<start.size();i++){
            ans.push_back({finish[i],start[i]});
        }
        sort(ans.begin(),ans.end());
        int end=ans[0].first;
        int cnt=1;
        for(int i=1;i<ans.size();i++){
            if(end<ans[i].second){
                cnt++;
                end=ans[i].first;
            }
        }
        return cnt;
    }
};