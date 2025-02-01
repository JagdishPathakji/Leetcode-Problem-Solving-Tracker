class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = needle.size();
        string check = "";

        for(int i=0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                int j = i;
                while(j < haystack.size() and j<(i+n)) {
                    check = check + haystack[j];
                    j++;
                }
                if(check == needle) {
                    return i;
                }
                else {
                    check = "";
                }
            }
        }

        return -1;
    }
};