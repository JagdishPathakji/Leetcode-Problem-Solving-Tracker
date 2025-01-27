class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> v(27,0);

        for(int i=0; i<magazine.size(); i++) {
            v[magazine[i]-'a']++;
        }   

        vector<int> m(27,0);
    
        for(int i=0; i<ransomNote.size(); i++) {
            m[ransomNote[i]-'a']++;
        }

        for(int i=0; i<27; i++) {
            if(m[i] > v[i]) {
                return false;
            }
        }

        return true;
    }
};