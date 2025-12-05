class Solution {
  public:
    void rec(int n){
        if(n==0)    return;
        rec(n-1);
        cout<<n<<" ";
    }
    void printTillN(int n) {
        // code here
        rec(n);
    }
};