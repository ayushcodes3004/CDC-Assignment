// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {\
  private:
    void heapify(int i,int n,vector<int>& arr){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[left]>arr[largest])    largest=left;
        if(right<n && arr[right]>arr[largest])  largest=right;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(largest,n,arr);
        }
    }
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(i,n,arr);
        }
        
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(0,i,arr);
        }
    }
};