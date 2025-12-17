class Solution {
private:
    bool isValid(string s){
        stack<char>st;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
            }else{
                if (st.empty()) return false;
                st.pop();
            }
        }
        return (st.empty());
    }
    void rec(int i,string& s,vector<string>& ans, int size){
        if(i==size){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        rec(i+1,s,ans,size);
        s.pop_back();
        s.push_back(')');
        rec(i+1,s,ans,size);
        s.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        rec(0,s,ans,2*n);
        return ans;
    }
};