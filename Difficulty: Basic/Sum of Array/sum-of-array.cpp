// User function template for C++
class Solution {
  public:
    int rec(int i,vector<int>& arr,int n,int ans){
        if(i==n)    return ans;
        
        return arr[i]+rec(i+1,arr,n,ans);
        
    }
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        return rec(0,arr,n,ans);
    }
};