class Solution {
public:
    string processStr(string s) {
        
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' and s[i] <= 'z') {
                ans.push_back(s[i]);
            }
            else if(s[i] == '*') {
                if(ans.size() != 0) 
                ans.pop_back();
            }
            else if(s[i] == '#') {
                string temp = ans;
                ans = ans + temp;
            }
            else if(s[i] == '%') {
                reverse(ans.begin(),ans.end());
            }
        }

        return ans;
    }
};