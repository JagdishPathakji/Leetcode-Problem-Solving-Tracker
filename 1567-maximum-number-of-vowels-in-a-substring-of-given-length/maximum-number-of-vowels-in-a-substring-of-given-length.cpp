class Solution {
public:
    int maxVowels(string s, int k) {
        
        
        int i = 0;
        int j = 0;

        int count = 0;
        int maxcount = 0;
        while(j < s.size()) {

            if(j-i+1 > k) {
                if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')    
                count--;
                i++;
            }

            if(s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u')
            count++;

            if(j-i+1 <= k)
            maxcount = maxcount > count ? maxcount : count;

            j++;
        }

        return maxcount;
    }
};