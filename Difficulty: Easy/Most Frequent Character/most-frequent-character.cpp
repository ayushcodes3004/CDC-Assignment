class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int freq[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int maxi=0;
        for(int i=0;i<26;i++){
            if(freq[i]>maxi){
                maxi=freq[i];
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]==maxi){
                return i+'a';
            }
        }
        return 'a';
    }
};