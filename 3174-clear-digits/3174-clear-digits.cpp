class Solution {
public:
    string clearDigits(string s) {
        
        stack<char> st;
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' and s[i] <= 'z') {
                st.push(s[i]);
            }
            else if(s[i] >= '0' and s[i] <= '9') {
                if(st.top() >= 'a' and st.top() <= 'z') {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};