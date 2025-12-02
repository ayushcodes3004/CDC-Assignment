void reverseArray(vector<int> &arr , int m) {
    // Write your code here
    int l=m+1;
    int r=arr.size()-1;
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }   	
    // reverse(arr.begin()+m+1,arr.end());
}
