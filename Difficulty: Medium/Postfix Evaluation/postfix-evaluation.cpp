class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string s: arr){
            if(s=="+"||s=="-"||s=="*"||s=="/"|| s == "^"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(s=="+")  st.push(b+a);
                else if(s=="-") st.push(b-a);
                else if(s=="*") st.push(b*a);
                else if(s=="^") st.push(pow(b, a));
                else{
                    if (a == 0) { // avoid division by zero; adjust behaviour if needed
                        st.push(0);
                    } else {
                        long long q = b / a;     // truncated toward zero
                        long long r = b % a;     // remainder (sign of b)
                        if (r != 0 && ((b < 0) ^ (a < 0))) q--; // floor for negatives
                        st.push(q);
                    }
                }
            }else   st.push(stoi(s));
        }
        return st.top();
    }
};