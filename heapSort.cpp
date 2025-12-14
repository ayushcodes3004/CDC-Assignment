#include <iostream>
#include<vector>
using namespace std;
//max heap
void heapify(int i, int n,vector<int>& arr){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]>arr[largest])    largest=left;
    if(right<n && arr[right]>arr[largest])    largest=right;
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(largest,n,arr);
    }
    
}
void heapSort(vector<int>& arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(i,n,arr);
    }
    
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]); //move max to end
        heapify(0,i,arr); //heap size becomes i
    }
}
int main() {
    vector<int>arr={4, 10, 3, 5, 1};
    heapSort(arr);
    for(int el: arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}
