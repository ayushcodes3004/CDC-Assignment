class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp; //sum->first idx
        int sum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0)  maxi=i+1;
            int remove=sum;
            if(mp.find(remove)!=mp.end()){
                maxi=max(maxi,i-mp[remove]);
            }else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
};