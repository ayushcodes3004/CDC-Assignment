class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; //{valur,idx}
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            //remove top elements that are outside the window
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
            //window formed
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};