class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int ans=0;
        int temp=n;
        while(temp){
            int digit=temp%10;
            if(digit==0)    ans+=0;
            else if(n%digit==0) ans+=1;
            temp=temp/10;
        }
        return ans;
    }
};