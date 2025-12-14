class Solution {
private:
    // int rec(int i,int j,string s, vector<vector<int>>& dp) {
    //     if(i>=j)    return 1;
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j]=rec(i+1,j-1,s,dp);
    //     }
    //     return dp[i][j]=0;
    // }
    void expand(int l,int r,string s,int& maxi,int& start){
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>maxi){
                maxi=r-l+1;
                start=l;
            }
            l--;
            r++;
        }
    }
public:
    string longestPalindrome(string s) {
        // int n=s.size();
        // int maxi=0;
        // int start=-1;
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(rec(i,j,s,dp)==1){
        //             if(j-i+1>maxi){
        //                 maxi=j-i+1;
        //                 start=i;
        //             }
        //         }
        //     }
        // }
        int n=s.size();
        int maxi=0;
        int start=-1;
        for(int i=0;i<n;i++){
            expand(i,i,s,maxi,start);      //odd
            expand(i,i+1,s,maxi,start);    //even
        }
        return s.substr(start,maxi);
    }
};