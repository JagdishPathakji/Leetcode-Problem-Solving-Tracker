class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        string temp = "";

        for(int i=0; i<s.size(); i++) {
            if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) {
                temp += s[i];
            }
        }

        reverse(temp.begin(),temp.end());

        int k = 0;
        for(int i=0; i<s.size(); i++) {
            if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')) {
                s[i] = temp[k];
                k++;
            }
        }

        return s;
    }
};