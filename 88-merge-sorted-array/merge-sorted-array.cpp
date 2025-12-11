class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        vector<int>arr3(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(arr1[i]<arr2[j]){
                arr3[k++]=arr1[i++];
            }else{
                arr3[k++]=arr2[j++];
            }
        }

        while(i<m){
            arr3[k++]=arr1[i++];
        }

        while(j<n){
            arr3[k++]=arr2[j++];
        }

        for(int i=0;i<m+n;i++){
            arr1[i]=arr3[i];
        }
    }
};