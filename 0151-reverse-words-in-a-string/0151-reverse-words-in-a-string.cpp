class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "";
        bool flag = false;
        vector<string> v;

        for(int i=0; i<s.size(); i++) {
            if(s[i] != ' ') {
                flag = true;
                ans = ans + s[i];
            }
            else {
                if(flag)
                v.push_back(ans);
                
                flag = false;
                ans = "";
            }
        }
        if(ans != "")
        v.push_back(ans);

        string temp = "";
        for(int i=v.size()-1; i>=0; i--) {
            temp = temp + v[i];
            temp = temp + " ";
        }
        temp.pop_back();
        

        return temp;
    }
};