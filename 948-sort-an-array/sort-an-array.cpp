class Solution {
private:
    void merge(vector<int>& arr, int s, int mid,int e){
        vector<int>temp;
        int i=s;
        int j=mid+1;

        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=e){
            temp.push_back(arr[j]);
            j++;
        }
        for (int k = s; k <= e; k++) 
            arr[k] = temp[k - s];

    }
    void mergeSort(vector<int>& arr, int s, int e){
        if(s>=e)    return;
        int mid=s+(e-s)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     bool swapped=false;
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //             swapped=true;
        //         }
        //     }
        //     if(!swapped)    break;
        // }
        // return nums;
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};