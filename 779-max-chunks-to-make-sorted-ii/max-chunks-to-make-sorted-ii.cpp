class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>s=arr;
        sort(s.begin(),s.end());
        int cnt=0;
        long long sum1=0,sum2=0;
        for(int i=0;i<arr.size();i++){
            sum1+=s[i];
            sum2+=arr[i];
            if(sum1==sum2)  cnt++;
        }
        return cnt;
    }
};