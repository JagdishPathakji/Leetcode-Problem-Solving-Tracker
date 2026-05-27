class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char,int> mp;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                mp[word[i]] = i;
            }
        }

        int count = 0;

        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                if(mp.find(word[i]+32) != mp.end()) {
                    if(mp[word[i]+32] < i) {
                        count++;
                        mp[word[i]+32] = INT_MAX;
                    }
                    else {
                        mp[word[i]+32] = INT_MAX;
                    }
                }
            }
        }

        return count;        
    }
};