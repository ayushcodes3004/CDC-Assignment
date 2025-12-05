class Solution {
  public:
  int fact(int n){
      if(n==0 || n==1)  return 1;
      return n*fact(n-1);
  }
    int factorial(int n) {
        // code here
        // int ans=1;
        // while(n){
        //     ans*=n;
        //     n--;
        // }
        // return ans;
        return fact(n);
    }
};