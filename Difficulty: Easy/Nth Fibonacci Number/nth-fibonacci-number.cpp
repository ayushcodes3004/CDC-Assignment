class Solution {
  private:
    int rec(int n){
        if(n==0 || n==1)    return n;
        return rec(n-1)+rec(n-2);
    }
  public:
    int nthFibonacci(int n) {
        // code here
        return rec(n);
    }
};