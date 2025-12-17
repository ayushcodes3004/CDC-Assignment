class Solution {
private:
    bool isSafe(long long mid,vector<int>& time, int totalTrips){
        long long cnt=0;
        for(int i=0;i<time.size();i++){
            cnt+=mid/(long long)time[i];
        }
        if(cnt<totalTrips)  return false;
        return true;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int  n=time.size();
        int maxi=-1;
        for(int el:time){
            maxi=max(maxi,el);
        }
        long long l=1;
        long long r=(long long)maxi*(long long)totalTrips;
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(isSafe(mid,time,totalTrips)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};