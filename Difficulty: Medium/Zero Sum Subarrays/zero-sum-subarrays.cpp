class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[0]=1; //very important
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int remove=sum-0;
            if(mp.find(remove)!=mp.end()){
                cnt+=mp[remove];
            }
            mp[sum]++;
        }
        return cnt;
    }
};