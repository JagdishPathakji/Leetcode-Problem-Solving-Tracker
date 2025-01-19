class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;
        int n = s.size();

        for(int i=0; i<s.size(); i++) {

            if(!st.empty() and s[i] == 'B' and st.top() == 'A') {
                st.pop();
            }
            else if(!st.empty() and s[i] == 'D' and st.top() == 'C') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        return st.size();
    }
};