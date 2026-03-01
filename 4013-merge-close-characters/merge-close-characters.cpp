class Solution {
public:
    string mergeCharacters(string s, int k) {
        
        unordered_map<char,int> mp;
        int cnt = 0;

        string ans = "";
        for(int i=0; i<s.size(); i++) {
            
            if(mp.find(s[i]) != mp.end()) {
                if(i-cnt-mp[s[i]] <= k) {
                    cnt++;
                }
                else {
                    mp[s[i]] = i-cnt;
                    ans.push_back(s[i]);
                }
            }
            else {
                mp[s[i]] = i-cnt;
                ans.push_back(s[i]);
            }

        }

        return ans;
    }
};