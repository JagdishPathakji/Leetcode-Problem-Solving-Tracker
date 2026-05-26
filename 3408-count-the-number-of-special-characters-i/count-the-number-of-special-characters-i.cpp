class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> s;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z')
            s.insert(word[i]);
        }

        int ans = 0;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                if(s.find(word[i]+32) != s.end()) {
                    s.erase(word[i]+32);
                    ans++;
                }
            }
        }

        return ans;
    }
};