class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int idx = -1;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1')
            {
                idx = i;
                break;
            }
        }

        if(idx == -1)
        return true;

        while(idx < s.size() && s[idx] == '1') {
            idx++;
        }

        while(idx < s.size() && s[idx] == '0') {
            idx++;
        }
        
        if(idx != s.size())
        return false;

        return true;
    }
};