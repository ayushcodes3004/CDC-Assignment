class Solution {
  private:
    int cnt=0;
    int rec(int n, int src, int aux, int dest){
        if(n==0)    return 0;
        rec(n-1,src,dest,aux);
        cnt++;
        rec(n-1,aux,src,dest);
        return cnt;
    }
    
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        // return 2^n-1;
        return rec(n,from,aux,to);
    }
};