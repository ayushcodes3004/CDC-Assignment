class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bulls=0,cows=0;
        vector<int>freq(10,0);
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                freq[secret[i]-'0']++;
            }
        }

        for(int i=0;i<n;i++){
            int d=guess[i]-'0';
            if(secret[i]!=guess[i]){
                if(freq[d]>0){
                    cows++;
                    freq[d]--;
                }   
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};