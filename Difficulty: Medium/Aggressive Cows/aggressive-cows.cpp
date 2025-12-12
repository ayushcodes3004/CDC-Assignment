class Solution {
  private:
    bool solve(int mid,vector<int>& arr,int k){
        int n=arr.size();
        int cows=1;
        int lastStallPos=arr[0];
        for(int i=1;i<n;i++){
            if((arr[i]-lastStallPos)>=mid){
                cows++;
                lastStallPos=arr[i];
            }
            if(cows==k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int l=1;
        int r=stalls[n-1]-stalls[0];
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(mid,stalls,k)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};