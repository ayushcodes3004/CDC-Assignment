// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        // map<char,int>freq;
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]]++;
        // }
        // string ans="";
        // for(auto [ch, f]:freq){
        //     ans+=ch;
        // }
        // return ans;
        bool seen[255]={false};
        string ans="";
        for(int i=0;i<s.size();i++){
            if(seen[s[i]]==false){
                ans+=s[i];
                seen[s[i]]=true;
            }
        }
        return ans;
    }
};