class Solution {
private:
    long long solve(int k,vector<int>& piles){
        long long sum=0;
        for(int el:piles){
           sum += (el + (long long)k - 1) / k;
        }
        if(sum>1e9) return sum;   
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=piles[0];
        for(int el: piles){
            maxi=max(maxi,el);
        }
        int l=1;
        int r=maxi;
        int ans=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(mid,piles)<=h){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};