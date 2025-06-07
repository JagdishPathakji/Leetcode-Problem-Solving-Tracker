class Solution {
public:
    int numberOfSubstrings(string s) {
        
        vector<int> lastoccurance(3,-1);
        int count = 0;

        for(int i=0; i<s.size(); i++) {
            lastoccurance[s[i]-'a'] = i;
            if(lastoccurance[0] != -1 && lastoccurance[1] != -1 && lastoccurance[2] != -1) {
                if(lastoccurance[0] < lastoccurance[1] && lastoccurance[0] < lastoccurance[2])
                count += 1 + lastoccurance[0];
                if(lastoccurance[1] < lastoccurance[0] && lastoccurance[1] < lastoccurance[2])
                count += 1 + lastoccurance[1];
                if(lastoccurance[2] < lastoccurance[0] && lastoccurance[2] < lastoccurance[1])
                count += 1 + lastoccurance[2];
            }
        }
        
        return count;
    }
};