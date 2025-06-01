class Solution {
public:
    int maxVowels(string s, int k) {
        
        multiset<char> ms;
        
        int i = 0;
        int j = 0;

        int maxcount = 0;
        while(j < s.size()) {

            if(j-i+1 > k) {
                if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')    
                ms.erase(ms.find(s[i]));
                i++;
            }

            if(s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u')
            ms.insert(s[j]);
            
            if(j-i+1 <= k)
            maxcount = maxcount > ms.size() ? maxcount : ms.size();

            j++;
        }

        return maxcount;
    }
};