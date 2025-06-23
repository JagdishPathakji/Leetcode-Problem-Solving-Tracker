class Solution {
public:

    bool isvowel(char s) {
        if(s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u' or s == 'A' or s == 'E' or s == 'I' or s == 'O' or s == 'U')
        return true;
        
        return false;
    }

    string reverseVowels(string s) {
        
        int i = 0;
        int j = s.size()-1;

        while(i < j) {

            if(isvowel(s[i]) and isvowel(s[j])) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isvowel(s[i])) {
                j--;
            }
            else if(isvowel(s[j])) {
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        
        return s;
    }
};