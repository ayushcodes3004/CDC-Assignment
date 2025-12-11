#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int i=0;
        int j=0;
        int k=n-1;
        while(j<=k){
            if(a[j]==0){
                swap(a[i],a[j]);
                i++,j++;
            }else if(a[j]==1){
                j++;
            }else{
                swap(a[j],a[k]);
                k--;
            }
        }
    }
};