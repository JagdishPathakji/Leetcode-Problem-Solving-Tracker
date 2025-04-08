class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for(int i=0; i<s.size(); i++) {

            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i]) and i < s.size()) {
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                i--;
                st.push(to_string(num));
            }
            else {

                if(s[i] == '[') {
                    st.push(string(1,s[i]));
                }
                else if(s[i] == ']') {
                    
                    string ans = "";
                    while(!st.empty() and st.top() != "[") {
                        ans = st.top() + ans;
                        st.pop();
                    }
                    st.pop();
                    string realstr = "";
                    for(int i=0; i<stoi(st.top()); i++) {
                        realstr += ans;
                    }
                    st.pop();
                    st.push(realstr);
                }
                else {
                    st.push(string(1,s[i]));
                }
            }
        }

        string finalans = "";
        while(!st.empty()) {
            finalans = st.top() + finalans;
            st.pop();
        }

        return finalans;
    }
};