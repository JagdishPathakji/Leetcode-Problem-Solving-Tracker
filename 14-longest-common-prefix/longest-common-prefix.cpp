class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans;
        int index = 0;

        int minLen = INT_MAX;
        for(int i=0; i<strs.size(); i++) {
            if(minLen > strs[i].size())
            minLen = strs[i].size();
        }

        for(int i=0; i<minLen; i++) {
            
            char c = strs[0][index];
            bool flag = false;
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][index] != c) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            index++;
        }

        return strs[0].substr(0,index);
    }
};