class Solution {
  public:
    int reve(int n){
        int rev=0;
        while(n){
            int dig=n%10;
            rev=rev*10+dig;
            n=n/10;
        }
        return rev;
    }
    int pow(int a, int b){
        if(b==0)    return 1;
        return a*pow(a,b-1);
    }
    int reverseExponentiation(int n) {
        // code here
        int exp=reve(n);
        return pow(n,exp);
    }
};