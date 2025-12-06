// User function template for C++

class Solution {
  private:
    string rec(string& s){
        // unordered_map<char,int>freq;
        // for(char c: s)  freq[c]++;
        // bool repeat=false;
        // for(auto [c,f]: freq){
        //     if(f!=1)    repeat=true;
        // }
        // if(!repeat) return s;
        // string temp="";
        // for(int i=0;i<s.size();i++){
        //     if(freq[s[i]]==1)   temp+=s[i];
        // }
        // return rec(temp);
        string temp="";
        int n=s.size();
        for(int i=0;i<n;i++){
            bool repeated=false;
            for(int j=i+1;j<n && s[i]==s[j] ;j++){
                repeated=true;
                i++;
            }
            if(!repeated)   temp+=s[i];
        }
        if(n==temp.length())    return s;
        return rec(temp);
    }
  public:
    string removeUtil(string &s) {
        // code here
        return rec(s);
    }
};