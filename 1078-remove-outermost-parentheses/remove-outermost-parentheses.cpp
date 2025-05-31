class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        stack<char> st;

        int open = 0;
        int close = 0;

        for(int i=0; i<s.size(); i++) {
            
            st.push(s[i]);
            if(s[i] == '(')
            open++;
            if(s[i] == ')')
            close++;
            
            if(open == close) {
                string temp = "";
                st.pop();
                while(!st.empty()) {
                    temp += st.top();
                    st.pop();
                } 
                temp.pop_back();
                reverse(temp.begin(),temp.end());
                ans += temp;
            }
        }

        return ans;
    }
};