class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> v(27,0);

        for(int i=0; i<magazine.size(); i++) {
            v[magazine[i]-'a']++;
        }   

        for(int i=0; i<ransomNote.size(); i++) {
            v[ransomNote[i]-'a']--;
        }

        for(int i=0; i<27; i++) {
            if(v[i] < 0) {
                return false;
            }
        }

        return true;
    }
};