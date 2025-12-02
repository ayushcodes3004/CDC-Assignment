class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // vector<int>temp(nums.size());
        // temp=nums;
        // for(int i=0;i<nums.size();i++){
        //     nums[(i+k)%nums.size()]=temp[i];
        // }
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
    }
};