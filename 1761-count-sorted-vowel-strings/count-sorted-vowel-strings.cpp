class Solution {
public:

    int find(int selected,int index, vector<char> &vowels, int n) {

        if(index >= vowels.size())
        return 0;

        if(selected == n)
        return 1;

        return find(selected+1,index,vowels,n) + find(selected,index+1,vowels,n);
    }

    int countVowelStrings(int n) {
        
        vector<char> vowels = {'a','e','i','o','u'};
        return find(0,0,vowels,n);
    }
};