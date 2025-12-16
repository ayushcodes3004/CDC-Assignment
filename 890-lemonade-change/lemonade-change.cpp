class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int cnt5=0;
        int cnt10=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                cnt5+=1;
            }else if(bills[i]==10){
                if(cnt5<1)  return false;
                cnt5--;
                cnt10++;
            }else{
                if((cnt5>=3)||(cnt10>=1 && cnt5>=1)){
                    if(cnt10>=1 && cnt5>=1){
                        cnt5--;
                        cnt10--;
                    }else if(cnt5>=3){
                        cnt5=cnt5-3;
                    }

                }else{
                    return false;
                }
            }
        }
        return true;
    }
};